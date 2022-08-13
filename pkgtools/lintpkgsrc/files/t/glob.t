# $NetBSD: glob.t,v 1.8 2022/08/13 12:22:20 rillig Exp $
#
# Tests for file globbing and matching.

use strict;
use warnings;
use Test;

BEGIN { plan tests => 27, onfail => sub { die } }

require('../lintpkgsrc.pl');

sub test_glob2regex() {

	ok(glob2regex('*'), '^.*$');
	ok(glob2regex('\*'), '');

	ok(glob2regex('?'), '^.$');
	ok(glob2regex('\?'), '');

	# Ordinary characters in glob patterns.
	ok(glob2regex('+'), '^\+$');
	ok(glob2regex('\+'), '');
	ok(glob2regex('|'), '^\|$');
	ok(glob2regex('\|'), '');

	ok(glob2regex('\.'), '');
	ok(glob2regex('\n'), '^n$');
	ok(glob2regex('\\\\'), '');
	ok(glob2regex('\['), '');
	ok(glob2regex('\{'), '');
	ok(glob2regex('\-'), '');

	ok(glob2regex('[a-z]'), '');
	ok(glob2regex('[a-z0-9]'), '');
	ok(glob2regex('[a-z0-9_]'), '');
	ok(glob2regex('[*]'), '');

	ok(glob2regex('*.[ch]'), '^.*\.[ch]$');

	# Outside of braces, the ',' is a regular character.
	ok(glob2regex('a,b'), '');
	ok(glob2regex('{one,two}'), '^(one|two)$');
	ok(glob2regex('{{thi,fou}r,fif}teen'), '^((thi|fou)r|fif)teen$');

	# There is an unbalanced '}' at the very end.
	ok(glob2regex('{four,fif}teen}'), undef);

	# An escaped '[' does not start a character class.
	ok(glob2regex('a\[b*'), '^a\[b.*$');

	ok(glob2regex('a\n*'), '^an.*$');

	# https://gnats.netbsd.org/12996
	ok(glob2regex('libsigc++'), '^libsigc\+\+$');

	my $re = 'a\nb';
	ok("a\nb" =~ $re, 1);
}

test_glob2regex();
