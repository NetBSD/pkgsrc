# $NetBSD: parse_makefile.t,v 1.10 2022/08/12 22:45:14 rillig Exp $

use strict;
use warnings;
use File::Slurp;
use File::Temp;
use Test;

BEGIN { plan tests => 29, onfail => sub { die } }

require('../lintpkgsrc.pl');

sub enable_debug_logging() {
	export_for_test()->{opt}->{D} = 1;
}

sub disable_debug_logging() {
	export_for_test()->{opt}->{D} = 0;
}

sub test_expand_exprs() {
	my %vars = (
	    CFLAGS      => '${CFLAGS_OPT} ${CFLAGS_WARN} ${CFLAGS_ERR}',
	    CFLAGS_WARN => '${CFLAGS_WARN_ALL}',
	    CFLAGS_OPT  => '-Os',
	    CFLAGS_ERR  => '${CFLAGS_WARN_ALL:M*error=*}',
	    '2_DOLLAR'  => '$${CFLAGS_OPT}',
	    '3_DOLLAR'  => '$$${CFLAGS_OPT}',
	);

	ok(expand_exprs('<${CFLAGS}>', \%vars),
	    '<-Os M_a_G_i_C_uNdEfInEd ${CFLAGS_WARN_ALL:M*error=*}>');

	# FIXME: '$$' must be preserved, the result must be '$${CFLAGS_OPT}'.
	ok(expand_exprs('<${2_DOLLAR}>', \%vars),
	    '<$-Os>');
	ok(expand_exprs('<${3_DOLLAR}>', \%vars),
	    '<$$-Os>');
}

sub test_parse_makefile_vars() {
	my $dir = File::Temp->newdir();
	my $file = "$dir/filename.mk";

	write_file($file, map { "$_\n" } (
	    '# comment',
	    "VAR=\tvalue",
	    "COMMENT=\tvalue#comment",
	    "MULTI=\tone\\",
	    "\ttwo\\",
	    'three#comment',
	));

	my $vars = parse_makefile_vars($file, undef);

	ok(
	    join(', ', sort keys %$vars),
	    '.CURDIR, BSD_PKG_MK, COMMENT, MULTI, VAR');
	ok($vars->{BSD_PKG_MK}, 'YES');

	ok($vars->{COMMENT}, 'value');

	ok($vars->{MULTI}, 'one two three');

	ok($vars->{VAR}, 'value');
}

sub test_parse_makefile_vars_cond() {
	my $dir = File::Temp->newdir();
	my $file = "$dir/filename.mk";

	write_file($file, map { "$_\n" } (
	    '.if ${COND} == then',
	    'BRANCH= then',
	    '.elif ${COND} == elif',
	    'BRANCH= elif',
	    '.else',
	    'BRANCH= else',
	    '.endif',
	));

	my $vars;
	export_for_test()->{default_vars}->{COND} = 'then';
	$vars = parse_makefile_vars($file, undef);
	ok($vars->{BRANCH}, 'then');

	export_for_test()->{default_vars}->{COND} = 'elif';
	$vars = parse_makefile_vars($file, undef);
	ok($vars->{BRANCH}, 'elif');

	# XXX: The string 'anything else' would not work due to the space.
	export_for_test()->{default_vars}->{COND} = 'anything_else';
	$vars = parse_makefile_vars($file, undef);
	ok($vars->{BRANCH}, 'else');
}

sub test_expand_modifiers() {
	my $vars = {
	    REF => 'VALUE',
	};

	expand_modifiers('file.mk', 'VAR', '<', 'REF', 'S,U,X,', '>', $vars);

	# Ensure that the 'U' in the modifier 'S,U,X,' is not interpreted as
	# the modifier ':U'. Before lintpkgsrc.pl 1.81 from 2022-08-13,
	# lintpkgsrc did exactly that.
	ok($vars->{VAR}, '<VALXE>');

	expand_modifiers('file.mk', 'VAR', '<', 'REF', 'S,VAL,H,', '>', $vars);

	ok($vars->{VAR}, '<HUE>');
}

sub test_eval_mk_cond_func() {
	my $vars = {
	    'EMPTY'    => '',
	    'SPACE'    => ' ',
	    'WORD'     => 'word',
	    'WORDS'    => 'word1 word2',
	    'DEV_NULL' => '/dev/null',
	};

	ok(eval_mk_cond_func('defined', '', $vars), 0);
	ok(eval_mk_cond_func('defined', 'UNDEF', $vars), 0);
	ok(eval_mk_cond_func('defined', 'EMPTY', $vars), 1);
	ok(eval_mk_cond_func('defined', 'SPACE', $vars), 1);
	ok(eval_mk_cond_func('defined', 'WORDS', $vars), 1);

	# TODO: The expression '${}' doesn't expand to an empty string.
	ok(eval_mk_cond_func('empty', '', $vars), 0);

	ok(eval_mk_cond_func('empty', 'EMPTY', $vars), 1);
	ok(eval_mk_cond_func('empty', 'SPACE', $vars), 1);
	ok(eval_mk_cond_func('empty', 'WORD', $vars), 0);
	ok(eval_mk_cond_func('empty', 'WORDS', $vars), 0);

	ok(eval_mk_cond_func('empty', 'EMPTY:M*', $vars), 1);
	ok(eval_mk_cond_func('empty', 'SPACE:M*', $vars), 1);
	ok(eval_mk_cond_func('empty', 'WORD:Mword', $vars), 0);
	ok(eval_mk_cond_func('empty', 'WORD:Mword1', $vars), 1);
	ok(eval_mk_cond_func('empty', 'WORD:M*', $vars), 0);

	# Only expressions with a single ':M' modifier are supported.
	# The expression '${WORD:Mword:Mword}' is not expanded further,
	# and is thus nonempty.
	ok(eval_mk_cond_func('empty', 'WORD:Mword:Mword', $vars), 0);

	ok(eval_mk_cond_func('exists', '/dev/null', $vars), 1);
	ok(eval_mk_cond_func('exists', '${DEV_NULL}', $vars), 1);
	ok(eval_mk_cond_func('exists', '/random-46699840-8aca', $vars), 0);

	ok(eval_mk_cond_func('make', 'anything', $vars), 0);

	ok(eval_mk_cond_func('target', 'anything', $vars), 0);
}

sub test_parse_eval_make_false() {
	my $vars = {
	    'EMPTY'    => '',
	    'SPACE'    => ' ',
	    'WORD'     => 'word',
	    'WORDS'    => 'word1 word2',
	    'DEV_NULL' => '/dev/null',
	};

	# 1 means false, 0 means true.
	ok(parse_eval_make_false('defined(UNDEF)', $vars), 1);
	ok(parse_eval_make_false('defined(EMPTY)', $vars), 0);
}

test_expand_exprs();
test_parse_makefile_vars();
test_parse_makefile_vars_cond();
test_expand_modifiers();
test_eval_mk_cond_func();
test_parse_eval_make_false();
