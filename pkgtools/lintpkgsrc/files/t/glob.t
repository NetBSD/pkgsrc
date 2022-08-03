# $NetBSD: glob.t,v 1.1 2022/08/03 16:15:49 rillig Exp $

use strict;
use warnings;
use Test;

BEGIN { plan tests => 12; }

require('../lintpkgsrc.pl');

sub test_glob2regex() {

	ok(glob2regex('*'), '^.*$');

	ok(glob2regex('?'), '^.$');

	# The '' means that the regular expression equals the glob.
	ok(glob2regex('[a-z]'), '');

	# The '' means that the regular expression equals the glob.
	ok(glob2regex('[a-z0-9]'), '');

	# The '' means that the regular expression equals the glob.
	ok(glob2regex('[a-z0-9_]'), '');

	ok(glob2regex('*.[ch]'), '^.*\.[ch]$');

	ok(glob2regex('{one,two}'), '^(one|two)$');

	ok(glob2regex('{{thi,fou}r,fif}teen'), '^((thi|fou)r|fif)teen$');

	# There is an unbalanced '}' at the very end.
	ok(glob2regex('{{thi,fou}r,fif}teen}'), undef);

	# XXX: Why is '+' turned into '.'?
	ok(glob2regex('a+b|c'), '^a.b\|c$');

	# XXX: Typo in the code, the case '\\+' is unreachable.
	# Escaping the backslash works nevertheless.
	ok(glob2regex('a\[b*'), '^a\[b.*$');

	# XXX: Depending on the exact implementation, the '\n' may be
	# interpreted as a newline, a literal 'n' or a literal '\' 'n'.
	ok(glob2regex('a\n*'), '^a\n.*$');
}

test_glob2regex();
