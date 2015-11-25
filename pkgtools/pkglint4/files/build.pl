#! @PERL@
# $NetBSD: build.pl,v 1.1 2015/11/25 16:42:21 rillig Exp $
#

use strict;
use warnings;

sub readfile {
	my $file = shift;

	local $/ = undef;
	open(my $in, "<", $file) || die "failed to read $file: $!";
	my $contents = <$in>;
	close($in) || die "failed to read $file: $!";

	return $contents;
}

while (my $line = <>) {
	if ($line =~ m"^#include (.+)$/") {
		print readfile($1);
	} else {
		print $line;
	}
}
