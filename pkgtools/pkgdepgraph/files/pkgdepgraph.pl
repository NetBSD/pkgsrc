#!@PREFIX@/bin/perl

# Copyright (c) 2002, 2003 by Andrew Brown <atatat@netbsd.org>
# Absolutely no warranty.

# $NetBSD: pkgdepgraph.pl,v 1.3 2003/03/06 21:13:13 atatat Exp $
# pkgdepgraph: @DISTVER@

use strict;

use Getopt::Std;
my($opts, %opt) = ('CcDd:fgLlO:oP:Rt:vU:');
my($iam, $usecolor, $group, $locations, $order, $versions);
my($limit, $delete, $rebuild, $force, $outofdate, $update, $clean);
my($pkg_dbdir, $pkgsrcdir);

($iam = $0) =~ s:.*/::;
die("usage: $iam [-CcDfgLloRv] [-d pkg_dbdir] [-O package] [-P pkgsrcdir]\n",
    " " x (length($iam) + 8), "[-t target] [-U package] [data ...]\n")
    if (!getopts($opts, \%opt));

$usecolor = 0;
$pkg_dbdir = $opt{d} || $ENV{'PKG_DBDIR'} || "/var/db/pkg";
$pkgsrcdir = $opt{P} || $ENV{'PKGSRCDIR'} || "/usr/pkgsrc";
$group = $opt{g};
$locations = $opt{l};
$order = $opt{o};
$versions = $opt{v};
$delete = $opt{D};
$rebuild = $opt{t} || "install" if (defined($opt{R}));
$force = $opt{f};
$outofdate = $opt{O};
$update = $opt{U};
$limit = $opt{L};
$clean = $opt{c} ? "clean" : "";
$clean = $opt{C} ? "CLEANDEPENDS=YES clean" : $clean;

my(@pkgs, $pkg, $req, %req, @reqs, @rreqs);
my(%clusters, $closeme);
my(%where, $pkgcnt, $num, %num, @num, %ord, @ord, $suffix);
my(%color, $color, %vuln);
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
## create a hash of clusters of package prefixes, with counts.  later,
## clusters that have more than one member can be marked as subgraphs.
##
map({ $a = ""; map({ $a .= $_; $clusters{$a}++; } /([^-_]*[-_])/g); } @pkgs);

##
## impose some sort of order on the pkgs by assigning them numbers
## that indicate their height in the graph
##
map(order(1, $_), @pkgs);

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
## if we want to check a specific pkg for rebuild impact... 
##
if ($outofdate) {
    $usecolor = 1;
    $outofdate = canonicalize($outofdate);

    if ($color{$outofdate} ne "red") {
	$color{$outofdate} = "red";
	$need{$outofdate} = "$outofdate (forced)";
    }
}

##
## if we want to update a specific package, mark all non-related
## packages as "green"
##
if ($update) {
    $update = canonicalize($update);

    # these things will need to be checked
    @reqs = sort(keys %{$req{$update}});
    @rreqs = recurse(@reqs);

    # check each pkg to see if it will be affected
    foreach $pkg (@pkgs) {
	# these pkgs are dependencies
	if (grep($pkg eq $_, ($update, @reqs, @rreqs))) {
	    if ($force && $color{$pkg} ne "red") {
		# we want to force rebuild of *all* dependencies
		$color{$pkg} = "red";
		$need{$pkg} = "$pkg (forced)";
	    }
	}
	# these packages do not depend on any of $update's dependencies
	else {
	    delete($color{$pkg});
	    delete($need{$pkg});
	}
    }
}

##
## "delete" output, ordered with "least depended on" first
##
if ($delete) {
    map(print("$_\n"),
	reverse(sort(byord grep(color($_) ne "green", @pkgs))));
    exit(0);
}

##
## "rebuild" output for sh(1), with just leaves listed
##
if ($rebuild) {
    map(printf("( pkg_info -qe %s || " .
	       "( cd %s/%s && " .
	       "make %s%s )) &&\n",
	       ($need{$_} || $_) =~ /(.*)-.*/,
	       $pkgsrcdir, $where{$_},
	       $rebuild,
	       $clean ? " && make $clean" : ""),
	grep(color($_) ne "green" && $ord{$_} == 1, @pkgs));
    print("true\n");
    exit(0);
}

##
## show left overs as a graph
##
printf("digraph \"%s\" {\n",
       $limit ? "out of date packages" : "packages");
foreach $pkg (sort(bynum @pkgs)) {
    $color = color($pkg);
    next if ($limit && $color eq "green");
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
    $suffix .= ", LEAF" if ($ord{$pkg} == 1);
    $a = "";
    $b = 0;
    foreach ($pkg =~ /([^-_]*[-_])/g) {
	last if ($clusters{$a .= $_} <= 1 || !$group);
	next if ($b && $clusters{$a} >= $b);
	printf("subgraph \"cluster_%s\" {\n", substr($a, 0, -1));
	$b = $clusters{$a};
	$closeme .= "}\n";
    }
    printf("\"%s\" [color=\"%s\",label=\"%s\"];$suffix\n", $pkg,
	   $usecolor ? $color : "black", $label);
    print($closeme);
    $closeme = "";
    @reqs = sort(keys %{$req{$pkg}});
    $suffix =~ s/, LEAF$//;
    $suffix .= ", EDGE";
    foreach $req (@reqs) {
	$color = color($req);
	next if ($limit && $color eq "green");
	printf("\"%s\" -> \"%s\" [color=\"%s\"];$suffix\n", $req, $pkg,
	       $usecolor ? $color : "black");
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
## canonicalize a pkg name based on what we have installed
##
sub canonicalize {
    my($canon);
    my($pkg) = @_;

    # attempt to find actual pkg, first by argument given...
    ($canon) = grep($pkg eq $_, @pkgs);

    # ...then by comparing against the internal list sans version numbers
    ($canon) = grep(($a = $_) =~ s/(.*)-.*/$1/ && $pkg eq $a, @pkgs)
        if (!defined($canon));

    die("package '$update' not found\n")
        if (!defined($canon));

    $canon;
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
    if ($color{$pkg}) {
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
