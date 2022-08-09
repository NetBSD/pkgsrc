# $NetBSD: glob.t,v 1.5 2022/08/09 18:14:22 rillig Exp $

use strict;
use warnings;
use Test;

BEGIN { plan tests => 12, onfail => sub { die } }

require('../lintpkgsrc.pl');

sub test_glob2regex() {

	ok(glob2regex('*'), '^.*$');

	ok(glob2regex('?'), '^.$');

	ok(glob2regex('[a-z]'), '');

	ok(glob2regex('[a-z0-9]'), '');

	ok(glob2regex('[a-z0-9_]'), '');

	# Outside of braces, the ',' is a regular character.
	ok(glob2regex('a,b'), '');

	# FIXME: Inside brackets, the '*' is a literal '*'.
	ok(glob2regex('[*]'), '^[.*]$');

	ok(glob2regex('\*'), '');

	ok(glob2regex('*.[ch]'), '^.*\.[ch]$');

	ok(glob2regex('{one,two}'), '^(one|two)$');

	ok(glob2regex('{{thi,fou}r,fif}teen'), '^((thi|fou)r|fif)teen$');

	# There is an unbalanced '}' at the very end.
	ok(glob2regex('{{thi,fou}r,fif}teen}'), undef);

	ok(glob2regex('a+b|c'), '^a\+b\|c$');

	ok(glob2regex('a\[b*'), '^a\[b.*$');

	ok(glob2regex('a\+b'), '');

	ok(glob2regex('a\?b'), '');

	# XXX: Depending on the exact implementation, the '\n' may be
	# interpreted as a newline, a literal 'n' or a literal '\' 'n'.
	ok(glob2regex('a\n*'), '^a\n.*$');

	# https://gnats.netbsd.org/12996
	ok(glob2regex('libsigc++'), '^libsigc\+\+$');
}

test_glob2regex();
