#!@PREFIX@/bin/perl

# ----------------------------------------------------------------------------
# "THE BEER-WARE LICENSE" (Revision 42):
# <atatat@NetBSD.ORG> wrote this file.  As long as you retain this notice you
# can do whatever you want with this stuff. If we meet some day, and you think
# this stuff is worth it, you can buy me a beer in return.
#
# Andrew Brown
# ----------------------------------------------------------------------------

$date = localtime();

$sg = "";
open(GPG, "gpg --list-keys --verbose 2>/dev/null |");
while (<GPG>) {
    chomp;
    if (/^(pub) +(\S+)\s+(\S+)\s+(.+\S)/ ||
	/^(uid) +\s+(.+\S)/) {
	if ($1 eq "pub") {
	    ($lkeyid, $date, $kuid) = ($2, $3, $4);
	}
	else {
	    ($kuid) = ($2);
	}
	$kuid =~ s/\"/\\\"/g;
	($keyid = $lkeyid) =~ s:.*/::;
	next if ($kuid !~ /netbsd.org/i);
	$kuid{$keyid} = $kuid;
	$label{$keyid} = "$lkeyid - $date\\n$kuid";
    }
    elsif (/^sig (.{7}) (\S+)\s+(\S+)\s+(.+\S)/) {
	($skeyid, $date, $suid) = ($2, $3, $4);
	next if ($kuid !~ /netbsd.org/i ||
		 $suid =~ /id not found/ ||
		 $skeyid eq $keyid);
	push(@isigs, "$keyid $skeyid $date $suid");
    }
}

foreach (@isigs) {
    ($keyid, $skeyid, $date, $suid) = split(/ /, $_, 4);
    next if (!$kuid{$keyid} || !$kuid{$skeyid});
    push(@sigs, sprintf("\"%s\" -> \"%s\";\t// %s -> %s\n",
			$skeyid, $keyid, $kuid{$skeyid}, $kuid{$keyid}));
    $signer{$skeyid} = "yes";
    $signed{$keyid} = "yes";
}

foreach (keys %label) {
    next if (!$signer{$_} && !$signed{$_});
    push(@keys, sprintf("\"%s\" [label=\"%s\"];\n",
			$_, $label{$_}));
}

@sigs = uniq(sort(@sigs));

$" = "";
print(<<"EOF")
digraph "gpg" {
label = "gpg signature graph, $date";

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
