#!@PREFIX@/bin/perl

# $NetBSD: pkgdepgraph.pl,v 1.1.1.1 2002/11/07 23:18:01 atatat Exp $
# pkgdepgraph: @DISTVER@

# (1) lintpkgsrc -i > ! pkgdepgraph.in			(optional, adds color)
# (1a) audit-packages >> pkgdepgraph.in			(optional, adds color)
# (2) ./pkgdepgraph pkgdepgraph.in > ! pkgdepgraph.out	(can leave off lint)
# (3) dotty pkgdepgraph.out				(to view it)
# (4) dot -Tgif pkgdepgraph.out > ! pkgdepgraph.gif
# (5) file pkgdepgraph.gif				(to determine size)
# (6) dot -Tps pkgdepgraph.out > ! pkgdepgraph.ps
# (7) pstopnm -stdout -xsize 26332 -ysize 652 pkgdepgraph.ps > ! pkgdepgraph.ppm

use strict;

use Getopt::Std;
my($opts, %opt, $usecolor, $locations, $order, $versions) = ('cd:lov');
my($pkg_dbdir);
die("usage: $0 [-d pkg_dbdir] [-clov]\n") if (!getopts($opts, \%opt));
$usecolor = $opt{c};
$pkg_dbdir = $opt{d} || $ENV{'PKG_DBDIR'} || "/var/db/pkg";
$locations = $opt{l};
$order = $opt{o};
$versions = $opt{v};

my(@pkgs, $pkg, $req, %req, @reqs, @rreqs);
my(%where, %leaf, $pkgcnt, $num, %num, @num, %ord, @ord, $suffix);
my(%color, $color1, $color2, $ecolor, %vuln);
my(%need, $label);

##
## load out-of-date or security problem list (if given)
##
if (@ARGV || ! -t) {
    $usecolor = 1;
    while (<>) {
	if (/^Version mismatch: '(\S+)' (\S+) vs (\S+)/) {
	    $color{"$1-$2"} = "red";
	    $need{"$1-$2"} = "$1-$3";
	}
	elsif (/^Unknown package: '(\S+)' version (\S+)/) {
	    $color{"$1-$2"} = "purple";
	}
	elsif (/Package (\S+) has a (\S+) vulnerability/) {
	    $vuln{$1} = $2;
	    $color{$1} = "red";
	    # $1 =~ /(\S+)-([0-9\.]*([a-z]+\d*)?(nb[0-9]*)?)$/i;
	}
    }
}

##
## load pkg list
##
chdir($pkg_dbdir);
opendir(P, ".") || die("opendir");
@pkgs = grep(/-/, readdir(P));
closedir(P);
$pkgcnt = @pkgs;

##
## where are they needed
##
foreach $pkg (@pkgs) {
    $where{$pkg} = $pkg;
    $leaf{$pkg} = 1 unless (defined($leaf{$pkg}));
    open(R, "<$pkg/+BUILD_INFO") ||
	die("$pkg: +BUILD_INFO: $!\n");
    while (<R>) {
	if (/^PKGPATH\s*=\s*(\S+)/) {
	    $where{$pkg} = $1;
	    last;
	}
    }
    close(R);
    next if (!open(R, "<$pkg/+REQUIRED_BY"));
    while ($req = <R>) {
	chomp($req);
	$leaf{$pkg} = 0;
	$req{$req}->{$pkg} = 1;
#	print("$req -> $pkg\n");
    }
}

##
## eliminate redundancies by deleting edges that are redundant
##
foreach $pkg (@pkgs) {
    @reqs = sort(keys %{$req{$pkg}});
    @rreqs = recurse(@reqs);
#    print("$pkg -> (@reqs) -> (@rreqs)\n");
    map(delete($req{$pkg}->{$_}), @rreqs);
}

##
## impose some sort of order on the pkgs by assigning them numbers
## that indicate their height in the graph
##
foreach $pkg (@pkgs) {
    order(1, $pkg);
}

sub order {
    my($n, @pkgs) = @_;
    my($pkg);
    foreach $pkg (@pkgs) {
	$ord{$pkg} = $n if ($ord{$pkg} <= $n);
	order($n + 1, sort(keys %{$req{$pkg}}));
    }
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
    printf("\"%s\" [color=\"%s\",label=\"%s\"];$suffix\n", $pkg , $color1, $label);
    @reqs = sort(keys %{$req{$pkg}});
#    print("// $pkg -> (@reqs)\n");
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
