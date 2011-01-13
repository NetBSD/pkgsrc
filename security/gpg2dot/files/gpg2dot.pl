#! @PREFIX@/bin/perl
#
# $NetBSD: gpg2dot.pl,v 1.5 2011/01/13 00:40:09 lukem Exp $

# ----------------------------------------------------------------------------
# "THE BEER-WARE LICENSE" (Revision 42):
# Andrew Brown <atatat@NetBSD.org> and Luke Mewburn <lukem@NetBSD.org>
# wrote this file.  As long as you retain this notice you can do whatever
# you want with this stuff.  If we meet some day, and you think this stuff
# is worth it, you can buy us a beer in return.
# ----------------------------------------------------------------------------

#
# gpg2dot [mykey] --
#	generate input for dot(1) from gpg(1) --list-sigs
#		gpg	http://www.gnupg.org
#		dot	http://www.graphviz.org/
#

$url_statistics='http://webware.lysator.liu.se/jc/wotsap/search/keystatistics?key=%s';
$url_pathfinder='http://webware.lysator.liu.se/jc/wotsap/search/paths?top=%s&bottom=%s';

$now = localtime();
$mykeyid = uc shift;

open(GPG, "gpg --list-sigs --with-colons --no-sig-cache --verbose 2>/dev/null |");
while (<GPG>) {
    chomp;
    my @fields = split /:/;
    if ($fields[0] eq "pub" || $fields[0] eq "uid") {
	if ($fields[0] eq "pub") {
	    ($keyid, $date, $kuid) = ($fields[4], $fields[5], $fields[9]);
	}
	else {
	    next; # XXX --with-colons doesn't seem to produce uid records with useable values
	    ($kuid) = ($fields[$9]);
	}
	$kuid =~ s/\"/\\\"/g;
	$kuid =~ s/\\x([0-9a-fA-F]+)/chr(hex($1))/eg;
	$keyid = substr($keyid, -8);
	$kuid{$keyid} = $kuid;
	next if ($label{$keyid} != "");
	$label{$keyid} = "$keyid - $date\\n$kuid";
    }
    elsif ($fields[0] eq "sig") {
	($skeyid, $date, $suid) = ($fields[4], $fields[5], $fields[9]);
	$skeyid = substr($skeyid, -8);
	next if ($suid =~ /id not found/ ||
		 $skeyid eq $keyid);
	push(@isigs, "$keyid $skeyid $date $suid");
	$sigmap{"$keyid-$skeyid"} = 1;
    }
}

foreach (@isigs) {
    ($keyid, $skeyid, $date, $suid) = split(/ /, $_, 4);
    next if (!$kuid{$keyid} || !$kuid{$skeyid});
    next if ($sigmap{"$skeyid-$keyid"} == -1);
    $color = "black";
    $attrs = "";
    if ($sigmap{"$skeyid-$keyid"}) {
	if ($keyid eq $mykeyid ||
	    $skeyid eq $mykeyid) {	# two way trust, includes me
	    $color = "green";
	} else {			# two way trust, me unevolved
	    $color = "blue";
	}
	$attrs = ",dir=\"both\"";
	$sigmap{"$keyid-$skeyid"} = -1;
    } elsif ($keyid eq $mykeyid) {	# you trust me (one way)
	$color = "orange";
    } elsif ($skeyid eq $mykeyid) {	# i trust you (one way)
	$color = "red";
    }
    push(@sigs, sprintf("\"%s\" -> \"%s\"[tailURL=\"%s\",headURL=\"%s\",color=\"%s\"%s];\t// %s -> %s\n",
			$skeyid, $keyid,
			sprintf($url_pathfinder, $keyid, $skeyid),
			sprintf($url_pathfinder, $skeyid, $keyid),
			$color, $attrs,
			$kuid{$skeyid}, $kuid{$keyid}));
    $signer{$skeyid} = "yes";
    $signed{$keyid} = "yes";
}

foreach (keys %label) {
    next if (!$signer{$_} && !$signed{$_});
    push(@keys, sprintf("\"%s\" [URL=\"%s\",label=\"%s\",shape=\"box\"];\n",
			$_, sprintf($url_statistics, $_), $label{$_}));
}

@sigs = uniq(sort(@sigs));

$" = "";
print(<<"EOF")
digraph "gpg" {
label = "gpg signature graph, $now";

@keys
@sigs
}
EOF
    ;

sub uniq {
    my (@i) = @_;
    my (@o);
    push(@o, shift(@i));
    foreach (@i) {
	push(@o, $_) if ($o[-1] ne $_);
    }
    @o;
}
