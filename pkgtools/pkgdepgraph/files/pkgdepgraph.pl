#!@PREFIX@/bin/perl

# $NetBSD: pkgdepgraph.pl,v 1.2 2002/12/26 05:40:48 atatat Exp $
# pkgdepgraph: @DISTVER@

use strict;

use Getopt::Std;
my($opts, %opt, $usecolor, $group, $locations, $order, $versions) = ('cd:glov');
my($pkg_dbdir);
die("usage: $0 [-d pkg_dbdir] [-cglov]\n") if (!getopts($opts, \%opt));
$usecolor = $opt{c};
$pkg_dbdir = $opt{d} || $ENV{'PKG_DBDIR'} || "/var/db/pkg";
$group = $opt{g};
$locations = $opt{l};
$order = $opt{o};
$versions = $opt{v};

my(@pkgs, $pkg, $req, %req, @reqs, @rreqs);
my(%clusters, $closeme);
my(%where, %leaf, $pkgcnt, $num, %num, @num, %ord, @ord, $suffix);
my(%color, $color1, $color2, $ecolor, %vuln);
my(%need, $label);
my($recolor, @graph);

##
## load out-of-date or security problem list (if given)
##
$recolor = 0;
if (@ARGV || ! -t) {
    $usecolor = 1;
    while (<>) {
	if (/^digraph/) {
	    $recolor = 1;
	    @graph = ($_);
	}
	elsif ($recolor == 1) {
	    push(@graph, $_);
	    $recolor = 2 if (/^}/);
	}
	elsif (/^Version mismatch: '(\S+)' (\S+) vs (\S+)/) {
	    $color{"$1-$2"} = "red";
	    $need{"$1-$2"} = "$1-$3";
	}
	elsif (/^Unknown package: '(\S+)' version (\S+)/) {
	    $color{"$1-$2"} = "purple";
	}
	elsif (/Package (\S+) has a (\S+) vulnerability/) {
	    $vuln{$1} = $2;
	    $color{$1} = "red";
	}
    }
}

##
## load pkg list
##
opendir(P, $pkg_dbdir) || die("opendir");
@pkgs = grep(/-/, readdir(P));
closedir(P);
$pkgcnt = @pkgs;

##
## where are they needed
##
foreach $pkg (@pkgs) {
    $where{$pkg} = $pkg;
    $leaf{$pkg} = 1 unless (defined($leaf{$pkg}));
    open(R, "<$pkg_dbdir/$pkg/+BUILD_INFO") ||
	die("$pkg: +BUILD_INFO: $!\n");
    while (<R>) {
	if (/^PKGPATH\s*=\s*(\S+)/) {
	    $where{$pkg} = $1;
	    last;
	}
    }
    close(R);
    next if (!open(R, "<$pkg_dbdir/$pkg/+REQUIRED_BY"));
    while ($req = <R>) {
	chomp($req);
	$leaf{$pkg} = 0;
	$req{$req}->{$pkg} = 1;
    }
}

##
## if we're recoloring an existing graph, recolor it now and finish
##
if ($recolor) {
    my(%over, %nver, @label, $ocolor);
    map({ /(.*)-(.*)/ && ($nver{$1} = $2) } @pkgs);

    foreach (@graph) {
	# we don't recolor edges
	($pkg) = (/\"([^\"]+)\"/);
	$pkg =~ s/(.*)-(.*)/$1/;
	$over{$pkg} = $2;

	if (/, EDGE$/) {
	    if (defined($nver{$pkg})) {
		s/color=\"[^\"]+\"/color=\"green\"/;
	    }
	    else {
		s/color=\"[^\"]+\"/color=\"black\"/;
	    }
	}

	elsif (/label/) {
	    s/color=\"([^\"]+)\"/color="NEWCOLOR"/;
	    $ocolor = $1;
	    s/label=\"([^\"]+)\"/label="NEWLABEL"/;
	    $label = $1;
	    if ($nver{$pkg}) {
		if ($nver{$pkg} ne $over{$pkg} || $ocolor ne "red") {
		    s/NEWCOLOR/green/;
		}
		else {
		    s/NEWCOLOR/$ocolor/;
		}

		@label = split(/\\n/, $label);
		$label = "";

		# "where" tag
		if ($label[0] =~ m:/:) {
		    $label .= "\\n" . shift(@label);
		}

		# installed pkg
		$label[0] =~ s/(.*$pkg)-\S*$/$1-$nver{$pkg}/ if ($nver{$pkg});
		$label .= "\\n" . shift(@label);

		# "needed" pkg
		if ($label[0] =~ /^$pkg-(.*)/) {
		    $label .= "\\n$label[0]" if ($1 ne $nver{$pkg});
		    shift(@label);
		}

		# there shouldn't be anything left, but...
		$label .= "\\n" . join("\\n", @label);

		$label =~ s/\\n//;
	    }
	    else {
		s/NEWCOLOR/black/;
	    }
	    s/NEWLABEL/$label/;
	}
	print;
    }
    exit(0);
}

##
## eliminate redundancies by deleting edges that are redundant
##
foreach $pkg (@pkgs) {
    @reqs = sort(keys %{$req{$pkg}});
    @rreqs = recurse(@reqs);
    map(delete($req{$pkg}->{$_}), @rreqs);
}

##
## Create a hash of clusters of package prefixes, with counts
##
map({ $a=""; map({ $a .= $_; $clusters{$a}++; } /([^-_]*[-_])/g); } @pkgs);

##
## impose some sort of order on the pkgs by assigning them numbers
## that indicate their height in the graph
##
foreach $pkg (@pkgs) {
    order(1, $pkg);
}

##
## assign each pkg a group number, and count the number of pkgs in
## that group.  the higher the number, the earlier we need to assign
## them to a group.
##
$num = 1;
foreach $pkg (sort(byord @pkgs)) {
    my($pkgnum);
    @reqs = sort(keys %{$req{$pkg}});
    @rreqs = recurse(@reqs);
    $pkgnum = number($pkg, @reqs, @rreqs) || $num;
    foreach $req ($pkg, @reqs, @rreqs) {
	$num[$num{$req}]--;
	$num{$req} = $pkgnum;
	$num[$num{$req}]++;
    }
    $num++;
}

##
## show left overs as a graph
##
print("digraph \"packages\" {\n");
foreach $pkg (sort(bynum @pkgs)) {
    $color1 = color($pkg);
    $label = $pkg;
    $label =~ s/(.*)-.*/$1/ if (!$versions);
    $label = "($ord{$pkg}) $label" if ($order);
    $label = "$where{$pkg}\\n$label" if ($locations);
    $label .= "\\n$need{$pkg}" if ($need{$pkg});
    if ($vuln{$pkg}) {
	$label .= "\\n(no update available)" if (!$need{$pkg});
	$label .= "\\n[$vuln{$pkg}]";
    }
    $suffix = "\t// \#$ord{$pkg}, group $num{$pkg}, $num[$num{$pkg}] members, $pkgcnt pkgs";
    $suffix .= ", LEAF" if ($leaf{$pkg});
    $a = "";
    foreach ($pkg =~ /([^-_]*[-_])/g) {
	last if ($clusters{$a .= $_} <= 1 || !$group);
	printf("subgraph \"cluster_%s\" {\n", substr($a, 0, -1));
	$closeme .= "}\n";
    }
    printf("\"%s\" [color=\"%s\",label=\"%s\"];$suffix\n", $pkg , $color1, $label);
    print($closeme);
    $closeme = "";
    @reqs = sort(keys %{$req{$pkg}});
    $suffix =~ s/, LEAF$//;
    $suffix .= ", EDGE";
    foreach $req (@reqs) {
	$color2 = color($req);
	printf("\"%s\" -> \"%s\" [color=\"%s\"];$suffix\n", $req, $pkg, $color2);
    }
}
print("}\n");

##
## find all dependencies below a given node
##
sub recurse {
    my($pkg, @list, %list);
    %list = @list = ();
    foreach $pkg (@_) {
	@list = keys %{$req{$pkg}};
	map($list{$_} = $_, @list, recurse(@list));
    }
    sort(keys %list);
}

##
## lowest number of a graph
##
sub number {
    my($n, $pkg);
    $n = 0;
    foreach $pkg (@_) {
	$n = $num{$pkg} if ($n == 0 || $num{$pkg} < $n);
    }
    $n + 0;
}

##
## pick a color based on the color of the dependencies
##
sub color {
    my($pkg) = @_;
    if (! $usecolor) {
	"black";
    }
    elsif ($color{$pkg}) {
	$color{$pkg};
    }
    else {
	my($req, @reqs, $color);
	@reqs = sort(keys %{$req{$pkg}});
	@reqs = (@reqs, recurse(@reqs));
	$color = "green";
	foreach $req (@reqs) {
	    if ($color{$req} eq "red") {
		return "orange"; 
	    }
	    elsif ($color{$req} eq "purple") {
		$color = "blue";
	    }
	}
	$color;
    }
}

##
## bynum - higher numbers come last
##
sub bynum {
    return $num{$a} <=> $num{$b} ||
	$a cmp $b;
}

##
## byord - higher orders comes first
##
sub byord {
    return $ord{$b} <=> $ord{$a} ||
	$b cmp $a;
}

##
## order - the order of a pkg is one higher than anything below it  
##
sub order {
    my($n, @pkgs) = @_;
    my($pkg);
    foreach $pkg (@pkgs) {
	$ord{$pkg} = $n if ($ord{$pkg} <= $n);
	order($n + 1, sort(keys %{$req{$pkg}}));
    }
}
