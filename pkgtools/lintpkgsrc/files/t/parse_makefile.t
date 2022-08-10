# $NetBSD: parse_makefile.t,v 1.5 2022/08/10 07:12:52 rillig Exp $

use strict;
use warnings;
use File::Slurp;
use File::Temp;
use Test;

BEGIN { plan tests => 6, onfail => sub { die } }

require('../lintpkgsrc.pl');

sub test_expand_var() {
	my %vars = (
	    CFLAGS      => '${CFLAGS_OPT} ${CFLAGS_WARN} ${CFLAGS_ERR}',
	    CFLAGS_WARN => '${CFLAGS_WARN_ALL}',
	    CFLAGS_OPT  => '-Os',
	    CFLAGS_ERR  => '${CFLAGS_WARN_ALL:M*error=*}',
	);

	my $cflags = expand_var('<${CFLAGS}>', \%vars);

	ok($cflags, '<-Os M_a_G_i_C_uNdEfInEd ${CFLAGS_WARN_ALL:M*error=*}>')
}

sub test_parse_makefile_vars() {
	my $dir = File::Temp->newdir();
	my $file = "$dir/filename.mk";

	write_file($file,
	    "# comment\n",
	    "VAR=\tvalue\n",
	    "COMMENT=\tvalue#comment\n",
	    "MULTI=\tone\\\n",
	    "\ttwo\\\n",
	    "three#comment\n"
	);

	my $vars = parse_makefile_vars($file, undef);

	ok(
	    join(', ', sort keys %$vars),
	    '.CURDIR, BSD_PKG_MK, COMMENT, MULTI, VAR');
	ok($vars->{BSD_PKG_MK}, 'YES');

	# FIXME: must be 'value'
	ok($vars->{COMMENT}, 'valu');

	# FIXME: must be 'one two three'
	ok($vars->{MULTI}, "on\ttwthree#comment");

	ok($vars->{VAR}, 'value');
}

sub test_expand_modifiers() {
	my $vars = {
	    REF => 'VALUE',
	};
	export_for_test()->{opt}->{D} = 1;

	expand_modifiers('file.mk', 'VAR', '<', 'REF', 'S,U,X,', '>', $vars);

	# FIXME: Should be 'VALXE', but the 'U' is wrongly interpreted as a
	#  ':U' modifier.
	ok($vars->{VAR}, '<VALUE>');

	expand_modifiers('file.mk', 'VAR', '<', 'REF', 'S,VAL,H,', '>', $vars);

	ok($vars->{VAR}, '<HUE>');
}

test_expand_var();
test_parse_makefile_vars();
test_expand_modifiers();
