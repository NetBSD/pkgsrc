# $MirOS: src/bin/mksh/check.t,v 1.845 2020/05/16 22:19:15 tg Exp $
# -*- mode: sh -*-
#-
# Copyright ¬© 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010,
#	      2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018,
#	      2019, 2020
#	mirabilos <m@mirbsd.org>
#
# Provided that these terms and disclaimer and all copyright notices
# are retained or reproduced in an accompanying document, permission
# is granted to deal in this work without restriction, including un‚Äê
# limited rights to use, publicly perform, distribute, sell, modify,
# merge, give away, or sublicence.
#
# This work is provided ‚ÄúAS IS‚Äù and WITHOUT WARRANTY of any kind, to
# the utmost extent permitted by applicable law, neither express nor
# implied; without malicious intent or gross negligence. In no event
# may a licensor, author or contributor be held liable for indirect,
# direct, other damage, loss, or other issues arising in any way out
# of dealing in the work, even if advised of the possibility of such
# damage or existence of a defect, except proven that it results out
# of said person‚Äôs immediate fault when using the work as intended.
#-
# You may also want to test IFS with the script at
# http://www.research.att.com/~gsf/public/ifs.sh
#
# More testsuites at:
# http://svnweb.freebsd.org/base/head/bin/test/tests/legacy_test.sh?view=co&content-type=text%2Fplain
#
# Integrated testsuites from:
# (2013/12/02 20:39:44) http://cvsweb.openbsd.org/cgi-bin/cvsweb/src/regress/bin/ksh/?sortby=date

expected-stdout:
	KSH R59 2020/05/16
description:
	Check base version of full shell
stdin:
	vsn=${KSH_VERSION%%' +'*}
	echo "${vsn#* }"
name: KSH_VERSION
---
expected-stdout:
	@(#)MIRBSD
description:
	Check this identifies as legacy shell
stdin:
	echo "${KSH_VERSION%% *}"
name: KSH_VERSION-modern
category: !shell:legacy-yes
---
expected-stdout:
	@(#)LEGACY
description:
	Check this identifies as legacy shell
stdin:
	echo "${KSH_VERSION%% *}"
name: KSH_VERSION-legacy
category: !shell:legacy-no
---
name: KSH_VERSION-ascii
description:
	Check that the shell version tag does not include EBCDIC
category: !shell:ebcdic-yes
stdin:
	set -o noglob
	for x in $KSH_VERSION; do
		[[ $x = '+EBCDIC' ]] && exit 1
	done
	exit 0
---
name: KSH_VERSION-ebcdic
description:
	Check that the shell version tag includes EBCDIC
category: !shell:ebcdic-no
stdin:
	set -o noglob
	for x in $KSH_VERSION; do
		[[ $x = '+EBCDIC' ]] && exit 0
	done
	exit 1
---
name: KSH_VERSION-binmode
description:
	Check that the shell version tag does not include TEXTMODE
category: !shell:textmode-yes
stdin:
	set -o noglob
	for x in $KSH_VERSION; do
		[[ $x = '+TEXTMODE' ]] && exit 1
	done
	exit 0
---
name: KSH_VERSION-textmode
description:
	Check that the shell version tag includes TEXTMODE
category: !shell:textmode-no
stdin:
	set -o noglob
	for x in $KSH_VERSION; do
		[[ $x = '+TEXTMODE' ]] && exit 0
	done
	exit 1
---
name: selftest-1
description:
	Regression test self-testing
stdin:
	echo ${foo:-baz}
expected-stdout:
	baz
---
name: selftest-2
description:
	Regression test self-testing
env-setup: !foo=bar!
stdin:
	echo ${foo:-baz}
expected-stdout:
	bar
---
name: selftest-3
description:
	Regression test self-testing
env-setup: !ENV=fnord!
stdin:
	echo "<$ENV>"
expected-stdout:
	<fnord>
---
name: selftest-exec
description:
	Ensure that the test run directory (default /tmp but can be changed
	with check.pl flag -T or test.sh $TMPDIR) is not mounted noexec, as
	we execute scripts from the scratch directory during several tests.
stdin:
	print '#!'"$__progname"'\necho tf' >lq
	chmod +x lq
	./lq
expected-stdout:
	tf
---
name: selftest-env
description:
	Just output the environment variables set (always fails)
category: disabled
stdin:
	set
---
name: selftest-direct-builtin-call
description:
	Check that direct builtin calls work
stdin:
	ln -s "$__progname" cat || cp "$__progname" cat
	ln -s "$__progname" echo || cp "$__progname" echo
	./echo -c 'echo  foo' | ./cat -u
expected-stdout:
	-c echo  foo
---
name: selftest-pathsep-unix
description:
	Check that $PATHSEP is set correctly.
category: !os:os2
stdin:
	PATHSEP=.; export PATHSEP
	"$__progname" -c 'print -r -- $PATHSEP'
expected-stdout:
	:
---
name: selftest-pathsep-dospath
description:
	Check that $PATHSEP is set correctly.
category: os:os2
stdin:
	PATHSEP=.; export PATHSEP
	"$__progname" -c 'print -r -- $PATHSEP'
expected-stdout:
	;
---
name: selftest-tty-absent
description:
	Check that a controlling tty is not present as regress:no-ctty was used
	(if this test fails for you DO NOT PASS regress:no-ctty and fix every
	other test that fails: why u use it if u haz ctty?)
category: regress:no-ctty
env-setup: !ENV=./envf!
file-setup: file 644 "envf"
	PS1=X
arguments: !-i!
stdin:
	echo ok
expected-stdout:
	ok
expected-stderr-pattern:
	/ksh: warning: won't have full job control\nXX/
---
name: selftest-tty-present
description:
	Check that a controlling tty is present as regress:no-ctty was not used
need-ctty: yes
env-setup: !ENV=./envf!
file-setup: file 644 "envf"
	PS1=X
arguments: !-i!
stdin:
	echo ok
expected-stdout:
	ok
expected-stderr: !
	XX
---
name: alias-1
description:
	Check that recursion is detected/avoided in aliases.
stdin:
	alias fooBar=fooBar
	fooBar
	exit 0
expected-stderr-pattern:
	/fooBar.*not found.*/
---
name: alias-2
description:
	Check that recursion is detected/avoided in aliases.
stdin:
	alias fooBar=barFoo
	alias barFoo=fooBar
	fooBar
	barFoo
	exit 0
expected-stderr-pattern:
	/fooBar.*not found.*\n.*barFoo.*not found/
---
name: alias-3
description:
	Check that recursion is detected/avoided in aliases.
stdin:
	alias Echo='echo '
	alias fooBar=barFoo
	alias barFoo=fooBar
	Echo fooBar
	unalias barFoo
	Echo fooBar
expected-stdout:
	fooBar
	barFoo
---
name: alias-4
description:
	Check that alias expansion isn't done on keywords (in keyword
	postitions).
stdin:
	alias Echo='echo '
	alias while=While
	while false; do echo hi ; done
	Echo while
expected-stdout:
	While
---
name: alias-5
description:
	Check that alias expansion done after alias with trailing space.
stdin:
	alias Echo='echo '
	alias foo='bar stuff '
	alias bar='Bar1 Bar2 '
	alias stuff='Stuff'
	alias blah='Blah'
	Echo foo blah
expected-stdout:
	Bar1 Bar2 Stuff Blah
---
name: alias-6
description:
	Check that alias expansion done after alias with trailing space.
stdin:
	alias Echo='echo '
	alias foo='bar bar'
	alias bar='Bar '
	alias blah=Blah
	Echo foo blah
expected-stdout:
	Bar Bar Blah
---
name: alias-7
description:
	Check that alias expansion done after alias with trailing space
	after a keyword.
stdin:
	alias X='case '
	alias Y=Z
	X Y in 'Y') echo is y ;; Z) echo is z ;; esac
expected-stdout:
	is z
---
name: alias-8
description:
	Check that newlines in an alias don't cause the command to be lost.
stdin:
	alias foo='
	
	
	echo hi
	
	
	
	echo there
	
	
	'
	foo
expected-stdout:
	hi
	there
---
name: alias-9
description:
	Check that recursion is detected/avoided in aliases.
	This check fails for slow machines or Cygwin, raise
	the time-limit clause (e.g. to 7) if this occurs.
time-limit: 3
stdin:
	print '#!'"$__progname"'\necho tf' >lq
	chmod +x lq
	PATH=$PWD$PATHSEP$PATH
	alias lq=lq
	lq
	echo = now
	i=`lq`
	print -r -- $i
	echo = out
	exit 0
expected-stdout:
	tf
	= now
	tf
	= out
---
name: alias-10
description:
	Check that recursion is detected/avoided in aliases.
	Regression, introduced during an old bugfix.
stdin:
	alias foo='print hello '
	alias bar='foo world'
	echo $(bar)
expected-stdout:
	hello world
---
name: alias-11
description:
	Check that special argument handling still applies with escaped aliases
stdin:
	alias local1='\typeset'
	alias local2='\\builtin typeset'
	function fooa {
		local1 x=$1 y=z
		print -r -- "$x,$y"
	}
	function foob {
		local2 x=$1 y=z
		print -r -- "$x,$y"
	}
	x=1 y=2; fooa 'bar - baz'
	x=1 y=2; foob 'bar - baz'
expected-stdout:
	bar - baz,z
	bar - baz,z
---
name: alias-12
description:
	Something weird from Martijn Dekker
stdin:
	alias echo=print
	x() { echo a; (echo b); x=$(echo c); }
	typeset -f x
	alias OPEN='{' CLOSE='};'
	{ OPEN echo hi1; CLOSE }
	var=`{ OPEN echo hi2; CLOSE }` && echo "$var"
	var=$({ OPEN echo hi3; CLOSE }) && echo "$var"
expected-stdout:
	x() {
		\print a 
		( \print b ) 
		x=$(\print c ) 
	} 
	hi1
	hi2
	hi3
---
name: arith-compound
description:
	Check that arithmetic expressions are compound constructs
stdin:
	{ ! (( 0$(cat >&2) )) <<<1; } <<<2
expected-stderr:
	1
---
name: arith-lazy-1
description:
	Check that only one side of ternary operator is evaluated
stdin:
	x=i+=2
	y=j+=2
	typeset -i i=1 j=1
	echo $((1 ? 20 : (x+=2)))
	echo $i,$x
	echo $((0 ? (y+=2) : 30))
	echo $j,$y
expected-stdout:
	20
	1,i+=2
	30
	1,j+=2
---
name: arith-lazy-2
description:
	Check that assignments not done on non-evaluated side of ternary
	operator
stdin:
	x=i+=2
	y=j+=2
	typeset -i i=1 j=1
	echo $((1 ? 20 : (x+=2)))
	echo $i,$x
	echo $((0 ? (y+=2) : 30))
	echo $i,$y
expected-stdout:
	20
	1,i+=2
	30
	1,j+=2
---
name: arith-lazy-3
description:
	Check that assignments not done on non-evaluated side of ternary
	operator and this construct is parsed correctly (Debian #445651)
stdin:
	x=4
	y=$((0 ? x=1 : 2))
	echo = $x $y =
expected-stdout:
	= 4 2 =
---
name: arith-lazy-4
description:
	Check that preun/postun not done on non-evaluated side of ternary
	operator
stdin:
	(( m = n = 0, 1 ? n++ : m++ ? 2 : 3 ))
	echo "($n, $m)"
	m=0; echo $(( 0 ? ++m : 2 )); echo $m
	m=0; echo $(( 0 ? m++ : 2 )); echo $m
expected-stdout:
	(1, 0)
	2
	0
	2
	0
---
name: arith-lazy-5-arr-n
description: Check lazy evaluation with side effects
stdin:
	a=0; echo "$((0&&b[a++],a))"
expected-stdout:
	0
---
name: arith-lazy-5-arr-p
description: Check lazy evaluation with side effects
stdin:
	a=0; echo "$((0&&(b[a++]),a))"
expected-stdout:
	0
---
name: arith-lazy-5-str-n
description: Check lazy evaluation with side effects
stdin:
	a=0 b=a++; ((0&&b)); echo $a
expected-stdout:
	0
---
name: arith-lazy-5-str-p
description: Check lazy evaluation with side effects
stdin:
	a=0 b=a++; ((0&&(b))); echo $a
expected-stdout:
	0
---
name: arith-lazy-5-tern-l-n
description: Check lazy evaluation with side effects
stdin:
	a=0; echo "$((0?b[a++]:999,a))"
expected-stdout:
	0
---
name: arith-lazy-5-tern-l-p
description: Check lazy evaluation with side effects
stdin:
	a=0; echo "$((0?(b[a++]):999,a))"
expected-stdout:
	0
---
name: arith-lazy-5-tern-r-n
description: Check lazy evaluation with side effects
stdin:
	a=0; echo "$((1?999:b[a++],a))"
expected-stdout:
	0
---
name: arith-lazy-5-tern-r-p
description: Check lazy evaluation with side effects
stdin:
	a=0; echo "$((1?999:(b[a++]),a))"
expected-stdout:
	0
---
name: arith-ternary-prec-1
description:
	Check precedence of ternary operator vs assignment
stdin:
	typeset -i x=2
	y=$((1 ? 20 : x+=2))
expected-exit: e != 0
expected-stderr-pattern:
	/.*:.*1 \? 20 : x\+=2.*lvalue.*\n$/
---
name: arith-ternary-prec-2
description:
	Check precedence of ternary operator vs assignment
stdin:
	typeset -i x=2
	echo $((0 ? x+=2 : 20))
expected-stdout:
	20
---
name: arith-prec-1
description:
	Prove arithmetic expressions with embedded parameter
	substitutions cannot be parsed ahead of time
stdin:
	a='3 + 4'
	print 1 $((2 * a)) .
	print 2 $((2 * $a)) .
expected-stdout:
	1 14 .
	2 10 .
---
name: arith-div-assoc-1
description:
	Check associativity of division operator
stdin:
	echo $((20 / 2 / 2))
expected-stdout:
	5
---
name: arith-div-byzero
description:
	Check division by zero errors out
stdin:
	x=$(echo $((1 / 0)))
	echo =$?:$x.
expected-stdout:
	=1:.
expected-stderr-pattern:
	/.*divisor/
---
name: arith-div-intmin-by-minusone
description:
	Check division overflow wraps around silently
category: int:32
stdin:
	echo signed:$((-2147483648 / -1))r$((-2147483648 % -1)).
	echo unsigned:$((# -2147483648 / -1))r$((# -2147483648 % -1)).
expected-stdout:
	signed:-2147483648r0.
	unsigned:0r2147483648.
---
name: arith-div-intmin-by-minusone-64
description:
	Check division overflow wraps around silently
category: int:64
stdin:
	echo signed:$((-9223372036854775808 / -1))r$((-9223372036854775808 % -1)).
	echo unsigned:$((# -9223372036854775808 / -1))r$((# -9223372036854775808 % -1)).
expected-stdout:
	signed:-9223372036854775808r0.
	unsigned:0r9223372036854775808.
---
name: arith-assop-assoc-1
description:
	Check associativity of assignment-operator operator
stdin:
	typeset -i i=1 j=2 k=3
	echo $((i += j += k))
	echo $i,$j,$k
expected-stdout:
	6
	6,5,3
---
name: arith-mandatory
description:
	Passing of this test is *mandatory* for a valid mksh executable!
category: shell:legacy-no
stdin:
	typeset -i sari=0
	typeset -Ui uari=0
	typeset -i x=0
	print -r -- $((x++)):$sari=$uari. #0
	let --sari --uari
	print -r -- $((x++)):$sari=$uari. #1
	sari=2147483647 uari=2147483647
	print -r -- $((x++)):$sari=$uari. #2
	let ++sari ++uari
	print -r -- $((x++)):$sari=$uari. #3
	let --sari --uari
	let 'sari *= 2' 'uari *= 2'
	let ++sari ++uari
	print -r -- $((x++)):$sari=$uari. #4
	let ++sari ++uari
	print -r -- $((x++)):$sari=$uari. #5
	sari=-2147483648 uari=-2147483648
	print -r -- $((x++)):$sari=$uari. #6
	let --sari --uari
	print -r -- $((x++)):$sari=$uari. #7
	(( sari = -5 >> 1 ))
	((# uari = -5 >> 1 ))
	print -r -- $((x++)):$sari=$uari. #8
	(( sari = -2 ))
	((# uari = sari ))
	print -r -- $((x++)):$sari=$uari. #9
expected-stdout:
	0:0=0.
	1:-1=4294967295.
	2:2147483647=2147483647.
	3:-2147483648=2147483648.
	4:-1=4294967295.
	5:0=0.
	6:-2147483648=2147483648.
	7:2147483647=2147483647.
	8:-3=2147483645.
	9:-2=4294967294.
---
name: arith-unsigned-1
description:
	Check if unsigned arithmetics work
category: int:32
stdin:
	# signed vs unsigned
	echo x1 $((-1)) $((#-1))
	# calculating
	typeset -i vs
	typeset -Ui vu
	vs=4123456789; vu=4123456789
	echo x2 $vs $vu
	(( vs %= 2147483647 ))
	(( vu %= 2147483647 ))
	echo x3 $vs $vu
	vs=4123456789; vu=4123456789
	(( # vs %= 2147483647 ))
	(( # vu %= 2147483647 ))
	echo x4 $vs $vu
	# make sure the calculation does not change unsigned flag
	vs=4123456789; vu=4123456789
	echo x5 $vs $vu
	# short form
	echo x6 $((# vs % 2147483647)) $((# vu % 2147483647))
	# array refs
	set -A va
	va[1975973142]=right
	va[4123456789]=wrong
	echo x7 ${va[#4123456789%2147483647]}
	# make sure multiple calculations don't interfere with each other
	let '# mca = -4 % -2' ' mcb = -4 % -2'
	echo x8 $mca $mcb
expected-stdout:
	x1 -1 4294967295
	x2 -171510507 4123456789
	x3 -171510507 4123456789
	x4 1975973142 1975973142
	x5 -171510507 4123456789
	x6 1975973142 1975973142
	x7 right
	x8 -4 0
---
name: arith-limit32-1
description:
	Check if arithmetics are 32 bit
category: int:32
stdin:
	# signed vs unsigned
	echo x1 $((-1)) $((#-1))
	# calculating
	typeset -i vs
	typeset -Ui vu
	vs=2147483647; vu=2147483647
	echo x2 $vs $vu
	let vs++ vu++
	echo x3 $vs $vu
	vs=4294967295; vu=4294967295
	echo x4 $vs $vu
	let vs++ vu++
	echo x5 $vs $vu
	let vs++ vu++
	echo x6 $vs $vu
expected-stdout:
	x1 -1 4294967295
	x2 2147483647 2147483647
	x3 -2147483648 2147483648
	x4 -1 4294967295
	x5 0 0
	x6 1 1
---
name: arith-limit64-1
description:
	Check if arithmetics are 64 bit
category: int:64
stdin:
	# signed vs unsigned
	echo x1 $((-1)) $((#-1))
	# calculating
	typeset -i vs
	typeset -Ui vu
	vs=9223372036854775807; vu=9223372036854775807
	echo x2 $vs $vu
	let vs++ vu++
	echo x3 $vs $vu
	vs=18446744073709551615; vu=18446744073709551615
	echo x4 $vs $vu
	let vs++ vu++
	echo x5 $vs $vu
	let vs++ vu++
	echo x6 $vs $vu
expected-stdout:
	x1 -1 18446744073709551615
	x2 9223372036854775807 9223372036854775807
	x3 -9223372036854775808 9223372036854775808
	x4 -1 18446744073709551615
	x5 0 0
	x6 1 1
---
name: bksl-nl-ign-1
description:
	Check that \newline is not collapsed after #
stdin:
	echo hi #there \
	echo folks
expected-stdout:
	hi
	folks
---
name: bksl-nl-ign-2
description:
	Check that \newline is not collapsed inside single quotes
stdin:
	echo 'hi \
	there'
	echo folks
expected-stdout:
	hi \
	there
	folks
---
name: bksl-nl-ign-3
description:
	Check that \newline is not collapsed inside single quotes
stdin:
	cat << \EOF
	hi \
	there
	EOF
expected-stdout:
	hi \
	there
---
name: bksl-nl-ign-4
description:
	Check interaction of aliases, single quotes and here-documents
	with backslash-newline
	(don't know what POSIX has to say about this)
stdin:
	a=2
	alias x='echo hi
	cat << "EOF"
	foo\
	bar
	some'
	x
	more\
	stuff$a
	EOF
expected-stdout:
	hi
	foo\
	bar
	some
	more\
	stuff$a
---
name: bksl-nl-ign-5
description:
	Check what happens with backslash at end of input
	(the old Bourne shell trashes them; so do we)
stdin: !
	echo `echo foo\\`bar
	echo hi\
expected-stdout:
	foobar
	hi
---
#
# Places \newline should be collapsed
#
name: bksl-nl-1
description:
	Check that \newline is collapsed before, in the middle of, and
	after words
stdin:
	 	 	\
			 echo hi\
	There, \
	folks
expected-stdout:
	hiThere, folks
---
name: bksl-nl-2
description:
	Check that \newline is collapsed in $ sequences
	(ksh93 fails this)
stdin:
	a=12
	ab=19
	echo $\
	a
	echo $a\
	b
	echo $\
	{a}
	echo ${a\
	b}
	echo ${ab\
	}
expected-stdout:
	12
	19
	12
	19
	19
---
name: bksl-nl-3
description:
	Check that \newline is collapsed in $(..) and `...` sequences
	(ksh93 fails this)
stdin:
	echo $\
	(echo foobar1)
	echo $(\
	echo foobar2)
	echo $(echo foo\
	bar3)
	echo $(echo foobar4\
	)
	echo `
	echo stuff1`
	echo `echo st\
	uff2`
expected-stdout:
	foobar1
	foobar2
	foobar3
	foobar4
	stuff1
	stuff2
---
name: bksl-nl-4
description:
	Check that \newline is collapsed in $((..)) sequences
	(ksh93 fails this)
stdin:
	echo $\
	((1+2))
	echo $(\
	(1+2+3))
	echo $((\
	1+2+3+4))
	echo $((1+\
	2+3+4+5))
	echo $((1+2+3+4+5+6)\
	)
expected-stdout:
	3
	6
	10
	15
	21
---
name: bksl-nl-5
description:
	Check that \newline is collapsed in double quoted strings
stdin:
	echo "\
	hi"
	echo "foo\
	bar"
	echo "folks\
	"
expected-stdout:
	hi
	foobar
	folks
---
name: bksl-nl-6
description:
	Check that \newline is collapsed in here document delimiters
	(ksh93 fails second part of this)
stdin:
	a=12
	cat << EO\
	F
	a=$a
	foo\
	bar
	EOF
	cat << E_O_F
	foo
	E_O_\
	F
	echo done
expected-stdout:
	a=12
	foobar
	foo
	done
---
name: bksl-nl-7
description:
	Check that \newline is collapsed in double-quoted here-document
	delimiter.
stdin:
	a=12
	cat << "EO\
	F"
	a=$a
	foo\
	bar
	EOF
	echo done
expected-stdout:
	a=$a
	foo\
	bar
	done
---
name: bksl-nl-8
description:
	Check that \newline is collapsed in various 2+ character tokens
	delimiter.
	(ksh93 fails this)
stdin:
	echo hi &\
	& echo there
	echo foo |\
	| echo bar
	cat <\
	< EOF
	stuff
	EOF
	cat <\
	<\
	- EOF
		more stuff
	EOF
	cat <<\
	EOF
	abcdef
	EOF
	echo hi >\
	> /dev/null
	echo $?
	i=1
	case $i in
	(\
	x|\
	1\
	) echo hi;\
	;
	(*) echo oops
	esac
expected-stdout:
	hi
	there
	foo
	stuff
	more stuff
	abcdef
	0
	hi
---
name: bksl-nl-9
description:
	Check that \ at the end of an alias is collapsed when followed
	by a newline
	(don't know what POSIX has to say about this)
stdin:
	alias x='echo hi\'
	x
	echo there
expected-stdout:
	hiecho there
---
name: bksl-nl-10
description:
	Check that \newline in a keyword is collapsed
stdin:
	i\
	f true; then\
	 echo pass; el\
	se echo fail; fi
expected-stdout:
	pass
---
#
# Places \newline should be collapsed (ksh extensions)
#
name: bksl-nl-ksh-1
description:
	Check that \newline is collapsed in extended globbing
	(ksh93 fails this)
stdin:
	xxx=foo
	case $xxx in
	(f*\
	(\
	o\
	)\
	) echo ok ;;
	*) echo bad
	esac
expected-stdout:
	ok
---
name: bksl-nl-ksh-2
description:
	Check that \newline is collapsed in ((...)) expressions
	(ksh93 fails this)
stdin:
	i=1
	(\
	(\
	i=i+2\
	)\
	)
	echo $i
expected-stdout:
	3
---
name: break-1
description:
	See if break breaks out of loops
stdin:
	for i in a b c; do echo $i; break; echo bad-$i; done
	echo end-1
	for i in a b c; do echo $i; break 1; echo bad-$i; done
	echo end-2
	for i in a b c; do
	    for j in x y z; do
		echo $i:$j
		break
		echo bad-$i
	    done
	    echo end-$i
	done
	echo end-3
	for i in a b c; do echo $i; eval break; echo bad-$i; done
	echo end-4
expected-stdout:
	a
	end-1
	a
	end-2
	a:x
	end-a
	b:x
	end-b
	c:x
	end-c
	end-3
	a
	end-4
---
name: break-2
description:
	See if break breaks out of nested loops
stdin:
	for i in a b c; do
	    for j in x y z; do
		echo $i:$j
		break 2
		echo bad-$i
	    done
	    echo end-$i
	done
	echo end
expected-stdout:
	a:x
	end
---
name: break-3
description:
	What if break used outside of any loops
	(ksh88,ksh93 don't print error messages here)
stdin:
	break
expected-stderr-pattern:
	/.*break.*/
---
name: break-4
description:
	What if break N used when only N-1 loops
	(ksh88,ksh93 don't print error messages here)
stdin:
	for i in a b c; do echo $i; break 2; echo bad-$i; done
	echo end
expected-stdout:
	a
	end
expected-stderr-pattern:
	/.*break.*/
---
name: break-5
description:
	Error if break argument isn't a number
stdin:
	for i in a b c; do echo $i; break abc; echo more-$i; done
	echo end
expected-stdout:
	a
expected-exit: e != 0
expected-stderr-pattern:
	/.*break.*/
---
name: continue-1
description:
	See if continue continues loops
stdin:
	for i in a b c; do echo $i; continue; echo bad-$i ; done
	echo end-1
	for i in a b c; do echo $i; continue 1; echo bad-$i; done
	echo end-2
	for i in a b c; do
	    for j in x y z; do
		echo $i:$j
		continue
		echo bad-$i-$j
	    done
	    echo end-$i
	done
	echo end-3
	for i in a b c; do echo $i; eval continue; echo bad-$i ; done
	echo end-4
expected-stdout:
	a
	b
	c
	end-1
	a
	b
	c
	end-2
	a:x
	a:y
	a:z
	end-a
	b:x
	b:y
	b:z
	end-b
	c:x
	c:y
	c:z
	end-c
	end-3
	a
	b
	c
	end-4
---
name: continue-2
description:
	See if continue breaks out of nested loops
stdin:
	for i in a b c; do
	    for j in x y z; do
		echo $i:$j
		continue 2
		echo bad-$i-$j
	    done
	    echo end-$i
	done
	echo end
expected-stdout:
	a:x
	b:x
	c:x
	end
---
name: continue-3
description:
	What if continue used outside of any loops
	(ksh88,ksh93 don't print error messages here)
stdin:
	continue
expected-stderr-pattern:
	/.*continue.*/
---
name: continue-4
description:
	What if continue N used when only N-1 loops
	(ksh88,ksh93 don't print error messages here)
stdin:
	for i in a b c; do echo $i; continue 2; echo bad-$i; done
	echo end
expected-stdout:
	a
	b
	c
	end
expected-stderr-pattern:
	/.*continue.*/
---
name: continue-5
description:
	Error if continue argument isn't a number
stdin:
	for i in a b c; do echo $i; continue abc; echo more-$i; done
	echo end
expected-stdout:
	a
expected-exit: e != 0
expected-stderr-pattern:
	/.*continue.*/
---
name: cd-history
description:
	Test someone's CD history package (uses arrays)
stdin:
	# go to known place before doing anything
	cd /
	
	alias cd=_cd
	function _cd
	{
		typeset -i cdlen i
		typeset t
	
		if [ $# -eq 0 ]
		then
			set -- $HOME
		fi
	
		if [ "$CDHISTFILE" -a -r "$CDHISTFILE" ] # if directory history exists
		then
			typeset CDHIST
			i=-1
			while read -r t			# read directory history file
			do
				CDHIST[i=i+1]=$t
			done <$CDHISTFILE
		fi
	
		if [ "${CDHIST[0]}" != "$PWD" -a "$PWD" != "" ]
		then
			_cdins				# insert $PWD into cd history
		fi
	
		cdlen=${#CDHIST[*]}			# number of elements in history
	
		case "$@" in
		-)					# cd to new dir
			if [ "$OLDPWD" = "" ] && ((cdlen>1))
			then
				'print' ${CDHIST[1]}
				'cd' ${CDHIST[1]}
				_pwd
			else
				'cd' $@
				_pwd
			fi
			;;
		-l)					# print directory list
			typeset -R3 num
			((i=cdlen))
			while (((i=i-1)>=0))
			do
				num=$i
				'print' "$num ${CDHIST[i]}"
			done
			return
			;;
		-[0-9]|-[0-9][0-9])			# cd to dir in list
			if (((i=${1#-})<cdlen))
			then
				'print' ${CDHIST[i]}
				'cd' ${CDHIST[i]}
				_pwd
			else
				'cd' $@
				_pwd
			fi
			;;
		-*)					# cd to matched dir in list
			t=${1#-}
			i=1
			while ((i<cdlen))
			do
				case ${CDHIST[i]} in
				*$t*)
					'print' ${CDHIST[i]}
					'cd' ${CDHIST[i]}
					_pwd
					break
					;;
				esac
				((i=i+1))
			done
			if ((i>=cdlen))
			then
				'cd' $@
				_pwd
			fi
			;;
		*)					# cd to new dir
			'cd' $@
			_pwd
			;;
		esac
	
		_cdins					# insert $PWD into cd history
	
		if [ "$CDHISTFILE" ]
		then
			cdlen=${#CDHIST[*]}		# number of elements in history
	
			i=0
			while ((i<cdlen))
			do
				'print' -r ${CDHIST[i]}	# update directory history
				((i=i+1))
			done >$CDHISTFILE
		fi
	}
	
	function _cdins					# insert $PWD into cd history
	{						# meant to be called only by _cd
		typeset -i i
	
		((i=0))
		while ((i<${#CDHIST[*]}))		# see if dir is already in list
		do
			if [ "${CDHIST[$i]}" = "$PWD" ]
			then
				break
			fi
			((i=i+1))
		done
	
		if ((i>22))				# limit max size of list
		then
			i=22
		fi
	
		while (((i=i-1)>=0))			# bump old dirs in list
		do
			CDHIST[i+1]=${CDHIST[i]}
		done
	
		CDHIST[0]=$PWD				# insert new directory in list
	}
	
	
	function _pwd
	{
		if [ -n "$ECD" ]
		then
			pwd 1>&6
		fi
	}
	# Start of test
	cd /tmp
	cd /bin
	cd /etc
	cd -
	cd -2
	cd -l
expected-stdout:
	/bin
	/tmp
	  3 /
	  2 /etc
	  1 /bin
	  0 /tmp
---
name: cd-pe
description:
	Check package for cd -Pe
need-pass: no
# the mv command fails on Cygwin and z/OS
# Hurd aborts the testsuite (permission denied)
# QNX does not find subdir to cd into
category: !os:cygwin,!os:gnu,!os:midipix,!os:msys,!os:nto,!os:os390,!nosymlink
file-setup: file 644 "x"
	mkdir noread noread/target noread/target/subdir
	ln -s noread link
	chmod 311 noread
	cd -P$1 .
	echo 0=$?
	bwd=$PWD
	cd -P$1 link/target
	echo 1=$?,${PWD#$bwd/}
	epwd=$($TSHELL -c pwd 2>/dev/null)
	# This unexpectedly succeeds on GNU/Linux and MidnightBSD
	#echo pwd=$?,$epwd
	# expect:	pwd=1,
	mv ../../noread ../../renamed
	cd -P$1 subdir
	echo 2=$?,${PWD#$bwd/}
	cd $bwd
	chmod 755 noread renamed 2>/dev/null
	rm -rf noread link renamed
stdin:
	export TSHELL="$__progname"
	"$__progname" x
	echo "now with -e:"
	"$__progname" x e
expected-stdout:
	0=0
	1=0,noread/target
	2=0,noread/target/subdir
	now with -e:
	0=0
	1=0,noread/target
	2=1,noread/target/subdir
---
name: env-prompt
description:
	Check that prompt not printed when processing ENV
env-setup: !ENV=./foo!
file-setup: file 644 "foo"
	XXX=_
	PS1=X
	false && echo hmmm
need-ctty: yes
arguments: !-i!
stdin:
	echo hi${XXX}there
expected-stdout:
	hi_there
expected-stderr: !
	XX
---
name: expand-ugly
description:
	Check that weird ${foo+bar} constructs are parsed correctly
stdin:
	print '#!'"$__progname"'\nfor x in "$@"; do print -r -- "$x"; done' >pfn
	print '#!'"$__progname"'\nfor x in "$@"; do print -nr -- "<$x> "; done' >pfs
	chmod +x pfn pfs
	(echo 1 ${IFS+'}'z}) 2>/dev/null || echo failed in 1
	(echo 2 "${IFS+'}'z}") 2>/dev/null || echo failed in 2
	(echo 3 "foo ${IFS+'bar} baz") 2>/dev/null || echo failed in 3
	(echo -n '4 '; ./pfn "foo ${IFS+"b   c"} baz") 2>/dev/null || echo failed in 4
	(echo -n '5 '; ./pfn "foo ${IFS+b   c} baz") 2>/dev/null || echo failed in 5
	(echo 6 ${IFS+"}"z}) 2>/dev/null || echo failed in 6
	(echo 7 "${IFS+"}"z}") 2>/dev/null || echo failed in 7
	(echo 8 "${IFS+\"}\"z}") 2>/dev/null || echo failed in 8
	(echo 9 "${IFS+\"\}\"z}") 2>/dev/null || echo failed in 9
	(echo 10 foo ${IFS+'bar} baz'}) 2>/dev/null || echo failed in 10
	(echo 11 "$(echo "${IFS+'}'z}")") 2>/dev/null || echo failed in 11
	(echo 12 "$(echo ${IFS+'}'z})") 2>/dev/null || echo failed in 12
	(echo 13 ${IFS+\}z}) 2>/dev/null || echo failed in 13
	(echo 14 "${IFS+\}z}") 2>/dev/null || echo failed in 14
	u=x; (echo -n '15 '; ./pfs "foo ${IFS+a"b$u{ {"{{\}b} c ${IFS+d{}} bar" ${IFS-e{}} baz; echo .) 2>/dev/null || echo failed in 15
	l=t; (echo 16 ${IFS+h`echo -n i ${IFS+$l}h`ere}) 2>/dev/null || echo failed in 16
	l=t; (echo 17 ${IFS+h$(echo -n i ${IFS+$l}h)ere}) 2>/dev/null || echo failed in 17
	l=t; (echo 18 "${IFS+h`echo -n i ${IFS+$l}h`ere}") 2>/dev/null || echo failed in 18
	l=t; (echo 19 "${IFS+h$(echo -n i ${IFS+$l}h)ere}") 2>/dev/null || echo failed in 19
	l=t; (echo 20 ${IFS+h`echo -n i "${IFS+$l}"h`ere}) 2>/dev/null || echo failed in 20
	l=t; (echo 21 ${IFS+h$(echo -n i "${IFS+$l}"h)ere}) 2>/dev/null || echo failed in 21
	l=t; (echo 22 "${IFS+h`echo -n i "${IFS+$l}"h`ere}") 2>/dev/null || echo failed in 22
	l=t; (echo 23 "${IFS+h$(echo -n i "${IFS+$l}"h)ere}") 2>/dev/null || echo failed in 23
	key=value; (echo -n '24 '; ./pfn "${IFS+'$key'}") 2>/dev/null || echo failed in 24
	key=value; (echo -n '25 '; ./pfn "${IFS+"'$key'"}") 2>/dev/null || echo failed in 25	# ksh93: ‚Äú'$key'‚Äù
	key=value; (echo -n '26 '; ./pfn ${IFS+'$key'}) 2>/dev/null || echo failed in 26
	key=value; (echo -n '27 '; ./pfn ${IFS+"'$key'"}) 2>/dev/null || echo failed in 27
	(echo -n '28 '; ./pfn "${IFS+"'"x ~ x'}'x"'}"x}" #') 2>/dev/null || echo failed in 28
	u=x; (echo -n '29 '; ./pfs foo ${IFS+a"b$u{ {"{ {\}b} c ${IFS+d{}} bar ${IFS-e{}} baz; echo .) 2>/dev/null || echo failed in 29
	(echo -n '30 '; ./pfs ${IFS+foo 'b\
	ar' baz}; echo .) 2>/dev/null || (echo failed in 30; echo failed in 31)
	(echo -n '32 '; ./pfs ${IFS+foo "b\
	ar" baz}; echo .) 2>/dev/null || echo failed in 32
	(echo -n '33 '; ./pfs "${IFS+foo 'b\
	ar' baz}"; echo .) 2>/dev/null || echo failed in 33
	(echo -n '34 '; ./pfs "${IFS+foo "b\
	ar" baz}"; echo .) 2>/dev/null || echo failed in 34
	(echo -n '35 '; ./pfs ${v=a\ b} x ${v=c\ d}; echo .) 2>/dev/null || echo failed in 35
	(echo -n '36 '; ./pfs "${v=a\ b}" x "${v=c\ d}"; echo .) 2>/dev/null || echo failed in 36
	(echo -n '37 '; ./pfs ${v-a\ b} x ${v-c\ d}; echo .) 2>/dev/null || echo failed in 37
	(echo 38 ${IFS+x'a'y} / "${IFS+x'a'y}" .) 2>/dev/null || echo failed in 38
	foo="x'a'y"; (echo 39 ${foo%*'a'*} / "${foo%*'a'*}" .) 2>/dev/null || echo failed in 39
	foo="a b c"; (echo -n '40 '; ./pfs "${foo#a}"; echo .) 2>/dev/null || echo failed in 40
	(foo() { return 100; }; foo; echo 41 ${#+${#:+${#?}}\ \}\}\}}) 2>/dev/null || echo failed in 41
expected-stdout:
	1 }z
	2 ''z}
	3 foo 'bar baz
	4 foo b   c baz
	5 foo b   c baz
	6 }z
	7 }z
	8 ""z}
	9 "}"z
	10 foo bar} baz
	11 ''z}
	12 }z
	13 }z
	14 }z
	15 <foo abx{ {{{}b c d{} bar> <}> <baz> .
	16 hi there
	17 hi there
	18 hi there
	19 hi there
	20 hi there
	21 hi there
	22 hi there
	23 hi there
	24 'value'
	25 'value'
	26 $key
	27 'value'
	28 'x ~ x''x}"x}" #
	29 <foo> <abx{ {{> <{}b> <c> <d{}> <bar> <}> <baz> .
	30 <foo> <b\
	ar> <baz> .
	32 <foo> <bar> <baz> .
	33 <foo 'bar' baz> .
	34 <foo bar baz> .
	35 <a> <b> <x> <a> <b> .
	36 <a\ b> <x> <a\ b> .
	37 <a b> <x> <c d> .
	38 xay / x'a'y .
	39 x' / x' .
	40 < b c> .
	41 3 }}}
---
name: expand-unglob-dblq
description:
	Check that regular "${foo+bar}" constructs are parsed correctly
stdin:
	u=x
	tl_norm() {
		v=$2
		test x"$v" = x"-" && unset v
		(echo "$1 plus norm foo ${v+'bar'} baz")
		(echo "$1 dash norm foo ${v-'bar'} baz")
		(echo "$1 eqal norm foo ${v='bar'} baz")
		(echo "$1 qstn norm foo ${v?'bar'} baz") 2>/dev/null || \
		    echo "$1 qstn norm -> error"
		(echo "$1 PLUS norm foo ${v:+'bar'} baz")
		(echo "$1 DASH norm foo ${v:-'bar'} baz")
		(echo "$1 EQAL norm foo ${v:='bar'} baz")
		(echo "$1 QSTN norm foo ${v:?'bar'} baz") 2>/dev/null || \
		    echo "$1 QSTN norm -> error"
	}
	tl_paren() {
		v=$2
		test x"$v" = x"-" && unset v
		(echo "$1 plus parn foo ${v+(bar)} baz")
		(echo "$1 dash parn foo ${v-(bar)} baz")
		(echo "$1 eqal parn foo ${v=(bar)} baz")
		(echo "$1 qstn parn foo ${v?(bar)} baz") 2>/dev/null || \
		    echo "$1 qstn parn -> error"
		(echo "$1 PLUS parn foo ${v:+(bar)} baz")
		(echo "$1 DASH parn foo ${v:-(bar)} baz")
		(echo "$1 EQAL parn foo ${v:=(bar)} baz")
		(echo "$1 QSTN parn foo ${v:?(bar)} baz") 2>/dev/null || \
		    echo "$1 QSTN parn -> error"
	}
	tl_brace() {
		v=$2
		test x"$v" = x"-" && unset v
		(echo "$1 plus brac foo ${v+a$u{{{\}b} c ${v+d{}} baz")
		(echo "$1 dash brac foo ${v-a$u{{{\}b} c ${v-d{}} baz")
		(echo "$1 eqal brac foo ${v=a$u{{{\}b} c ${v=d{}} baz")
		(echo "$1 qstn brac foo ${v?a$u{{{\}b} c ${v?d{}} baz") 2>/dev/null || \
		    echo "$1 qstn brac -> error"
		(echo "$1 PLUS brac foo ${v:+a$u{{{\}b} c ${v:+d{}} baz")
		(echo "$1 DASH brac foo ${v:-a$u{{{\}b} c ${v:-d{}} baz")
		(echo "$1 EQAL brac foo ${v:=a$u{{{\}b} c ${v:=d{}} baz")
		(echo "$1 QSTN brac foo ${v:?a$u{{{\}b} c ${v:?d{}} baz") 2>/dev/null || \
		    echo "$1 QSTN brac -> error"
	}
	: '}}}' '}}}' '}}}' '}}}' '}}}' '}}}' '}}}' '}}}'
	tl_norm 1 -
	tl_norm 2 ''
	tl_norm 3 x
	tl_paren 4 -
	tl_paren 5 ''
	tl_paren 6 x
	tl_brace 7 -
	tl_brace 8 ''
	tl_brace 9 x
expected-stdout:
	1 plus norm foo  baz
	1 dash norm foo 'bar' baz
	1 eqal norm foo 'bar' baz
	1 qstn norm -> error
	1 PLUS norm foo  baz
	1 DASH norm foo 'bar' baz
	1 EQAL norm foo 'bar' baz
	1 QSTN norm -> error
	2 plus norm foo 'bar' baz
	2 dash norm foo  baz
	2 eqal norm foo  baz
	2 qstn norm foo  baz
	2 PLUS norm foo  baz
	2 DASH norm foo 'bar' baz
	2 EQAL norm foo 'bar' baz
	2 QSTN norm -> error
	3 plus norm foo 'bar' baz
	3 dash norm foo x baz
	3 eqal norm foo x baz
	3 qstn norm foo x baz
	3 PLUS norm foo 'bar' baz
	3 DASH norm foo x baz
	3 EQAL norm foo x baz
	3 QSTN norm foo x baz
	4 plus parn foo  baz
	4 dash parn foo (bar) baz
	4 eqal parn foo (bar) baz
	4 qstn parn -> error
	4 PLUS parn foo  baz
	4 DASH parn foo (bar) baz
	4 EQAL parn foo (bar) baz
	4 QSTN parn -> error
	5 plus parn foo (bar) baz
	5 dash parn foo  baz
	5 eqal parn foo  baz
	5 qstn parn foo  baz
	5 PLUS parn foo  baz
	5 DASH parn foo (bar) baz
	5 EQAL parn foo (bar) baz
	5 QSTN parn -> error
	6 plus parn foo (bar) baz
	6 dash parn foo x baz
	6 eqal parn foo x baz
	6 qstn parn foo x baz
	6 PLUS parn foo (bar) baz
	6 DASH parn foo x baz
	6 EQAL parn foo x baz
	6 QSTN parn foo x baz
	7 plus brac foo  c } baz
	7 dash brac foo ax{{{}b c d{} baz
	7 eqal brac foo ax{{{}b c ax{{{}b} baz
	7 qstn brac -> error
	7 PLUS brac foo  c } baz
	7 DASH brac foo ax{{{}b c d{} baz
	7 EQAL brac foo ax{{{}b c ax{{{}b} baz
	7 QSTN brac -> error
	8 plus brac foo ax{{{}b c d{} baz
	8 dash brac foo  c } baz
	8 eqal brac foo  c } baz
	8 qstn brac foo  c } baz
	8 PLUS brac foo  c } baz
	8 DASH brac foo ax{{{}b c d{} baz
	8 EQAL brac foo ax{{{}b c ax{{{}b} baz
	8 QSTN brac -> error
	9 plus brac foo ax{{{}b c d{} baz
	9 dash brac foo x c x} baz
	9 eqal brac foo x c x} baz
	9 qstn brac foo x c x} baz
	9 PLUS brac foo ax{{{}b c d{} baz
	9 DASH brac foo x c x} baz
	9 EQAL brac foo x c x} baz
	9 QSTN brac foo x c x} baz
---
name: expand-unglob-unq
description:
	Check that regular ${foo+bar} constructs are parsed correctly
stdin:
	u=x
	tl_norm() {
		v=$2
		test x"$v" = x"-" && unset v
		(echo $1 plus norm foo ${v+'bar'} baz)
		(echo $1 dash norm foo ${v-'bar'} baz)
		(echo $1 eqal norm foo ${v='bar'} baz)
		(echo $1 qstn norm foo ${v?'bar'} baz) 2>/dev/null || \
		    echo "$1 qstn norm -> error"
		(echo $1 PLUS norm foo ${v:+'bar'} baz)
		(echo $1 DASH norm foo ${v:-'bar'} baz)
		(echo $1 EQAL norm foo ${v:='bar'} baz)
		(echo $1 QSTN norm foo ${v:?'bar'} baz) 2>/dev/null || \
		    echo "$1 QSTN norm -> error"
	}
	tl_paren() {
		v=$2
		test x"$v" = x"-" && unset v
		(echo $1 plus parn foo ${v+\(bar')'} baz)
		(echo $1 dash parn foo ${v-\(bar')'} baz)
		(echo $1 eqal parn foo ${v=\(bar')'} baz)
		(echo $1 qstn parn foo ${v?\(bar')'} baz) 2>/dev/null || \
		    echo "$1 qstn parn -> error"
		(echo $1 PLUS parn foo ${v:+\(bar')'} baz)
		(echo $1 DASH parn foo ${v:-\(bar')'} baz)
		(echo $1 EQAL parn foo ${v:=\(bar')'} baz)
		(echo $1 QSTN parn foo ${v:?\(bar')'} baz) 2>/dev/null || \
		    echo "$1 QSTN parn -> error"
	}
	tl_brace() {
		v=$2
		test x"$v" = x"-" && unset v
		(echo $1 plus brac foo ${v+a$u{{{\}b} c ${v+d{}} baz)
		(echo $1 dash brac foo ${v-a$u{{{\}b} c ${v-d{}} baz)
		(echo $1 eqal brac foo ${v=a$u{{{\}b} c ${v=d{}} baz)
		(echo $1 qstn brac foo ${v?a$u{{{\}b} c ${v?d{}} baz) 2>/dev/null || \
		    echo "$1 qstn brac -> error"
		(echo $1 PLUS brac foo ${v:+a$u{{{\}b} c ${v:+d{}} baz)
		(echo $1 DASH brac foo ${v:-a$u{{{\}b} c ${v:-d{}} baz)
		(echo $1 EQAL brac foo ${v:=a$u{{{\}b} c ${v:=d{}} baz)
		(echo $1 QSTN brac foo ${v:?a$u{{{\}b} c ${v:?d{}} baz) 2>/dev/null || \
		    echo "$1 QSTN brac -> error"
	}
	: '}}}' '}}}' '}}}' '}}}' '}}}' '}}}' '}}}' '}}}'
	tl_norm 1 -
	tl_norm 2 ''
	tl_norm 3 x
	tl_paren 4 -
	tl_paren 5 ''
	tl_paren 6 x
	tl_brace 7 -
	tl_brace 8 ''
	tl_brace 9 x
expected-stdout:
	1 plus norm foo baz
	1 dash norm foo bar baz
	1 eqal norm foo bar baz
	1 qstn norm -> error
	1 PLUS norm foo baz
	1 DASH norm foo bar baz
	1 EQAL norm foo bar baz
	1 QSTN norm -> error
	2 plus norm foo bar baz
	2 dash norm foo baz
	2 eqal norm foo baz
	2 qstn norm foo baz
	2 PLUS norm foo baz
	2 DASH norm foo bar baz
	2 EQAL norm foo bar baz
	2 QSTN norm -> error
	3 plus norm foo bar baz
	3 dash norm foo x baz
	3 eqal norm foo x baz
	3 qstn norm foo x baz
	3 PLUS norm foo bar baz
	3 DASH norm foo x baz
	3 EQAL norm foo x baz
	3 QSTN norm foo x baz
	4 plus parn foo baz
	4 dash parn foo (bar) baz
	4 eqal parn foo (bar) baz
	4 qstn parn -> error
	4 PLUS parn foo baz
	4 DASH parn foo (bar) baz
	4 EQAL parn foo (bar) baz
	4 QSTN parn -> error
	5 plus parn foo (bar) baz
	5 dash parn foo baz
	5 eqal parn foo baz
	5 qstn parn foo baz
	5 PLUS parn foo baz
	5 DASH parn foo (bar) baz
	5 EQAL parn foo (bar) baz
	5 QSTN parn -> error
	6 plus parn foo (bar) baz
	6 dash parn foo x baz
	6 eqal parn foo x baz
	6 qstn parn foo x baz
	6 PLUS parn foo (bar) baz
	6 DASH parn foo x baz
	6 EQAL parn foo x baz
	6 QSTN parn foo x baz
	7 plus brac foo c } baz
	7 dash brac foo ax{{{}b c d{} baz
	7 eqal brac foo ax{{{}b c ax{{{}b} baz
	7 qstn brac -> error
	7 PLUS brac foo c } baz
	7 DASH brac foo ax{{{}b c d{} baz
	7 EQAL brac foo ax{{{}b c ax{{{}b} baz
	7 QSTN brac -> error
	8 plus brac foo ax{{{}b c d{} baz
	8 dash brac foo c } baz
	8 eqal brac foo c } baz
	8 qstn brac foo c } baz
	8 PLUS brac foo c } baz
	8 DASH brac foo ax{{{}b c d{} baz
	8 EQAL brac foo ax{{{}b c ax{{{}b} baz
	8 QSTN brac -> error
	9 plus brac foo ax{{{}b c d{} baz
	9 dash brac foo x c x} baz
	9 eqal brac foo x c x} baz
	9 qstn brac foo x c x} baz
	9 PLUS brac foo ax{{{}b c d{} baz
	9 DASH brac foo x c x} baz
	9 EQAL brac foo x c x} baz
	9 QSTN brac foo x c x} baz
---
name: expand-threecolons-dblq
description:
	Check for a particular thing that used to segfault
stdin:
	TEST=1234
	echo "${TEST:1:2:3}"
	echo $? but still living
expected-stderr-pattern:
	/bad substitution/
expected-exit: 1
---
name: expand-threecolons-unq
description:
	Check for a particular thing that used to not error out
stdin:
	TEST=1234
	echo ${TEST:1:2:3}
	echo $? but still living
expected-stderr-pattern:
	/bad substitution/
expected-exit: 1
---
name: expand-weird-1
description:
	Check corner cases of trim expansion vs. $# vs. ${#var} vs. ${var?}
stdin:
	set 1 2 3 4 5 6 7 8 9 10 11
	echo ${#}	# value of $#
	echo ${##}	# length of $#
	echo ${##1}	# $# trimmed 1
	set 1 2 3 4 5 6 7 8 9 10 11 12
	echo ${##1}
	(exit 0)
	echo $? = ${#?} .
	(exit 111)
	echo $? = ${#?} .
expected-stdout:
	11
	2
	1
	2
	0 = 1 .
	111 = 3 .
---
name: expand-weird-2
description:
	Check more substitution and extension corner cases
stdin:
	:& set -C; pid=$$; sub=$!; flg=$-; set -- i; exec 3>x.tmp
	#echo "D: !=$! #=$# \$=$$ -=$- ?=$?"
	echo >&3 3 = s^${!-word} , ${#-word} , p^${$-word} , f^${--word} , ${?-word} .
	echo >&3 4 = ${!+word} , ${#+word} , ${$+word} , ${-+word} , ${?+word} .
	echo >&3 5 = s^${!=word} , ${#=word} , p^${$=word} , f^${-=word} , ${?=word} .
	echo >&3 6 = s^${!?word} , ${#?word} , p^${$?word} , f^${-?word} , ${??word} .
	echo >&3 7 = sl^${#!} , ${##} , pl^${#$} , fl^${#-} , ${#?} .
	echo >&3 8 = sw^${%!} , ${%#} , pw^${%$} , fw^${%-} , ${%?} .
	echo >&3 9 = ${!!} , s^${!#} , ${!$} , s^${!-} , s^${!?} .
	echo >&3 10 = s^${!#pattern} , ${##pattern} , p^${$#pattern} , f^${-#pattern} , ${?#pattern} .
	echo >&3 11 = s^${!%pattern} , ${#%pattern} , p^${$%pattern} , f^${-%pattern} , ${?%pattern} .
	echo >&3 12 = $# : ${##} , ${##1} .
	set --
	echo >&3 14 = $# : ${##} , ${##1} .
	set -- 1 2 3 4 5
	echo >&3 16 = $# : ${##} , ${##1} .
	set -- 1 2 3 4 5 6 7 8 9 a b c d e
	echo >&3 18 = $# : ${##} , ${##1} .
	exec 3>&-
	<x.tmp sed \
	    -e "s/ pl^${#pid} / PID /g" -e "s/ sl^${#sub} / SUB /g" -e "s/ fl^${#flg} / FLG /g" \
	    -e "s/ pw^${%pid} / PID /g" -e "s/ sw^${%sub} / SUB /g" -e "s/ fw^${%flg} / FLG /g" \
	    -e "s/ p^$pid / PID /g" -e "s/ s^$sub / SUB /g" -e "s/ f^$flg / FLG /g"
expected-stdout:
	3 = SUB , 1 , PID , FLG , 0 .
	4 = word , word , word , word , word .
	5 = SUB , 1 , PID , FLG , 0 .
	6 = SUB , 1 , PID , FLG , 0 .
	7 = SUB , 1 , PID , FLG , 1 .
	8 = SUB , 1 , PID , FLG , 1 .
	9 = ! , SUB , $ , SUB , SUB .
	10 = SUB , 1 , PID , FLG , 0 .
	11 = SUB , 1 , PID , FLG , 0 .
	12 = 1 : 1 , .
	14 = 0 : 1 , 0 .
	16 = 5 : 1 , 5 .
	18 = 14 : 2 , 4 .
---
name: expand-weird-3
description:
	Check that trimming works with positional parameters (Debian #48453)
stdin:
	A=9999-02
	B=9999
	echo 1=${A#$B?}.
	set -- $A $B
	echo 2=${1#$2?}.
expected-stdout:
	1=02.
	2=02.
---
name: expand-weird-4
description:
	Check that tilde expansion is enabled in ${x#~}
	and cases that are modelled after it (${x/~/~})
stdin:
	HOME=/etc
	a="~/x"
	echo "<${a#~}> <${a#\~}> <${b:-~}> <${b:-\~}> <${c:=~}><$c> <${a/~}> <${a/x/~}> <${a/x/\~}>"
expected-stdout:
	<~/x> </x> <~> <\~> <~><~> <~/x> <~//etc> <~/~>
---
name: expand-bang-1
description:
	Check corner case of ${!?} with ! being var vs. op
stdin:
	echo ${!?}
expected-exit: 1
expected-stderr-pattern: /not set/
---
name: expand-bang-2
description:
	Check corner case of ${!var} vs. ${var op} with var=!
stdin:
	echo 1 $! .
	echo 2 ${!#} .
	echo 3 ${!#[0-9]} .
	echo 4 ${!-foo} .
	# get an at least three-digit bg pid
	while :; do
		:&
		x=$!
		if [[ $x != +([0-9]) ]]; then
			echo >&2 "cannot test, pid '$x' not numeric"
			echo >&2 report this with as many details as possible
			exit 1
		fi
		[[ $x = [0-9][0-9][0-9]* ]] && break
	done
	y=${x#?}
	t=$!; [[ $t = $x ]]; echo 5 $? .
	t=${!#}; [[ $t = $x ]]; echo 6 $? .
	t=${!#[0-9]}; [[ $t = $y ]]; echo 7 $? .
	t=${!-foo}; [[ $t = $x ]]; echo 8 $? .
	t=${!?bar}; [[ $t = $x ]]; echo 9 $? .
expected-stdout:
	1 .
	2 .
	3 .
	4 foo .
	5 0 .
	6 0 .
	7 0 .
	8 0 .
	9 0 .
---
name: expand-number-1
description:
	Check that positional arguments do not overflow
stdin:
	echo "1 ${12345678901234567890} ."
expected-stdout:
	1  .
---
name: expand-slashes-1
description:
	Check that side effects in substring replacement are handled correctly
stdin:
	foo=n1n1n1n2n3
	i=2
	n=1
	echo 1 ${foo//n$((n++))/[$((++i))]} .
	echo 2 $n , $i .
expected-stdout:
	1 [3][3][3]n2n3 .
	2 2 , 3 .
---
name: expand-slashes-2
description:
	Check that side effects in substring replacement are handled correctly
stdin:
	foo=n1n1n1n2n3
	i=2
	n=1
	echo 1 ${foo@/n$((n++))/[$((++i))]} .
	echo 2 $n , $i .
expected-stdout:
	1 [3]n1n1[4][5] .
	2 5 , 5 .
---
name: expand-slashes-3
description:
	Check that we can access the replaced string
stdin:
	foo=n1n1n1n2n3
	echo 1 ${foo@/n[12]/[$KSH_MATCH]} .
expected-stdout:
	1 [n1][n1][n1][n2]n3 .
---
name: eglob-bad-1
description:
	Check that globbing isn't done when glob has syntax error
category: !os:cygwin,!os:midipix,!os:msys,!os:os2
file-setup: file 644 "@(a[b|)c]foo"
stdin:
	echo @(a[b|)c]*
expected-stdout:
	@(a[b|)c]*
---
name: eglob-bad-2
description:
	Check that globbing isn't done when glob has syntax error
	(AT&T ksh fails this test)
file-setup: file 644 "abcx"
file-setup: file 644 "abcz"
file-setup: file 644 "bbc"
stdin:
	echo [a*(]*)z
expected-stdout:
	[a*(]*)z
---
name: eglob-infinite-plus
description:
	Check that shell doesn't go into infinite loop expanding +(...)
	expressions.
file-setup: file 644 "abc"
time-limit: 3
stdin:
	echo +()c
	echo +()x
	echo +(*)c
	echo +(*)x
expected-stdout:
	+()c
	+()x
	abc
	+(*)x
---
name: eglob-subst-1
description:
	Check that eglobbing isn't done on substitution results
file-setup: file 644 "abc"
stdin:
	x='@(*)'
	echo $x
expected-stdout:
	@(*)
---
name: eglob-nomatch-1
description:
	Check that the pattern doesn't match
stdin:
	echo 1: no-file+(a|b)stuff
	echo 2: no-file+(a*(c)|b)stuff
	echo 3: no-file+((((c)))|b)stuff
expected-stdout:
	1: no-file+(a|b)stuff
	2: no-file+(a*(c)|b)stuff
	3: no-file+((((c)))|b)stuff
---
name: eglob-match-1
description:
	Check that the pattern matches correctly
file-setup: file 644 "abd"
file-setup: file 644 "acd"
file-setup: file 644 "abac"
stdin:
	echo 1: a+(b|c)d
	echo 2: a!(@(b|B))d
	echo 3: *(a(b|c))		# (...|...) can be used within X(..)
	echo 4: a[b*(foo|bar)]d		# patterns not special inside [...]
expected-stdout:
	1: abd acd
	2: acd
	3: abac
	4: abd
---
name: eglob-case-1
description:
	Simple negation tests
stdin:
	case foo in !(foo|bar)) echo yes;; *) echo no;; esac
	case bar in !(foo|bar)) echo yes;; *) echo no;; esac
expected-stdout:
	no
	no
---
name: eglob-case-2
description:
	Simple kleene tests
stdin:
	case foo in *(a|b[)) echo yes;; *) echo no;; esac
	case foo in *(a|b[)|f*) echo yes;; *) echo no;; esac
	case '*(a|b[)' in *(a|b[)) echo yes;; *) echo no;; esac
	case 'aab[b[ab[a' in *(a|b[)) echo yes;; *) echo no;; esac
expected-stdout:
	no
	yes
	no
	yes
---
name: eglob-trim-1
description:
	Eglobbing in trim expressions...
	(AT&T ksh fails this - docs say # matches shortest string, ## matches
	longest...)
stdin:
	x=abcdef
	echo 1: ${x#a|abc}
	echo 2: ${x##a|abc}
	echo 3: ${x%def|f}
	echo 4: ${x%%f|def}
expected-stdout:
	1: bcdef
	2: def
	3: abcde
	4: abc
---
name: eglob-trim-2
description:
	Check eglobbing works in trims...
stdin:
	x=abcdef
	echo 1: ${x#*(a|b)cd}
	echo 2: "${x#*(a|b)cd}"
	echo 3: ${x#"*(a|b)cd"}
	echo 4: ${x#a(b|c)}
expected-stdout:
	1: ef
	2: ef
	3: abcdef
	4: cdef
---
name: eglob-trim-3
description:
	Check eglobbing works in trims, for Korn Shell
	Ensure eglobbing does not work for reduced-feature /bin/sh
stdin:
	set +o sh
	x=foobar
	y=foobaz
	z=fooba\?
	echo "<${x%bar|baz},${y%bar|baz},${z%\?}>"
	echo "<${x%ba(r|z)},${y%ba(r|z)}>"
	set -o sh
	echo "<${x%bar|baz},${y%bar|baz},${z%\?}>"
	z='foo(bar'
	echo "<${z%(*}>"
expected-stdout:
	<foo,foo,fooba>
	<foo,foo>
	<foobar,foobaz,fooba>
	<foo>
---
name: eglob-substrpl-1
description:
	Check eglobbing works in substs... and they work at all
stdin:
	[[ -n $BASH_VERSION ]] && shopt -s extglob
	x=1222321_ab/cde_b/c_1221
	y=xyz
	echo 1: ${x/2} . ${x/}
	echo 2: ${x//2}
	echo 3: ${x/+(2)}
	echo 4: ${x//+(2)}
	echo 5: ${x/2/4}
	echo 6: ${x//2/4}
	echo 7: ${x/+(2)/4}
	echo 8: ${x//+(2)/4}
	echo 9: ${x/b/c/e/f}
	echo 10: ${x/b\/c/e/f}
	echo 11: ${x/b\/c/e\/f}
	echo 12: ${x/b\/c/e\\/f}
	echo 13: ${x/b\\/c/e\\/f}
	echo 14: ${x//b/c/e/f}
	echo 15: ${x//b\/c/e/f}
	echo 16: ${x//b\/c/e\/f}
	echo 17: ${x//b\/c/e\\/f}
	echo 18: ${x//b\\/c/e\\/f}
	echo 19: ${x/b\/*\/c/x}
	echo 20: ${x/\//.}
	echo 21: ${x//\//.}
	echo 22: ${x///.}
	echo 23: ${x/#1/9}
	echo 24: ${x//#1/9}
	echo 25: ${x/%1/9}
	echo 26: ${x//%1/9}
	echo 27: ${x//\%1/9}
	echo 28: ${x//\\%1/9}
	echo 29: ${x//\a/9}
	echo 30: ${x//\\a/9}
	echo 31: ${x/2/$y}
expected-stdout:
	1: 122321_ab/cde_b/c_1221 . 1222321_ab/cde_b/c_1221
	2: 131_ab/cde_b/c_11
	3: 1321_ab/cde_b/c_1221
	4: 131_ab/cde_b/c_11
	5: 1422321_ab/cde_b/c_1221
	6: 1444341_ab/cde_b/c_1441
	7: 14321_ab/cde_b/c_1221
	8: 14341_ab/cde_b/c_141
	9: 1222321_ac/e/f/cde_b/c_1221
	10: 1222321_ae/fde_b/c_1221
	11: 1222321_ae/fde_b/c_1221
	12: 1222321_ae\/fde_b/c_1221
	13: 1222321_ab/cde_b/c_1221
	14: 1222321_ac/e/f/cde_c/e/f/c_1221
	15: 1222321_ae/fde_e/f_1221
	16: 1222321_ae/fde_e/f_1221
	17: 1222321_ae\/fde_e\/f_1221
	18: 1222321_ab/cde_b/c_1221
	19: 1222321_ax_1221
	20: 1222321_ab.cde_b/c_1221
	21: 1222321_ab.cde_b.c_1221
	22: 1222321_ab/cde_b/c_1221
	23: 9222321_ab/cde_b/c_1221
	24: 1222321_ab/cde_b/c_1221
	25: 1222321_ab/cde_b/c_1229
	26: 1222321_ab/cde_b/c_1221
	27: 1222321_ab/cde_b/c_1221
	28: 1222321_ab/cde_b/c_1221
	29: 1222321_9b/cde_b/c_1221
	30: 1222321_ab/cde_b/c_1221
	31: 1xyz22321_ab/cde_b/c_1221
---
name: eglob-substrpl-2
description:
	Check anchored substring replacement works, corner cases
stdin:
	foo=123
	echo 1: ${foo/#/x}
	echo 2: ${foo/%/x}
	echo 3: ${foo/#/}
	echo 4: ${foo/#}
	echo 5: ${foo/%/}
	echo 6: ${foo/%}
expected-stdout:
	1: x123
	2: 123x
	3: 123
	4: 123
	5: 123
	6: 123
---
name: eglob-substrpl-3a
description:
	Check substring replacement works with variables and slashes, too
stdin:
	HOME=/etc
	pfx=/home/user
	wd=/home/user/tmp
	echo "${wd/#$pfx/~}"
	echo "${wd/#\$pfx/~}"
	echo "${wd/#"$pfx"/~}"
	echo "${wd/#'$pfx'/~}"
	echo "${wd/#"\$pfx"/~}"
	echo "${wd/#'\$pfx'/~}"
expected-stdout:
	/etc/tmp
	/home/user/tmp
	/etc/tmp
	/home/user/tmp
	/home/user/tmp
	/home/user/tmp
---
name: eglob-substrpl-3b
description:
	More of this, bash fails it (bash4 passes)
stdin:
	HOME=/etc
	pfx=/home/user
	wd=/home/user/tmp
	echo "${wd/#$(echo /home/user)/~}"
	echo "${wd/#"$(echo /home/user)"/~}"
	echo "${wd/#'$(echo /home/user)'/~}"
expected-stdout:
	/etc/tmp
	/etc/tmp
	/home/user/tmp
---
name: eglob-substrpl-3c
description:
	Even more weird cases
stdin:
	HOME=/etc
	pfx=/home/user
	wd='$pfx/tmp'
	echo 1: ${wd/#$pfx/~}
	echo 2: ${wd/#\$pfx/~}
	echo 3: ${wd/#"$pfx"/~}
	echo 4: ${wd/#'$pfx'/~}
	echo 5: ${wd/#"\$pfx"/~}
	echo 6: ${wd/#'\$pfx'/~}
	ts='a/ba/b$tp$tp_a/b$tp_*(a/b)_*($tp)'
	tp=a/b
	tr=c/d
	[[ -n $BASH_VERSION ]] && shopt -s extglob
	echo 7: ${ts/a\/b/$tr}
	echo 8: ${ts/a\/b/\$tr}
	echo 9: ${ts/$tp/$tr}
	echo 10: ${ts/\$tp/$tr}
	echo 11: ${ts/\\$tp/$tr}
	echo 12: ${ts/$tp/c/d}
	echo 13: ${ts/$tp/c\/d}
	echo 14: ${ts/$tp/c\\/d}
	echo 15: ${ts/+(a\/b)/$tr}
	echo 16: ${ts/+(a\/b)/\$tr}
	echo 17: ${ts/+($tp)/$tr}
	echo 18: ${ts/+($tp)/c/d}
	echo 19: ${ts/+($tp)/c\/d}
	echo 20: ${ts//a\/b/$tr}
	echo 21: ${ts//a\/b/\$tr}
	echo 22: ${ts//$tp/$tr}
	echo 23: ${ts//$tp/c/d}
	echo 24: ${ts//$tp/c\/d}
	echo 25: ${ts//+(a\/b)/$tr}
	echo 26: ${ts//+(a\/b)/\$tr}
	echo 27: ${ts//+($tp)/$tr}
	echo 28: ${ts//+($tp)/c/d}
	echo 29: ${ts//+($tp)/c\/d}
	tp="+($tp)"
	echo 30: ${ts/$tp/$tr}
	echo 31: ${ts//$tp/$tr}
expected-stdout:
	1: $pfx/tmp
	2: /etc/tmp
	3: $pfx/tmp
	4: /etc/tmp
	5: /etc/tmp
	6: $pfx/tmp
	7: c/da/b$tp$tp_a/b$tp_*(a/b)_*($tp)
	8: $tra/b$tp$tp_a/b$tp_*(a/b)_*($tp)
	9: c/da/b$tp$tp_a/b$tp_*(a/b)_*($tp)
	10: a/ba/bc/d$tp_a/b$tp_*(a/b)_*($tp)
	11: a/ba/b$tp$tp_a/b$tp_*(a/b)_*($tp)
	12: c/da/b$tp$tp_a/b$tp_*(a/b)_*($tp)
	13: c/da/b$tp$tp_a/b$tp_*(a/b)_*($tp)
	14: c\/da/b$tp$tp_a/b$tp_*(a/b)_*($tp)
	15: c/d$tp$tp_a/b$tp_*(a/b)_*($tp)
	16: $tr$tp$tp_a/b$tp_*(a/b)_*($tp)
	17: c/d$tp$tp_a/b$tp_*(a/b)_*($tp)
	18: c/d$tp$tp_a/b$tp_*(a/b)_*($tp)
	19: c/d$tp$tp_a/b$tp_*(a/b)_*($tp)
	20: c/dc/d$tp$tp_c/d$tp_*(c/d)_*($tp)
	21: $tr$tr$tp$tp_$tr$tp_*($tr)_*($tp)
	22: c/dc/d$tp$tp_c/d$tp_*(c/d)_*($tp)
	23: c/dc/d$tp$tp_c/d$tp_*(c/d)_*($tp)
	24: c/dc/d$tp$tp_c/d$tp_*(c/d)_*($tp)
	25: c/d$tp$tp_c/d$tp_*(c/d)_*($tp)
	26: $tr$tp$tp_$tr$tp_*($tr)_*($tp)
	27: c/d$tp$tp_c/d$tp_*(c/d)_*($tp)
	28: c/d$tp$tp_c/d$tp_*(c/d)_*($tp)
	29: c/d$tp$tp_c/d$tp_*(c/d)_*($tp)
	30: a/ba/b$tp$tp_a/b$tp_*(a/b)_*($tp)
	31: a/ba/b$tp$tp_a/b$tp_*(a/b)_*($tp)
#	This is what GNU bash does:
#	30: c/d$tp$tp_a/b$tp_*(a/b)_*($tp)
#	31: c/d$tp$tp_c/d$tp_*(c/d)_*($tp)
---
name: eglob-utf8-1
description:
	UTF-8 mode differences for eglobbing
category: !shell:ebcdic-yes
stdin:
	s=bl√∂d
	set +U
	print 1: ${s%???} .
	print 2: ${s/b???d/x} .
	set -U
	print 3: ${s%???} .
	print 4: ${s/b??d/x} .
	x=n√∂
	print 5: ${x%?} ${x%%?} .
	x=√§h
	print 6: ${x#?} ${x##?} .
	x=ÅÇ
	print 7: ${x%?} ${x%%?} .
	x=m√§Ä
	print 8: ${x%?} ${x%%?} .
	x=‰Ωï
	print 9: ${x%?} ${x%%?} .
expected-stdout:
	1: bl .
	2: x .
	3: b .
	4: x .
	5: n n .
	6: h h .
	7: Å Å .
	8: m√§ m√§ .
	9: .
---
name: glob-bad-1
description:
	Check that [ matches itself if it's not a valid bracket expr
	but does not prevent globbing, while backslash-escaping does
file-setup: dir 755 "[x"
file-setup: file 644 "[x/foo"
stdin:
	echo [*
	echo *[x
	echo [x/*
	:>'ab[x'
	:>'a[a-z][x'
	echo a[a-z][*
	echo a[a-z]*
	echo a[a\-z]*
expected-stdout:
	[x
	[x
	[x/foo
	ab[x
	ab[x
	a[a-z]*
---
name: glob-bad-2
description:
	Check that symbolic links aren't stat()'d
# breaks on Dell UNIX 4.0 R2.2 (SVR4) where unlink also fails
# breaks on FreeMiNT (cannot unlink dangling symlinks)
# breaks on MSYS, OS/2 (do not support symlinks)
category: !os:mint,!os:msys,!os:svr4.0,!nosymlink
file-setup: dir 755 "dir"
file-setup: symlink 644 "dir/abc"
	non-existent-file
stdin:
	echo d*/*
	echo d*/abc
expected-stdout:
	dir/abc
	dir/abc
---
name: glob-bad-3
description:
	Check that the slash is parsed before the glob
stdin:
	mkdir a 'a[b'
	(cd 'a[b'; echo ok >'c]d')
	echo nok >abd
	echo fail >a/d
	cat a[b/c]d
expected-stdout:
	ok
---
name: glob-range-1
description:
	Test range matching
file-setup: file 644 ".bc"
file-setup: file 644 "abc"
file-setup: file 644 "bbc"
file-setup: file 644 "cbc"
file-setup: file 644 "-bc"
file-setup: file 644 "!bc"
file-setup: file 644 "^bc"
file-setup: file 644 "+bc"
file-setup: file 644 ",bc"
file-setup: file 644 "0bc"
file-setup: file 644 "1bc"
stdin:
	echo [ab-]*
	echo [-ab]*
	echo [!-ab]*
	echo [!ab]*
	echo []ab]*
	echo [^ab]*
	echo [+--]*
	echo [--1]*

expected-stdout:
	-bc abc bbc
	-bc abc bbc
	!bc +bc ,bc 0bc 1bc ^bc cbc
	!bc +bc ,bc -bc 0bc 1bc ^bc cbc
	abc bbc
	^bc abc bbc
	+bc ,bc -bc
	-bc 0bc 1bc
---
name: glob-range-2
description:
	Test range matching
	(AT&T ksh fails this; POSIX says invalid)
file-setup: file 644 "abc"
stdin:
	echo [a--]*
expected-stdout:
	[a--]*
---
name: glob-range-3
description:
	Check that globbing matches the right things...
# breaks on Mac OSX (HFS+ non-standard UTF-8 canonical decomposition)
# breaks on Cygwin 1.7 (files are now UTF-16 or something)
# breaks on QNX 6.4.1 (says RT)
category: !os:cygwin,!os:midipix,!os:darwin,!os:msys,!os:nto,!os:os2,!os:os390
need-pass: no
file-setup: file 644 "a¬c"
stdin:
	echo a[¡-⁄]*
expected-stdout:
	a¬c
---
name: glob-range-4
description:
	Results unspecified according to POSIX
file-setup: file 644 ".bc"
stdin:
	echo [a.]*
expected-stdout:
	[a.]*
---
name: glob-range-5
description:
	Results unspecified according to POSIX
	(AT&T ksh treats this like [a-cc-e]*)
file-setup: file 644 "abc"
file-setup: file 644 "bbc"
file-setup: file 644 "cbc"
file-setup: file 644 "dbc"
file-setup: file 644 "ebc"
file-setup: file 644 "-bc"
file-setup: file 644 "@bc"
stdin:
	echo [a-c-e]*
	echo [a--@]*
expected-stdout:
	-bc abc bbc cbc ebc
	@bc
---
name: glob-range-6
description:
	ksh93 fails this but POSIX probably demands it
file-setup: file 644 "abc"
file-setup: file 644 "cbc"
stdin:
	echo *b*
	[ '*b*' = *b* ] && echo yep; echo $?
expected-stdout:
	abc cbc
	2
expected-stderr-pattern: /.*/
---
name: glob-word-1
description:
	Check BSD word boundary matches
stdin:
	t() { [[ $1 = *[[:\<:]]bar[[:\>:]]* ]]; echo =$?; }
	t 'foo bar baz'
	t 'foobar baz'
	t 'foo barbaz'
	t 'bar'
	t '_bar'
	t 'bar_'
expected-stdout:
	=0
	=1
	=1
	=0
	=1
	=1
---
name: glob-trim-1
description:
	Check against a regression from fixing IFS-subst-2
stdin:
	x='#foo'
	print -r "before='$x'"
	x=${x%%#*}
	print -r "after ='$x'"
expected-stdout:
	before='#foo'
	after =''
---
name: heredoc-1
description:
	Check ordering/content of redundent here documents.
stdin:
	cat << EOF1 << EOF2
	hi
	EOF1
	there
	EOF2
expected-stdout:
	there
---
name: heredoc-2
description:
	Check quoted here-doc is protected.
stdin:
	a=foo
	cat << 'EOF'
	hi\
	there$a
	stuff
	EO\
	F
	EOF
expected-stdout:
	hi\
	there$a
	stuff
	EO\
	F
---
name: heredoc-3
description:
	Check that newline isn't needed after heredoc-delimiter marker.
stdin: !
	cat << EOF
	hi
	there
	EOF
expected-stdout:
	hi
	there
---
name: heredoc-4a
description:
	Check that an error occurs if the heredoc-delimiter is missing.
stdin: !
	cat << EOF
	hi
	there
expected-exit: e > 0
expected-stderr-pattern: /.*/
---
name: heredoc-4an
description:
	Check that an error occurs if the heredoc-delimiter is missing.
arguments: !-n!
stdin: !
	cat << EOF
	hi
	there
expected-exit: e > 0
expected-stderr-pattern: /.*/
---
name: heredoc-4b
description:
	Check that an error occurs if the heredoc is missing.
stdin: !
	cat << EOF
expected-exit: e > 0
expected-stderr-pattern: /.*/
---
name: heredoc-4bn
description:
	Check that an error occurs if the heredoc is missing.
arguments: !-n!
stdin: !
	cat << EOF
expected-exit: e > 0
expected-stderr-pattern: /.*/
---
name: heredoc-5
description:
	Check that backslash quotes a $, ` and \ and kills a \newline
stdin:
	a=BAD
	b=ok
	cat << EOF
	h\${a}i
	h\\${b}i
	th\`echo not-run\`ere
	th\\`echo is-run`ere
	fol\\ks
	more\\
	last \
	line
	EOF
expected-stdout:
	h${a}i
	h\oki
	th`echo not-run`ere
	th\is-runere
	fol\ks
	more\
	last line
---
name: heredoc-6
description:
	Check that \newline in initial here-delim word doesn't imply
	a quoted here-doc.
stdin:
	a=i
	cat << EO\
	F
	h$a
	there
	EOF
expected-stdout:
	hi
	there
---
name: heredoc-7
description:
	Check that double quoted $ expressions in here delimiters are
	not expanded and match the delimiter.
	POSIX says only quote removal is applied to the delimiter.
stdin:
	a=b
	cat << "E$a"
	hi
	h$a
	hb
	E$a
	echo done
expected-stdout:
	hi
	h$a
	hb
	done
---
name: heredoc-8
description:
	Check that double quoted escaped $ expressions in here
	delimiters are not expanded and match the delimiter.
	POSIX says only quote removal is applied to the delimiter
	(\ counts as a quote).
stdin:
	a=b
	cat << "E\$a"
	hi
	h$a
	h\$a
	hb
	h\b
	E$a
	echo done
expected-stdout:
	hi
	h$a
	h\$a
	hb
	h\b
	done
---
name: heredoc-9
description:
	Check that here strings work.
stdin:
	bar="bar
		baz"
	tr abcdefghijklmnopqrstuvwxyz nopqrstuvwxyzabcdefghijklm <<<foo
	"$__progname" -c "tr abcdefghijklmnopqrstuvwxyz nopqrstuvwxyzabcdefghijklm <<<foo"
	tr abcdefghijklmnopqrstuvwxyz nopqrstuvwxyzabcdefghijklm <<<"$bar"
	tr abcdefghijklmnopqrstuvwxyz nopqrstuvwxyzabcdefghijklm <<<'$bar'
	tr abcdefghijklmnopqrstuvwxyz nopqrstuvwxyzabcdefghijklm <<<\$bar
	tr abcdefghijklmnopqrstuvwxyz nopqrstuvwxyzabcdefghijklm <<<-foo
	tr abcdefghijklmnopqrstuvwxyz nopqrstuvwxyzabcdefghijklm <<<"$(echo "foo bar")"
	tr abcdefghijklmnopqrstuvwxyz nopqrstuvwxyzabcdefghijklm <<<"A $(echo "foo bar") B"
	tr abcdefghijklmnopqrstuvwxyz nopqrstuvwxyzabcdefghijklm <<<\$b\$b$bar
	fnord=42
	bar="bar
		 \$fnord baz"
	tr abcdefghijklmnopqrstuvwxyz nopqrstuvwxyzabcdefghijklm <<<$bar
	tr abcdefghijklmnopqrstuvwxyz nopqrstuvwxyzabcdefghijklm <<< bar
	echo $(tr r z <<<'bar' 2>/dev/null)
	cat <<< "$(  :                                                             )aa"
	IFS=$'\n'
	x=(a "b c")
	tr ac 12 <<< ${x[*]}
	tr ac 34 <<< "${x[*]}"
	tr ac 56 <<< ${x[@]}
	tr ac 78 <<< "${x[@]}"
expected-stdout:
	sbb
	sbb
	one
		onm
	$one
	$one
	-sbb
	sbb one
	A sbb one B
	$o$oone
		onm
	one
		 $sabeq onm
	one
	baz
	aa
	1
	b 2
	3
	b 4
	5 b 6
	7 b 8
---
name: heredoc-10
description:
	Check direct here document assignment
category: !shell:ebcdic-yes
stdin:
	x=u
	va=<<EOF
	=a $x \x40=
	EOF
	vb=<<'EOF'
	=b $x \x40=
	EOF
	function foo {
		vc=<<-EOF
			=c $x \x40=
		EOF
	}
	fnd=$(typeset -f foo)
	print -r -- "$fnd"
	function foo {
		echo blub
	}
	foo
	eval "$fnd"
	foo
	# rather nonsensical, but‚Ä¶
	vd=<<<"=d $x \x40="
	ve=<<<'=e $x \x40='
	vf=<<<$'=f $x \x40='
	# now check
	print -r -- "| va={$va} vb={$vb} vc={$vc} vd={$vd} ve={$ve} vf={$vf} |"
	# check append
	v=<<-EOF
		vapp1
	EOF
	v+=<<-EOF
		vapp2
	EOF
	print -r -- "| ${v//$'\n'/^} |"
expected-stdout:
	function foo {
		vc=<<-EOF 
	=c $x \x40=
	EOF
	
	} 
	blub
	| va={=a u \x40=
	} vb={=b $x \x40=
	} vc={=c u \x40=
	} vd={=d u \x40=
	} ve={=e $x \x40=
	} vf={=f $x @=
	} |
	| vapp1^vapp2^ |
---
name: heredoc-10-ebcdic
description:
	Check direct here document assignment
category: !shell:ebcdic-no
stdin:
	x=u
	va=<<EOF
	=a $x \x7C=
	EOF
	vb=<<'EOF'
	=b $x \x7C=
	EOF
	function foo {
		vc=<<-EOF
			=c $x \x7C=
		EOF
	}
	fnd=$(typeset -f foo)
	print -r -- "$fnd"
	function foo {
		echo blub
	}
	foo
	eval "$fnd"
	foo
	# rather nonsensical, but‚Ä¶
	vd=<<<"=d $x \x7C="
	ve=<<<'=e $x \x7C='
	vf=<<<$'=f $x \x7C='
	# now check
	print -r -- "| va={$va} vb={$vb} vc={$vc} vd={$vd} ve={$ve} vf={$vf} |"
	# check append
	v=<<-EOF
		vapp1
	EOF
	v+=<<-EOF
		vapp2
	EOF
	print -r -- "| ${v//$'\n'/^} |"
expected-stdout:
	function foo {
		vc=<<-EOF 
	=c $x \x7C=
	EOF
	
	} 
	blub
	| va={=a u \x7C=
	} vb={=b $x \x7C=
	} vc={=c u \x7C=
	} vd={=d u \x7C=
	} ve={=e $x \x7C=
	} vf={=f $x @=
	} |
	| vapp1^vapp2^ |
---
name: heredoc-11
description:
	Check here documents with no or empty delimiter
stdin:
	x=u
	va=<<
	=a $x \x40=
	<<
	vb=<<''
	=b $x \x40=
	
	function foo {
		vc=<<-
			=c $x \x40=
		<<
		vd=<<-''
			=d $x \x40=
	
	}
	fnd=$(typeset -f foo)
	print -r -- "$fnd"
	function foo {
		echo blub
	}
	foo
	eval "$fnd"
	foo
	print -r -- "| va={$va} vb={$vb} vc={$vc} vd={$vd} |"
	x=y
	foo
	typeset -f foo
	print -r -- "| vc={$vc} vd={$vd} |"
	# check append
	v=<<-
		vapp1
	<<
	v+=<<-''
		vapp2
	
	print -r -- "| ${v//$'\n'/^} |"
expected-stdout:
	function foo {
		vc=<<- 
	=c $x \x40=
	<<
	
		vd=<<-"" 
	=d $x \x40=
	
	
	} 
	blub
	| va={=a u \x40=
	} vb={=b $x \x40=
	} vc={=c u \x40=
	} vd={=d $x \x40=
	} |
	function foo {
		vc=<<- 
	=c $x \x40=
	<<
	
		vd=<<-"" 
	=d $x \x40=
	
	
	} 
	| vc={=c y \x40=
	} vd={=d $x \x40=
	} |
	| vapp1^vapp2^ |
---
name: heredoc-12
description:
	Check here documents can use $* and $@; note shells vary:
	‚Ä¢ pdksh 5.2.14 acts the same
	‚Ä¢ dash has 1 and 2 the same but 3 lacks the space
	‚Ä¢ ksh93, bash4 differ in 2 by using space ipv colon
stdin:
	set -- a b
	nl='
	'
	IFS=" 	$nl"; n=1
	cat <<EOF
	$n foo $* foo
	$n bar "$*" bar
	$n baz $@ baz
	$n bla "$@" bla
	EOF
	IFS=":"; n=2
	cat <<EOF
	$n foo $* foo
	$n bar "$*" bar
	$n baz $@ baz
	$n bla "$@" bla
	EOF
	IFS=; n=3
	cat <<EOF
	$n foo $* foo
	$n bar "$*" bar
	$n baz $@ baz
	$n bla "$@" bla
	EOF
expected-stdout:
	1 foo a b foo
	1 bar "a b" bar
	1 baz a b baz
	1 bla "a b" bla
	2 foo a:b foo
	2 bar "a:b" bar
	2 baz a:b baz
	2 bla "a:b" bla
	3 foo a b foo
	3 bar "a b" bar
	3 baz a b baz
	3 bla "a b" bla
---
name: heredoc-14
description:
	Check that using multiple here documents works
stdin:
	foo() {
		echo "got $(cat) on stdin"
		echo "got $(cat <&4) on fd#4"
		echo "got $(cat <&5) on fd#5"
	}
	bar() {
		foo 4<<-a <<-b 5<<-c
		four
		a
		zero
		b
		five
		c
	}
	x=$(typeset -f bar)
	eval "$x"
	y=$(typeset -f bar)
	[[ $x = "$y" ]]; echo $?
	typeset -f bar
	bar
expected-stdout:
	0
	bar() {
		\foo 4<<-a <<-b 5<<-c 
	four
	a
	zero
	b
	five
	c
	
	} 
	got zero on stdin
	got four on fd#4
	got five on fd#5
---
name: heredoc-15
description:
	Check high-bit7 separators work
stdin:
	u=√§
	tr a-z A-Z <<-‚Ä¶
		m${u}h
	‚Ä¶
	echo ok
expected-stdout:
	M√§H
	ok
---
name: heredoc-comsub-1
description:
	Tests for here documents in COMSUB, taken from Austin ML
stdin:
	text=$(cat <<EOF
	here is the text
	EOF)
	echo = $text =
expected-stdout:
	= here is the text =
---
name: heredoc-comsub-2
description:
	Tests for here documents in COMSUB, taken from Austin ML
stdin:
	unbalanced=$(cat <<EOF
	this paren ) is a problem
	EOF)
	echo = $unbalanced =
expected-stdout:
	= this paren ) is a problem =
---
name: heredoc-comsub-3
description:
	Tests for here documents in COMSUB, taken from Austin ML
stdin:
	balanced=$(cat <<EOF
	these parens ( ) are not a problem
	EOF)
	echo = $balanced =
expected-stdout:
	= these parens ( ) are not a problem =
---
name: heredoc-comsub-4
description:
	Tests for here documents in COMSUB, taken from Austin ML
stdin:
	balanced=$(cat <<EOF
	these parens \( ) are a problem
	EOF)
	echo = $balanced =
expected-stdout:
	= these parens \( ) are a problem =
---
name: heredoc-comsub-5
description:
	Check heredoc and COMSUB mixture in input
stdin:
	prefix() { sed -e "s/^/$1:/"; }
	XXX() { echo x-en; }
	YYY() { echo y-es; }
	
	prefix A <<XXX && echo "$(prefix B <<XXX
	echo line 1
	XXX
	echo line 2)" && prefix C <<YYY
	echo line 3
	XXX
	echo line 4)"
	echo line 5
	YYY
	XXX
expected-stdout:
	A:echo line 3
	B:echo line 1
	line 2
	C:echo line 4)"
	C:echo line 5
	x-en
---
name: heredoc-comsub-6
description:
	Check here documents and here strings can be used
	without a specific command, like $(<‚Ä¶) (extension)
stdin:
	foo=bar
	x=$(<<<EO${foo}F)
	echo "3<$x>"
		y=$(<<-EOF
			hi!
	
			$foo) is not a problem
	
	
		EOF)
	echo "7<$y>"
expected-stdout:
	3<EObarF>
	7<hi!
	
	bar) is not a problem>
---
name: heredoc-subshell-1
description:
	Tests for here documents in subshells, taken from Austin ML
stdin:
	(cat <<EOF
	some text
	EOF)
	echo end
expected-stdout:
	some text
	end
---
name: heredoc-subshell-2
description:
	Tests for here documents in subshells, taken from Austin ML
stdin:
	(cat <<EOF
	some text
	EOF
	)
	echo end
expected-stdout:
	some text
	end
---
name: heredoc-subshell-3
description:
	Tests for here documents in subshells, taken from Austin ML
stdin:
	(cat <<EOF; )
	some text
	EOF
	echo end
expected-stdout:
	some text
	end
---
name: heredoc-weird-1
description:
	Tests for here documents, taken from Austin ML
	Documents current state in mksh, *NOT* necessarily correct!
stdin:
	cat <<END
	hello
	END\
	END
	END
	echo end
expected-stdout:
	hello
	ENDEND
	end
---
name: heredoc-weird-2
description:
	Tests for here documents, taken from Austin ML
stdin:
	cat <<'    END    '
	hello
	    END    
	echo end
expected-stdout:
	hello
	end
---
name: heredoc-weird-4
description:
	Tests for here documents, taken from Austin ML
	Documents current state in mksh, *NOT* necessarily correct!
stdin:
	cat <<END
	hello\
	END
	END
	echo end
expected-stdout:
	helloEND
	end
---
name: heredoc-weird-5
description:
	Tests for here documents, taken from Austin ML
	Documents current state in mksh, *NOT* necessarily correct!
stdin:
	cat <<END
	hello
	\END
	END
	echo end
expected-stdout:
	hello
	\END
	end
---
name: heredoc-tmpfile-1
description:
	Check that heredoc temp files aren't removed too soon or too late.
	Heredoc in simple command.
stdin:
	TMPDIR=$PWD
	eval '
		cat <<- EOF
		hi
		EOF
		for i in a b ; do
			cat <<- EOF
			more
			EOF
		done
	    ' &
	sleep 1
	echo Left overs: *
expected-stdout:
	hi
	more
	more
	Left overs: *
---
name: heredoc-tmpfile-2
description:
	Check that heredoc temp files aren't removed too soon or too late.
	Heredoc in function, multiple calls to function.
stdin:
	TMPDIR=$PWD
	eval '
		foo() {
			cat <<- EOF
			hi
			EOF
		}
		foo
		foo
	    ' &
	sleep 1
	echo Left overs: *
expected-stdout:
	hi
	hi
	Left overs: *
---
name: heredoc-tmpfile-3
description:
	Check that heredoc temp files aren't removed too soon or too late.
	Heredoc in function in loop, multiple calls to function.
stdin:
	TMPDIR=$PWD
	eval '
		foo() {
			cat <<- EOF
			hi
			EOF
		}
		for i in a b; do
			foo
			foo() {
				cat <<- EOF
				folks $i
				EOF
			}
		done
		foo
	    ' &
	sleep 1
	echo Left overs: *
expected-stdout:
	hi
	folks b
	folks b
	Left overs: *
---
name: heredoc-tmpfile-4
description:
	Check that heredoc temp files aren't removed too soon or too late.
	Backgrounded simple command with here doc
stdin:
	TMPDIR=$PWD
	eval '
		cat <<- EOF &
		hi
		EOF
	    ' &
	sleep 1
	echo Left overs: *
expected-stdout:
	hi
	Left overs: *
---
name: heredoc-tmpfile-5
description:
	Check that heredoc temp files aren't removed too soon or too late.
	Backgrounded subshell command with here doc
stdin:
	TMPDIR=$PWD
	eval '
	      (
		sleep 1	# so parent exits
		echo A
		cat <<- EOF
		hi
		EOF
		echo B
	      ) &
	    ' &
	sleep 5
	echo Left overs: *
expected-stdout:
	A
	hi
	B
	Left overs: *
---
name: heredoc-tmpfile-6
description:
	Check that heredoc temp files aren't removed too soon or too late.
	Heredoc in pipeline.
stdin:
	TMPDIR=$PWD
	eval '
		cat <<- EOF | sed "s/hi/HI/"
		hi
		EOF
	    ' &
	sleep 1
	echo Left overs: *
expected-stdout:
	HI
	Left overs: *
---
name: heredoc-tmpfile-7
description:
	Check that heredoc temp files aren't removed too soon or too late.
	Heredoc in backgrounded pipeline.
stdin:
	TMPDIR=$PWD
	eval '
		cat <<- EOF | sed 's/hi/HI/' &
		hi
		EOF
	    ' &
	sleep 1
	echo Left overs: *
expected-stdout:
	HI
	Left overs: *
---
name: heredoc-tmpfile-8
description:
	Check that heredoc temp files aren't removed too soon or too
	late. Heredoc in function, backgrounded call to function.
	This check can fail on slow machines (<100 MHz), or Cygwin,
	that's normal.
need-pass: no
stdin:
	TMPDIR=$PWD
	# Background eval so main shell doesn't do parsing
	eval '
		foo() {
			cat <<- EOF
			hi
			EOF
		}
		foo
		# sleep so eval can die
		(sleep 1; foo) &
		(sleep 1; foo) &
		foo
	    ' &
	sleep 5
	echo Left overs: *
expected-stdout:
	hi
	hi
	hi
	hi
	Left overs: *
---
name: heredoc-quoting-unsubst
description:
	Check for correct handling of quoted characters in
	here documents without substitution (marker is quoted).
stdin:
	foo=bar
	cat <<-'EOF'
		x " \" \ \\ $ \$ `echo baz` \`echo baz\` $foo \$foo x
	EOF
expected-stdout:
	x " \" \ \\ $ \$ `echo baz` \`echo baz\` $foo \$foo x
---
name: heredoc-quoting-subst
description:
	Check for correct handling of quoted characters in
	here documents with substitution (marker is not quoted).
stdin:
	foo=bar
	cat <<-EOF
		x " \" \ \\ $ \$ `echo baz` \`echo baz\` $foo \$foo x
	EOF
expected-stdout:
	x " \" \ \ $ $ baz `echo baz` bar $foo x
---
name: single-quotes-in-braces
description:
	Check that single quotes inside unquoted {} are treated as quotes
stdin:
	foo=1
	echo ${foo:+'blah  $foo'}
expected-stdout:
	blah  $foo
---
name: single-quotes-in-quoted-braces
description:
	Check that single quotes inside quoted {} are treated as
	normal char
stdin:
	foo=1
	echo "${foo:+'blah  $foo'}"
expected-stdout:
	'blah  1'
---
name: single-quotes-in-braces-nested
description:
	Check that single quotes inside unquoted {} are treated as quotes,
	even if that's inside a double-quoted command expansion
stdin:
	foo=1
	echo "$( echo ${foo:+'blah  $foo'})"
expected-stdout:
	blah  $foo
---
name: single-quotes-in-brace-pattern
description:
	Check that single quotes inside {} pattern are treated as quotes
stdin:
	foo=1234
	echo ${foo%'2'*} "${foo%'2'*}" ${foo%2'*'} "${foo%2'*'}"
expected-stdout:
	1 1 1234 1234
---
name: single-quotes-in-heredoc-braces
description:
	Check that single quotes inside {} in heredoc are treated
	as normal char
stdin:
	foo=1
	cat <<EOM
	${foo:+'blah  $foo'}
	EOM
expected-stdout:
	'blah  1'
---
name: single-quotes-in-nested-braces
description:
	Check that single quotes inside nested unquoted {} are
	treated as quotes
stdin:
	foo=1
	echo ${foo:+${foo:+'blah  $foo'}}
expected-stdout:
	blah  $foo
---
name: single-quotes-in-nested-quoted-braces
description:
	Check that single quotes inside nested quoted {} are treated
	as normal char
stdin:
	foo=1
	echo "${foo:+${foo:+'blah  $foo'}}"
expected-stdout:
	'blah  1'
---
name: single-quotes-in-nested-braces-nested
description:
	Check that single quotes inside nested unquoted {} are treated
	as quotes, even if that's inside a double-quoted command expansion
stdin:
	foo=1
	echo "$( echo ${foo:+${foo:+'blah  $foo'}})"
expected-stdout:
	blah  $foo
---
name: single-quotes-in-nested-brace-pattern
description:
	Check that single quotes inside nested {} pattern are treated as quotes
stdin:
	foo=1234
	echo ${foo:+${foo%'2'*}} "${foo:+${foo%'2'*}}" ${foo:+${foo%2'*'}} "${foo:+${foo%2'*'}}"
expected-stdout:
	1 1 1234 1234
---
name: single-quotes-in-heredoc-nested-braces
description:
	Check that single quotes inside nested {} in heredoc are treated
	as normal char
stdin:
	foo=1
	cat <<EOM
	${foo:+${foo:+'blah  $foo'}}
	EOM
expected-stdout:
	'blah  1'
---
name: single-quotes-in-heredoc-trim
description:
	In some cases, single quotes inside {} in heredoc are not normal
stdin:
	x=notOK
	cat <<EOF
	1: ${x#not} ${x:+${x#not}}
	2: ${x#\n\o\t} ${x:+${x#\n\o\t}}
	3: ${x#"not"} ${x:+${x#"not"}}
	4: ${x#'not'} ${x:+${x#'not'}}
	5: ${x#$'not'} ${x:+${x#$'not'}}
	EOF
expected-stdout:
	1: OK OK
	2: OK OK
	3: OK OK
	4: OK OK
	5: OK OK
---
name: history-basic
description:
	See if we can test history at all
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo hi
	fc -l
expected-stdout:
	hi
	1	echo hi
expected-stderr-pattern:
	/^X*$/
---
name: history-dups
description:
	Verify duplicates and spaces are not entered
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo hi
	 echo yo
	echo hi
	fc -l
expected-stdout:
	hi
	yo
	hi
	1	echo hi
expected-stderr-pattern:
	/^X*$/
---
name: history-unlink
description:
	Check if broken HISTFILEs do not cause trouble
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=foo/hist.file!
file-setup: file 644 "Env"
	PS1=X
file-setup: dir 755 "foo"
file-setup: file 644 "foo/hist.file"
	sometext
time-limit: 5
perl-setup: chmod(0555, "foo");
stdin:
	echo hi
	fc -l
	chmod 0755 foo
expected-stdout:
	hi
	1	echo hi
expected-stderr-pattern:
	/(.*can't unlink HISTFILE.*\n)?X*$/
---
name: history-multiline
description:
	Check correct multiline history, Debian #783978
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!
file-setup: file 644 "Env"
	PS1=X
	PS2=Y
stdin:
	for i in A B C
	do
	   print $i
	   print $i
	done
	fc -l
expected-stdout:
	A
	A
	B
	B
	C
	C
	1	for i in A B C
		do
		   print $i
		   print $i
		done
expected-stderr-pattern:
	/^XYYYYXX$/
---
name: history-e-minus-1
description:
	Check if more recent command is executed
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo hi
	echo there
	fc -e -
expected-stdout:
	hi
	there
	there
expected-stderr-pattern:
	/^X*echo there\nX*$/
---
name: history-e-minus-2
description:
	Check that repeated command is printed before command
	is re-executed.
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	exec 2>&1
	echo hi
	echo there
	fc -e -
expected-stdout-pattern:
	/X*hi\nX*there\nX*echo there\nthere\nX*/
expected-stderr-pattern:
	/^X*$/
---
name: history-e-minus-3
description:
	fc -e - fails when there is no history
	(ksh93 has a bug that causes this to fail)
	(ksh88 loops on this)
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	fc -e -
	echo ok
expected-stdout:
	ok
expected-stderr-pattern:
	/^X*.*:.*history.*\nX*$/
---
name: history-e-minus-4
description:
	Check if "fc -e -" command output goes to stdout.
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo abc
	fc -e - | (read x; echo "A $x")
	echo ok
expected-stdout:
	abc
	A abc
	ok
expected-stderr-pattern:
	/^X*echo abc\nX*/
---
name: history-e-minus-5
description:
	fc is replaced in history by new command.
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo abc def
	echo ghi jkl
	:
	fc -e - echo
	fc -l 2 5
expected-stdout:
	abc def
	ghi jkl
	ghi jkl
	2	echo ghi jkl
	3	:
	4	echo ghi jkl
	5	fc -l 2 5
expected-stderr-pattern:
	/^X*echo ghi jkl\nX*$/
---
name: history-list-1
description:
	List lists correct range
	(ksh88 fails 'cause it lists the fc command)
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo line 1
	echo line 2
	echo line 3
	fc -l -- -2
expected-stdout:
	line 1
	line 2
	line 3
	2	echo line 2
	3	echo line 3
expected-stderr-pattern:
	/^X*$/
---
name: history-list-2
description:
	Lists oldest history if given pre-historic number
	(ksh93 has a bug that causes this to fail)
	(ksh88 fails 'cause it lists the fc command)
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo line 1
	echo line 2
	echo line 3
	fc -l -- -40
expected-stdout:
	line 1
	line 2
	line 3
	1	echo line 1
	2	echo line 2
	3	echo line 3
expected-stderr-pattern:
	/^X*$/
---
name: history-list-3
description:
	Can give number 'options' to fc
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo line 1
	echo line 2
	echo line 3
	echo line 4
	fc -l -3 -2
expected-stdout:
	line 1
	line 2
	line 3
	line 4
	2	echo line 2
	3	echo line 3
expected-stderr-pattern:
	/^X*$/
---
name: history-list-4
description:
	-1 refers to previous command
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo line 1
	echo line 2
	echo line 3
	echo line 4
	fc -l -1 -1
expected-stdout:
	line 1
	line 2
	line 3
	line 4
	4	echo line 4
expected-stderr-pattern:
	/^X*$/
---
name: history-list-5
description:
	List command stays in history
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo line 1
	echo line 2
	echo line 3
	echo line 4
	fc -l -1 -1
	fc -l -2 -1
expected-stdout:
	line 1
	line 2
	line 3
	line 4
	4	echo line 4
	4	echo line 4
	5	fc -l -1 -1
expected-stderr-pattern:
	/^X*$/
---
name: history-list-6
description:
	HISTSIZE limits about of history kept.
	(ksh88 fails 'cause it lists the fc command)
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!HISTSIZE=3!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo line 1
	echo line 2
	echo line 3
	echo line 4
	echo line 5
	fc -l
expected-stdout:
	line 1
	line 2
	line 3
	line 4
	line 5
	4	echo line 4
	5	echo line 5
expected-stderr-pattern:
	/^X*$/
---
name: history-list-7
description:
	fc allows too old/new errors in range specification
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!HISTSIZE=3!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo line 1
	echo line 2
	echo line 3
	echo line 4
	echo line 5
	fc -l 1 30
expected-stdout:
	line 1
	line 2
	line 3
	line 4
	line 5
	4	echo line 4
	5	echo line 5
	6	fc -l 1 30
expected-stderr-pattern:
	/^X*$/
---
name: history-list-r-1
description:
	test -r flag in history
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo line 1
	echo line 2
	echo line 3
	echo line 4
	echo line 5
	fc -l -r 2 4
expected-stdout:
	line 1
	line 2
	line 3
	line 4
	line 5
	4	echo line 4
	3	echo line 3
	2	echo line 2
expected-stderr-pattern:
	/^X*$/
---
name: history-list-r-2
description:
	If first is newer than last, -r is implied.
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo line 1
	echo line 2
	echo line 3
	echo line 4
	echo line 5
	fc -l 4 2
expected-stdout:
	line 1
	line 2
	line 3
	line 4
	line 5
	4	echo line 4
	3	echo line 3
	2	echo line 2
expected-stderr-pattern:
	/^X*$/
---
name: history-list-r-3
description:
	If first is newer than last, -r is cancelled.
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo line 1
	echo line 2
	echo line 3
	echo line 4
	echo line 5
	fc -l -r 4 2
expected-stdout:
	line 1
	line 2
	line 3
	line 4
	line 5
	2	echo line 2
	3	echo line 3
	4	echo line 4
expected-stderr-pattern:
	/^X*$/
---
name: history-subst-1
description:
	Basic substitution
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo abc def
	echo ghi jkl
	fc -e - abc=AB 'echo a'
expected-stdout:
	abc def
	ghi jkl
	AB def
expected-stderr-pattern:
	/^X*echo AB def\nX*$/
---
name: history-subst-2
description:
	Does subst find previous command?
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo abc def
	echo ghi jkl
	fc -e - jkl=XYZQRT 'echo g'
expected-stdout:
	abc def
	ghi jkl
	ghi XYZQRT
expected-stderr-pattern:
	/^X*echo ghi XYZQRT\nX*$/
---
name: history-subst-3
description:
	Does subst find previous command when no arguments given
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo abc def
	echo ghi jkl
	fc -e - jkl=XYZQRT
expected-stdout:
	abc def
	ghi jkl
	ghi XYZQRT
expected-stderr-pattern:
	/^X*echo ghi XYZQRT\nX*$/
---
name: history-subst-4
description:
	Global substitutions work
	(ksh88 and ksh93 do not have -g option)
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo abc def asjj sadjhasdjh asdjhasd
	fc -e - -g a=FooBAR
expected-stdout:
	abc def asjj sadjhasdjh asdjhasd
	FooBARbc def FooBARsjj sFooBARdjhFooBARsdjh FooBARsdjhFooBARsd
expected-stderr-pattern:
	/^X*echo FooBARbc def FooBARsjj sFooBARdjhFooBARsdjh FooBARsdjhFooBARsd\nX*$/
---
name: history-subst-5
description:
	Make sure searches don't find current (fc) command
	(ksh88/ksh93 don't have the ? prefix thing so they fail this test)
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo abc def
	echo ghi jkl
	fc -e - abc=AB \?abc
expected-stdout:
	abc def
	ghi jkl
	AB def
expected-stderr-pattern:
	/^X*echo AB def\nX*$/
---
name: history-ed-1-old
description:
	Basic (ed) editing works (assumes you have generic ed editor
	that prints no prompts). This is for oldish ed(1) which write
	the character count to stdout.
category: stdout-ed
need-ctty: yes
need-pass: no
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo abc def
	fc echo
	s/abc/FOOBAR/
	w
	q
expected-stdout:
	abc def
	13
	16
	FOOBAR def
expected-stderr-pattern:
	/^X*echo FOOBAR def\nX*$/
---
name: history-ed-2-old
description:
	Correct command is edited when number given
category: stdout-ed
need-ctty: yes
need-pass: no
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo line 1
	echo line 2 is here
	echo line 3
	echo line 4
	fc 2
	s/is here/is changed/
	w
	q
expected-stdout:
	line 1
	line 2 is here
	line 3
	line 4
	20
	23
	line 2 is changed
expected-stderr-pattern:
	/^X*echo line 2 is changed\nX*$/
---
name: history-ed-3-old
description:
	Newly created multi line commands show up as single command
	in history.
	(ksh88 fails 'cause it lists the fc command)
category: stdout-ed
need-ctty: yes
need-pass: no
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo abc def
	fc echo
	s/abc/FOOBAR/
	$a
	echo a new line
	.
	w
	q
	fc -l
expected-stdout:
	abc def
	13
	32
	FOOBAR def
	a new line
	1	echo abc def
	2	echo FOOBAR def
		echo a new line
expected-stderr-pattern:
	/^X*echo FOOBAR def\necho a new line\nX*$/
---
name: history-ed-1
description:
	Basic (ed) editing works (assumes you have generic ed editor
	that prints no prompts). This is for newish ed(1) and stderr.
category: !no-stderr-ed
need-ctty: yes
need-pass: no
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo abc def
	fc echo
	s/abc/FOOBAR/
	w
	q
expected-stdout:
	abc def
	FOOBAR def
expected-stderr-pattern:
	/^X*13\n16\necho FOOBAR def\nX*$/
---
name: history-ed-2
description:
	Correct command is edited when number given
category: !no-stderr-ed
need-ctty: yes
need-pass: no
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo line 1
	echo line 2 is here
	echo line 3
	echo line 4
	fc 2
	s/is here/is changed/
	w
	q
expected-stdout:
	line 1
	line 2 is here
	line 3
	line 4
	line 2 is changed
expected-stderr-pattern:
	/^X*20\n23\necho line 2 is changed\nX*$/
---
name: history-ed-3
description:
	Newly created multi line commands show up as single command
	in history.
category: !no-stderr-ed
need-ctty: yes
need-pass: no
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	echo abc def
	fc echo
	s/abc/FOOBAR/
	$a
	echo a new line
	.
	w
	q
	fc -l
expected-stdout:
	abc def
	FOOBAR def
	a new line
	1	echo abc def
	2	echo FOOBAR def
		echo a new line
expected-stderr-pattern:
	/^X*13\n32\necho FOOBAR def\necho a new line\nX*$/
---
name: IFS-space-1
description:
	Simple test, default IFS
stdin:
	showargs() { for s_arg in "$@"; do echo -n "<$s_arg> "; done; echo .; }
	set -- A B C
	showargs 1 $*
	showargs 2 "$*"
	showargs 3 $@
	showargs 4 "$@"
expected-stdout:
	<1> <A> <B> <C> .
	<2> <A B C> .
	<3> <A> <B> <C> .
	<4> <A> <B> <C> .
---
name: IFS-colon-1
description:
	Simple test, IFS=:
stdin:
	showargs() { for s_arg in "$@"; do echo -n "<$s_arg> "; done; echo .; }
	IFS=:
	set -- A B C
	showargs 1 $*
	showargs 2 "$*"
	showargs 3 $@
	showargs 4 "$@"
expected-stdout:
	<1> <A> <B> <C> .
	<2> <A:B:C> .
	<3> <A> <B> <C> .
	<4> <A> <B> <C> .
---
name: IFS-null-1
description:
	Simple test, IFS=""
stdin:
	showargs() { for s_arg in "$@"; do echo -n "<$s_arg> "; done; echo .; }
	IFS=""
	set -- A B C
	showargs 1 $*
	showargs 2 "$*"
	showargs 3 $@
	showargs 4 "$@"
expected-stdout:
	<1> <A> <B> <C> .
	<2> <ABC> .
	<3> <A> <B> <C> .
	<4> <A> <B> <C> .
---
name: IFS-space-colon-1
description:
	Simple test, IFS=<white-space>:
stdin:
	showargs() { for s_arg in "$@"; do echo -n "<$s_arg> "; done; echo .; }
	IFS="$IFS:"
	set --
	showargs 1 $*
	showargs 2 "$*"
	showargs 3 $@
	showargs 4 "$@"
	showargs 5 : "$@"
expected-stdout:
	<1> .
	<2> <> .
	<3> .
	<4> .
	<5> <:> .
---
name: IFS-space-colon-2
description:
	Simple test, IFS=<white-space>:
	AT&T ksh fails this, POSIX says the test is correct.
stdin:
	showargs() { for s_arg in "$@"; do echo -n "<$s_arg> "; done; echo .; }
	IFS="$IFS:"
	set --
	showargs :"$@"
expected-stdout:
	<:> .
---
name: IFS-space-colon-4
description:
	Simple test, IFS=<white-space>:
stdin:
	showargs() { for s_arg in "$@"; do echo -n "<$s_arg> "; done; echo .; }
	IFS="$IFS:"
	set --
	showargs "$@$@"
expected-stdout:
	.
---
name: IFS-space-colon-5
description:
	Simple test, IFS=<white-space>:
	Don't know what POSIX thinks of this.  AT&T ksh does not do this.
stdin:
	showargs() { for s_arg in "$@"; do echo -n "<$s_arg> "; done; echo .; }
	IFS="$IFS:"
	set --
	showargs "${@:-}"
expected-stdout:
	<> .
---
name: IFS-subst-1
description:
	Simple test, IFS=<white-space>:
stdin:
	showargs() { for s_arg in "$@"; do echo -n "<$s_arg> "; done; echo .; }
	IFS="$IFS:"
	x=":b: :"
	echo -n '1:'; for i in $x ; do echo -n " [$i]" ; done ; echo
	echo -n '2:'; for i in :b:: ; do echo -n " [$i]" ; done ; echo
	showargs 3 $x
	showargs 4 :b::
	x="a:b:"
	echo -n '5:'; for i in $x ; do echo -n " [$i]" ; done ; echo
	showargs 6 $x
	x="a::c"
	echo -n '7:'; for i in $x ; do echo -n " [$i]" ; done ; echo
	showargs 8 $x
	echo -n '9:'; for i in ${FOO-`echo -n h:i`th:ere} ; do echo -n " [$i]" ; done ; echo
	showargs 10 ${FOO-`echo -n h:i`th:ere}
	showargs 11 "${FOO-`echo -n h:i`th:ere}"
	x=" A :  B::D"
	echo -n '12:'; for i in $x ; do echo -n " [$i]" ; done ; echo
	showargs 13 $x
expected-stdout:
	1: [] [b] []
	2: [:b::]
	<3> <> <b> <> .
	<4> <:b::> .
	5: [a] [b]
	<6> <a> <b> .
	7: [a] [] [c]
	<8> <a> <> <c> .
	9: [h] [ith] [ere]
	<10> <h> <ith> <ere> .
	<11> <h:ith:ere> .
	12: [A] [B] [] [D]
	<13> <A> <B> <> <D> .
---
name: IFS-subst-2
description:
	Check leading whitespace after trim does not make a field
stdin:
	showargs() { for s_arg in "$@"; do echo -n "<$s_arg> "; done; echo .; }
	x="X 1 2"
	showargs 1 shift ${x#X}
expected-stdout:
	<1> <shift> <1> <2> .
---
name: IFS-subst-3-arr
description:
	Check leading IFS non-whitespace after trim does make a field
	but leading IFS whitespace does not, nor empty replacements
stdin:
	showargs() { for s_arg in "$@"; do echo -n "<$s_arg> "; done; echo .; }
	showargs 0 ${-+}
	IFS=:
	showargs 1 ${-+:foo:bar}
	IFS=' '
	showargs 2 ${-+ foo bar}
expected-stdout:
	<0> .
	<1> <> <foo> <bar> .
	<2> <foo> <bar> .
---
name: IFS-subst-3-ass
description:
	Check non-field semantics
stdin:
	showargs() { for s_arg in "$@"; do echo -n "<$s_arg> "; done; echo .; }
	showargs 0 x=${-+}
	IFS=:
	showargs 1 x=${-+:foo:bar}
	IFS=' '
	showargs 2 x=${-+ foo bar}
expected-stdout:
	<0> <x=> .
	<1> <x=> <foo> <bar> .
	<2> <x=> <foo> <bar> .
---
name: IFS-subst-3-lcl
description:
	Check non-field semantics, smaller corner case (LP#1381965)
stdin:
	set -x
	local regex=${2:-}
	exit 1
expected-exit: e != 0
expected-stderr-pattern:
	/regex=/
---
name: IFS-subst-4-1
description:
	reported by mikeserv
stdin:
	pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; }
	a='space divded  argument
	here'
	IFS=\  ; set -- $a
	IFS= ; q="$*" ; nq=$*
	pfn "$*" $* "$q" "$nq"
	[ "$q" = "$nq" ] && echo =true || echo =false
expected-stdout:
	<spacedivdedargument
	here>
	<space>
	<divded>
	<argument
	here>
	<spacedivdedargument
	here>
	<spacedivdedargument
	here>
	=true
---
name: IFS-subst-4-2
description:
	extended testsuite based on problem by mikeserv
stdin:
	pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; }
	a='space divded  argument
	here'
	IFS=\  ; set -- $a
	IFS= ; q="$@" ; nq=$@
	pfn "$*" $* "$q" "$nq"
	[ "$q" = "$nq" ] && echo =true || echo =false
expected-stdout:
	<spacedivdedargument
	here>
	<space>
	<divded>
	<argument
	here>
	<space divded argument
	here>
	<space divded argument
	here>
	=true
---
name: IFS-subst-4-3
description:
	extended testsuite based on problem by mikeserv
stdin:
	pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; }
	a='space divded  argument
	here'
	IFS=\ ; set -- $a; IFS=
	qs="$*"
	nqs=$*
	qk="$@"
	nqk=$@
	print -nr -- '= qs '; pfn "$qs"
	print -nr -- '=nqs '; pfn "$nqs"
	print -nr -- '= qk '; pfn "$qk"
	print -nr -- '=nqk '; pfn "$nqk"
	print -nr -- '~ qs '; pfn "$*"
	print -nr -- '~nqs '; pfn $*
	print -nr -- '~ qk '; pfn "$@"
	print -nr -- '~nqk '; pfn $@
expected-stdout:
	= qs <spacedivdedargument
	here>
	=nqs <spacedivdedargument
	here>
	= qk <space divded argument
	here>
	=nqk <space divded argument
	here>
	~ qs <spacedivdedargument
	here>
	~nqs <space>
	<divded>
	<argument
	here>
	~ qk <space>
	<divded>
	<argument
	here>
	~nqk <space>
	<divded>
	<argument
	here>
---
name: IFS-subst-4-4
description:
	extended testsuite based on problem by mikeserv
stdin:
	pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; }
	a='space divded  argument
	here'
	IFS=\ ; set -- $a; IFS=
	qs="$*"
	print -nr -- '= qs '; pfn "$qs"
	print -nr -- '~ qs '; pfn "$*"
	nqs=$*
	print -nr -- '=nqs '; pfn "$nqs"
	print -nr -- '~nqs '; pfn $*
	qk="$@"
	print -nr -- '= qk '; pfn "$qk"
	print -nr -- '~ qk '; pfn "$@"
	nqk=$@
	print -nr -- '=nqk '; pfn "$nqk"
	print -nr -- '~nqk '; pfn $@
expected-stdout:
	= qs <spacedivdedargument
	here>
	~ qs <spacedivdedargument
	here>
	=nqs <spacedivdedargument
	here>
	~nqs <space>
	<divded>
	<argument
	here>
	= qk <space divded argument
	here>
	~ qk <space>
	<divded>
	<argument
	here>
	=nqk <space divded argument
	here>
	~nqk <space>
	<divded>
	<argument
	here>
---
name: IFS-subst-4-4p
description:
	extended testsuite based on problem by mikeserv
stdin:
	pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; }
	a='space divded  argument
	here'
	IFS=\ ; set -- $a; IFS=
	unset v
	qs=${v:-"$*"}
	print -nr -- '= qs '; pfn "$qs"
	print -nr -- '~ qs '; pfn ${v:-"$*"}
	nqs=${v:-$*}
	print -nr -- '=nqs '; pfn "$nqs"
	print -nr -- '~nqs '; pfn ${v:-$*}
	qk=${v:-"$@"}
	print -nr -- '= qk '; pfn "$qk"
	print -nr -- '~ qk '; pfn ${v:-"$@"}
	nqk=${v:-$@}
	print -nr -- '=nqk '; pfn "$nqk"
	print -nr -- '~nqk '; pfn ${v:-$@}
expected-stdout:
	= qs <spacedivdedargument
	here>
	~ qs <spacedivdedargument
	here>
	=nqs <spacedivdedargument
	here>
	~nqs <space>
	<divded>
	<argument
	here>
	= qk <space divded argument
	here>
	~ qk <space>
	<divded>
	<argument
	here>
	=nqk <space divded argument
	here>
	~nqk <space>
	<divded>
	<argument
	here>
---
name: IFS-subst-4-5
description:
	extended testsuite based on problem by mikeserv
stdin:
	pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; }
	a='space divded  argument
	here'
	IFS=\ ; set -- $a; IFS=,
	qs="$*"
	print -nr -- '= qs '; pfn "$qs"
	print -nr -- '~ qs '; pfn "$*"
	nqs=$*
	print -nr -- '=nqs '; pfn "$nqs"
	print -nr -- '~nqs '; pfn $*
	qk="$@"
	print -nr -- '= qk '; pfn "$qk"
	print -nr -- '~ qk '; pfn "$@"
	nqk=$@
	print -nr -- '=nqk '; pfn "$nqk"
	print -nr -- '~nqk '; pfn $@
expected-stdout:
	= qs <space,divded,argument
	here>
	~ qs <space,divded,argument
	here>
	=nqs <space,divded,argument
	here>
	~nqs <space>
	<divded>
	<argument
	here>
	= qk <space divded argument
	here>
	~ qk <space>
	<divded>
	<argument
	here>
	=nqk <space divded argument
	here>
	~nqk <space>
	<divded>
	<argument
	here>
---
name: IFS-subst-4-5p
description:
	extended testsuite based on problem by mikeserv
stdin:
	pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; }
	a='space divded  argument
	here'
	IFS=\ ; set -- $a; IFS=,
	unset v
	qs=${v:-"$*"}
	print -nr -- '= qs '; pfn "$qs"
	print -nr -- '~ qs '; pfn ${v:-"$*"}
	nqs=${v:-$*}
	print -nr -- '=nqs '; pfn "$nqs"
	print -nr -- '~nqs '; pfn ${v:-$*}
	qk=${v:-"$@"}
	print -nr -- '= qk '; pfn "$qk"
	print -nr -- '~ qk '; pfn ${v:-"$@"}
	nqk=${v:-$@}
	print -nr -- '=nqk '; pfn "$nqk"
	print -nr -- '~nqk '; pfn ${v:-$@}
expected-stdout:
	= qs <space,divded,argument
	here>
	~ qs <space,divded,argument
	here>
	=nqs <space,divded,argument
	here>
	~nqs <space>
	<divded>
	<argument
	here>
	= qk <space divded argument
	here>
	~ qk <space>
	<divded>
	<argument
	here>
	=nqk <space divded argument
	here>
	~nqk <space>
	<divded>
	<argument
	here>
---
name: IFS-subst-5
description:
	extended testsuite based on IFS-subst-3
	differs slightly from ksh93:
	- omit trailing field in a3zna, a7ina (unquoted $@ expansion)
	- has extra middle fields in b5ins, b7ina (IFS_NWS unquoted expansion)
	differs slightly from bash:
	- omit leading field in a5ins, a7ina (IFS_NWS unquoted expansion)
	differs slightly from zsh:
	- differs in assignment, not expansion; probably zsh bug
	- has extra middle fields in b5ins, b7ina (IFS_NWS unquoted expansion)
	'emulate sh' zsh has extra fields in
	- a5ins (IFS_NWS unquoted $*)
	- b5ins, matching mksh‚Äôs
	!!WARNING!! more to come: http://austingroupbugs.net/view.php?id=888
stdin:
	"$__progname" -c 'pfb() { for s_arg in "$@"; do print -r -- "[$s_arg]"; done; }; pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; };
		IFS=; set -- "" 2 ""; pfb $*; x=$*; pfn "$x"'
	echo '=a1zns'
	"$__progname" -c 'pfb() { for s_arg in "$@"; do print -r -- "[$s_arg]"; done; }; pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; };
		IFS=; set -- "" 2 ""; pfb "$*"; x="$*"; pfn "$x"'
	echo '=a2zqs'
	"$__progname" -c 'pfb() { for s_arg in "$@"; do print -r -- "[$s_arg]"; done; }; pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; };
		IFS=; set -- "" 2 ""; pfb $@; x=$@; pfn "$x"'
	echo '=a3zna'
	"$__progname" -c 'pfb() { for s_arg in "$@"; do print -r -- "[$s_arg]"; done; }; pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; };
		IFS=; set -- "" 2 ""; pfb "$@"; x="$@"; pfn "$x"'
	echo '=a4zqa'
	"$__progname" -c 'pfb() { for s_arg in "$@"; do print -r -- "[$s_arg]"; done; }; pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; };
		IFS=,; set -- "" 2 ""; pfb $*; x=$*; pfn "$x"'
	echo '=a5ins'
	"$__progname" -c 'pfb() { for s_arg in "$@"; do print -r -- "[$s_arg]"; done; }; pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; };
		IFS=,; set -- "" 2 ""; pfb "$*"; x="$*"; pfn "$x"'
	echo '=a6iqs'
	"$__progname" -c 'pfb() { for s_arg in "$@"; do print -r -- "[$s_arg]"; done; }; pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; };
		IFS=,; set -- "" 2 ""; pfb $@; x=$@; pfn "$x"'
	echo '=a7ina'
	"$__progname" -c 'pfb() { for s_arg in "$@"; do print -r -- "[$s_arg]"; done; }; pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; };
		IFS=,; set -- "" 2 ""; pfb "$@"; x="$@"; pfn "$x"'
	echo '=a8iqa'
	"$__progname" -c 'pfb() { for s_arg in "$@"; do print -r -- "[$s_arg]"; done; }; pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; };
		IFS=; set -- A B "" "" C; pfb $*; x=$*; pfn "$x"'
	echo '=b1zns'
	"$__progname" -c 'pfb() { for s_arg in "$@"; do print -r -- "[$s_arg]"; done; }; pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; };
		IFS=; set -- A B "" "" C; pfb "$*"; x="$*"; pfn "$x"'
	echo '=b2zqs'
	"$__progname" -c 'pfb() { for s_arg in "$@"; do print -r -- "[$s_arg]"; done; }; pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; };
		IFS=; set -- A B "" "" C; pfb $@; x=$@; pfn "$x"'
	echo '=b3zna'
	"$__progname" -c 'pfb() { for s_arg in "$@"; do print -r -- "[$s_arg]"; done; }; pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; };
		IFS=; set -- A B "" "" C; pfb "$@"; x="$@"; pfn "$x"'
	echo '=b4zqa'
	"$__progname" -c 'pfb() { for s_arg in "$@"; do print -r -- "[$s_arg]"; done; }; pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; };
		IFS=,; set -- A B "" "" C; pfb $*; x=$*; pfn "$x"'
	echo '=b5ins'
	"$__progname" -c 'pfb() { for s_arg in "$@"; do print -r -- "[$s_arg]"; done; }; pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; };
		IFS=,; set -- A B "" "" C; pfb "$*"; x="$*"; pfn "$x"'
	echo '=b6iqs'
	"$__progname" -c 'pfb() { for s_arg in "$@"; do print -r -- "[$s_arg]"; done; }; pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; };
		IFS=,; set -- A B "" "" C; pfb $@; x=$@; pfn "$x"'
	echo '=b7ina'
	"$__progname" -c 'pfb() { for s_arg in "$@"; do print -r -- "[$s_arg]"; done; }; pfn() { for s_arg in "$@"; do print -r -- "<$s_arg>"; done; };
		IFS=,; set -- A B "" "" C; pfb "$@"; x="$@"; pfn "$x"'
	echo '=b8iqa'
expected-stdout:
	[2]
	<2>
	=a1zns
	[2]
	<2>
	=a2zqs
	[2]
	< 2 >
	=a3zna
	[]
	[2]
	[]
	< 2 >
	=a4zqa
	[2]
	<,2,>
	=a5ins
	[,2,]
	<,2,>
	=a6iqs
	[2]
	< 2 >
	=a7ina
	[]
	[2]
	[]
	< 2 >
	=a8iqa
	[A]
	[B]
	[C]
	<ABC>
	=b1zns
	[ABC]
	<ABC>
	=b2zqs
	[A]
	[B]
	[C]
	<A B   C>
	=b3zna
	[A]
	[B]
	[]
	[]
	[C]
	<A B   C>
	=b4zqa
	[A]
	[B]
	[]
	[]
	[C]
	<A,B,,,C>
	=b5ins
	[A,B,,,C]
	<A,B,,,C>
	=b6iqs
	[A]
	[B]
	[]
	[]
	[C]
	<A B   C>
	=b7ina
	[A]
	[B]
	[]
	[]
	[C]
	<A B   C>
	=b8iqa
---
name: IFS-subst-6
description:
	Regression wrt. vector expansion in trim
stdin:
	showargs() { for s_arg in "$@"; do echo -n "<$s_arg> "; done; echo .; }
	IFS=
	x=abc
	set -- a b
	showargs ${x#$*}
expected-stdout:
	<c> .
---
name: IFS-subst-7
description:
	ksh93 bug wrt. vector expansion in trim
stdin:
	showargs() { for s_arg in "$@"; do echo -n "<$s_arg> "; done; echo .; }
	IFS="*"
	a=abcd
	set -- '' c
	showargs "$*" ${a##"$*"}
expected-stdout:
	<*c> <abcd> .
---
name: IFS-subst-8
description:
	http://austingroupbugs.net/view.php?id=221
stdin:
	n() { echo "$#"; }; n "${foo-$@}"
expected-stdout:
	1
---
name: IFS-subst-9
description:
	Scalar context for $*/$@ in [[ and case
stdin:
	"$__progname" -c 'IFS=; set a b; [[ $* = "$1$2" ]]; echo 1 $?' sh a b
	"$__progname" -c 'IFS=; [[ $* = ab ]]; echo 2 "$?"' sh a b
	"$__progname" -c 'IFS=; [[ "$*" = ab ]]; echo 3 "$?"' sh a b
	"$__progname" -c 'IFS=; [[ $* = a ]]; echo 4 "$?"' sh a b
	"$__progname" -c 'IFS=; [[ "$*" = a ]]; echo 5 "$?"' sh a b
	"$__progname" -c 'IFS=; [[ "$@" = a ]]; echo 6 "$?"' sh a b
	"$__progname" -c 'IFS=; case "$@" in a) echo 7 a;; ab) echo 7 b;; a\ b) echo 7 ok;; esac' sh a b
	"$__progname" -c 'IFS=; case $* in a) echo 8 a;; ab) echo 8 ok;; esac' sh a b
	"$__progname" -c 'pfsp() { for s_arg in "$@"; do print -nr -- "<$s_arg> "; done; print .; }; IFS=; star=$* at="$@"; pfsp 9 "$star" "$at"' sh a b
expected-stdout:
	1 0
	2 0
	3 0
	4 1
	5 1
	6 1
	7 ok
	8 ok
	<9> <ab> <a b> .
---
name: IFS-subst-10
description:
	Scalar context in ${var=$subst}
stdin:
	showargs() { for s_arg in "$@"; do echo -n "<$s_arg> "; done; echo .; }
	set -- one "two three" four
	unset -v var
	save_IFS=$IFS
	IFS=
	set -- ${var=$*}
	IFS=$save_IFS
	echo "var=$var"
	showargs "$@"
expected-stdout:
	var=onetwo threefour
	<onetwo threefour> .
---
name: IFS-subst-11
description:
	Check leading non-whitespace after trim makes only one field
stdin:
	showargs() { for s_arg in "$@"; do echo -n "<$s_arg> "; done; echo .; }
	v="foo!one!two!three"
	IFS="!"
	showargs x ${v:3} y
expected-stdout:
	<x> <> <one> <two> <three> <y> .
---
name: IFS-arith-1
description:
	http://austingroupbugs.net/view.php?id=832
stdin:
	${ZSH_VERSION+false} || emulate sh
	${BASH_VERSION+set -o posix}
	showargs() { for s_arg in "$@"; do echo -n "<$s_arg> "; done; echo .; }
	IFS=0
	showargs $((1230456))
expected-stdout:
	<123> <456> .
---
name: integer-base-err-1
description:
	Can't have 0 base (causes shell to exit)
expected-exit: e != 0
stdin:
	typeset -i i
	i=3
	i=0#4
	echo $i
expected-stderr-pattern:
	/^.*:.*0#4.*\n$/
---
name: integer-base-err-2
description:
	Can't have multiple bases in a 'constant' (causes shell to exit)
	(ksh88 fails this test)
expected-exit: e != 0
stdin:
	typeset -i i
	i=3
	i=2#110#11
	echo $i
expected-stderr-pattern:
	/^.*:.*2#110#11.*\n$/
---
name: integer-base-err-3
description:
	Syntax errors in expressions and effects on bases
	(interactive so errors don't cause exits)
	(ksh88 fails this test - shell exits, even with -i)
need-ctty: yes
arguments: !-i!
stdin:
	PS1= # minimise prompt hassles
	typeset -i4 a=10
	typeset -i a=2+
	echo $a
	typeset -i4 a=10
	typeset -i2 a=2+
	echo $a
expected-stderr-pattern:
	/^([#\$] )?.*:.*2+.*\n.*:.*2+.*\n$/
expected-stdout:
	4#22
	4#22
---
name: integer-base-err-4
description:
	Are invalid digits (according to base) errors?
	(ksh93 fails this test)
expected-exit: e != 0
stdin:
	typeset -i i;
	i=3#4
expected-stderr-pattern:
	/^([#\$] )?.*:.*3#4.*\n$/
---
name: integer-base-1
description:
	Missing number after base is treated as 0.
stdin:
	typeset -i i
	i=3
	i=2#
	echo $i
expected-stdout:
	0
---
name: integer-base-2
description:
	Check 'stickyness' of base in various situations
stdin:
	typeset -i i=8
	echo $i
	echo ---------- A
	typeset -i4 j=8
	echo $j
	echo ---------- B
	typeset -i k=8
	typeset -i4 k=8
	echo $k
	echo ---------- C
	typeset -i4 l
	l=3#10
	echo $l
	echo ---------- D
	typeset -i m
	m=3#10
	echo $m
	echo ---------- E
	n=2#11
	typeset -i n
	echo $n
	n=10
	echo $n
	echo ---------- F
	typeset -i8 o=12
	typeset -i4 o
	echo $o
	echo ---------- G
	typeset -i p
	let p=8#12
	echo $p
expected-stdout:
	8
	---------- A
	4#20
	---------- B
	4#20
	---------- C
	4#3
	---------- D
	3#10
	---------- E
	2#11
	2#1010
	---------- F
	4#30
	---------- G
	8#12
---
name: integer-base-3
description:
	More base parsing (hmm doesn't test much..)
stdin:
	typeset -i aa
	aa=1+12#10+2
	echo $aa
	typeset -i bb
	bb=1+$aa
	echo $bb
	typeset -i bb
	bb=$aa
	echo $bb
	typeset -i cc
	cc=$aa
	echo $cc
expected-stdout:
	15
	16
	15
	15
---
name: integer-base-4
description:
	Check that things not declared as integers are not made integers,
	also, check if base is not reset by -i with no arguments.
	(ksh93 fails - prints 10#20 - go figure)
stdin:
	xx=20
	let xx=10
	typeset -i | grep '^xx='
	typeset -i4 a=10
	typeset -i a=20
	echo $a
expected-stdout:
	4#110
---
name: integer-base-5
description:
	More base stuff
stdin:
	typeset -i4 a=3#10
	echo $a
	echo --
	typeset -i j=3
	j='~3'
	echo $j
	echo --
	typeset -i k=1
	x[k=k+1]=3
	echo $k
	echo --
	typeset -i l
	for l in 1 2+3 4; do echo $l; done
expected-stdout:
	4#3
	--
	-4
	--
	2
	--
	1
	5
	4
---
name: integer-base-6
description:
	Even more base stuff
	(ksh93 fails this test - prints 0)
stdin:
	typeset -i7 i
	i=
	echo $i
expected-stdout:
	7#0
---
name: integer-base-7
description:
	Check that non-integer parameters don't get bases assigned
stdin:
	echo $(( zz = 8#100 ))
	echo $zz
expected-stdout:
	64
	64
---
name: integer-base-8
description:
	Check that base-36 works (full span)
stdin:
	echo 1:$((36#109AZ)).
	typeset -i36 x=1691675
	echo 2:$x.
	typeset -Uui36 x
	echo 3:$x.
expected-stdout:
	1:1691675.
	2:36#109az.
	3:36#109AZ.
---
name: integer-base-check-flat
description:
	Check behaviour does not match POSuX (except if set -o posix),
	because a not type-safe scripting language has *no* business
	interpreting the string "010" as octal number eight (dangerous).
stdin:
	echo 1 "$("$__progname" -c 'echo :$((10))/$((010)),$((0x10)):')" .
	echo 2 "$("$__progname" -o posix -c 'echo :$((10))/$((010)),$((0x10)):')" .
	echo 3 "$("$__progname" -o sh -c 'echo :$((10))/$((010)),$((0x10)):')" .
expected-stdout:
	1 :10/10,16: .
	2 :10/8,16: .
	3 :10/10,16: .
---
name: integer-base-check-numeric-from-1
description:
	Check behaviour for base one
category: !shell:ebcdic-yes
stdin:
	echo 1:$((1#1))0.
expected-stdout:
	1:490.
---
name: integer-base-check-numeric-from-1-ebcdic
description:
	Check behaviour for base one
category: !shell:ebcdic-no
stdin:
	echo 1:$((1#1))0.
expected-stdout:
	1:2410.
---
name: integer-base-check-numeric-from-2
description:
	Check behaviour for base two to 36, and that 37 degrades to 10
stdin:
	i=1
	while (( ++i <= 37 )); do
		eval 'echo '$i':$(('$i'#10)).'
	done
	echo 37:$($__progname -c 'echo $((37#10))').$?:
expected-stdout:
	2:2.
	3:3.
	4:4.
	5:5.
	6:6.
	7:7.
	8:8.
	9:9.
	10:10.
	11:11.
	12:12.
	13:13.
	14:14.
	15:15.
	16:16.
	17:17.
	18:18.
	19:19.
	20:20.
	21:21.
	22:22.
	23:23.
	24:24.
	25:25.
	26:26.
	27:27.
	28:28.
	29:29.
	30:30.
	31:31.
	32:32.
	33:33.
	34:34.
	35:35.
	36:36.
	37:10.
	37:10.0:
---
name: integer-base-check-numeric-to-1
description:
	Check behaviour for base one
category: !shell:ebcdic-yes
stdin:
	i=1
	typeset -Uui$i x=0x40
	eval "typeset -i10 y=$x"
	print $i:$x.$y.
expected-stdout:
	1:1#@.64.
---
name: integer-base-check-numeric-to-1-ebcdic
description:
	Check behaviour for base one
category: !shell:ebcdic-no
stdin:
	i=1
	typeset -Uui$i x=0x7C
	eval "typeset -i10 y=$x"
	print $i:$x.$y.
expected-stdout:
	1:1#@.124.
---
name: integer-base-check-numeric-to-2
description:
	Check behaviour for base two to 36, and that 37 degrades to 10
stdin:
	i=1
	while (( ++i <= 37 )); do
		typeset -Uui$i x=0x40
		eval "typeset -i10 y=$x"
		print $i:$x.$y.
	done
expected-stdout:
	2:2#1000000.64.
	3:3#2101.64.
	4:4#1000.64.
	5:5#224.64.
	6:6#144.64.
	7:7#121.64.
	8:8#100.64.
	9:9#71.64.
	10:64.64.
	11:11#59.64.
	12:12#54.64.
	13:13#4C.64.
	14:14#48.64.
	15:15#44.64.
	16:16#40.64.
	17:17#3D.64.
	18:18#3A.64.
	19:19#37.64.
	20:20#34.64.
	21:21#31.64.
	22:22#2K.64.
	23:23#2I.64.
	24:24#2G.64.
	25:25#2E.64.
	26:26#2C.64.
	27:27#2A.64.
	28:28#28.64.
	29:29#26.64.
	30:30#24.64.
	31:31#22.64.
	32:32#20.64.
	33:33#1V.64.
	34:34#1U.64.
	35:35#1T.64.
	36:36#1S.64.
	37:64.64.
---
name: integer-arithmetic-span
description:
	Check wraparound and size that is defined in mksh
category: int:32
stdin:
	echo s:$((2147483647+1)).$(((2147483647*2)+1)).$(((2147483647*2)+2)).
	echo u:$((#2147483647+1)).$((#(2147483647*2)+1)).$((#(2147483647*2)+2)).
expected-stdout:
	s:-2147483648.-1.0.
	u:2147483648.4294967295.0.
---
name: integer-arithmetic-span-64
description:
	Check wraparound and size that is defined in mksh
category: int:64
stdin:
	echo s:$((9223372036854775807+1)).$(((9223372036854775807*2)+1)).$(((9223372036854775807*2)+2)).
	echo u:$((#9223372036854775807+1)).$((#(9223372036854775807*2)+1)).$((#(9223372036854775807*2)+2)).
expected-stdout:
	s:-9223372036854775808.-1.0.
	u:9223372036854775808.18446744073709551615.0.
---
name: integer-size-FAIL-to-detect
description:
	Notify the user that their ints are not 32 or 64 bit
category: int:u
stdin:
	:
---
name: lineno-stdin
description:
	See if $LINENO is updated and can be modified.
stdin:
	echo A $LINENO
	echo B $LINENO
	LINENO=20
	echo C $LINENO
expected-stdout:
	A 1
	B 2
	C 20
---
name: lineno-inc
description:
	See if $LINENO is set for .'d files.
file-setup: file 644 "dotfile"
	echo dot A $LINENO
	echo dot B $LINENO
	LINENO=20
	echo dot C $LINENO
stdin:
	echo A $LINENO
	echo B $LINENO
	. ./dotfile
expected-stdout:
	A 1
	B 2
	dot A 1
	dot B 2
	dot C 20
---
name: lineno-func
description:
	See if $LINENO is set for commands in a function.
stdin:
	echo A $LINENO
	echo B $LINENO
	bar() {
	    echo func A $LINENO
	    echo func B $LINENO
	}
	bar
	echo C $LINENO
expected-stdout:
	A 1
	B 2
	func A 4
	func B 5
	C 8
---
name: lineno-unset
description:
	See if unsetting LINENO makes it non-magic.
file-setup: file 644 "dotfile"
	echo dot A $LINENO
	echo dot B $LINENO
stdin:
	unset LINENO
	echo A $LINENO
	echo B $LINENO
	bar() {
	    echo func A $LINENO
	    echo func B $LINENO
	}
	bar
	. ./dotfile
	echo C $LINENO
expected-stdout:
	A
	B
	func A
	func B
	dot A
	dot B
	C
---
name: lineno-unset-use
description:
	See if unsetting LINENO makes it non-magic even
	when it is re-used.
file-setup: file 644 "dotfile"
	echo dot A $LINENO
	echo dot B $LINENO
stdin:
	unset LINENO
	LINENO=3
	echo A $LINENO
	echo B $LINENO
	bar() {
	    echo func A $LINENO
	    echo func B $LINENO
	}
	bar
	. ./dotfile
	echo C $LINENO
expected-stdout:
	A 3
	B 3
	func A 3
	func B 3
	dot A 3
	dot B 3
	C 3
---
name: lineno-trap
description:
	Check if LINENO is tracked in traps
stdin:
	fail() {
		echo "line <$1>"
		exit 1
	}
	trap 'fail $LINENO' INT ERR
	false
expected-stdout:
	line <6>
expected-exit: 1
---
name: lineno-eval-alias
description:
	Check if LINENO is trapped in eval and aliases
stdin:
	${ZSH_VERSION+false} || emulate sh; echo $LINENO
	echo $LINENO
	eval '	echo $LINENO
		echo $LINENO
		echo $LINENO'
	echo $LINENO
expected-stdout:
	1
	2
	3
	3
	3
	6
---
name: unknown-trap
description:
	Ensure unknown traps are not a syntax error
stdin:
	(
	trap "echo trap 1 executed" UNKNOWNSIGNAL || echo "foo"
	echo =1
	trap "echo trap 2 executed" UNKNOWNSIGNAL EXIT 999999 FNORD
	echo = $?
	) 2>&1 | sed "s^${__progname%.exe}\.*e*x*e*: <stdin>\[[0-9]*]PROG"
expected-stdout:
	PROG: trap: bad signal 'UNKNOWNSIGNAL'
	foo
	=1
	PROG: trap: bad signal 'UNKNOWNSIGNAL'
	PROG: trap: bad signal '999999'
	PROG: trap: bad signal 'FNORD'
	= 1
	trap 2 executed
---
name: read-IFS-1
description:
	Simple test, default IFS
stdin:
	echo "A B " > IN
	unset x y z
	read x y z < IN
	echo 1: "x[$x] y[$y] z[$z]"
	echo 1a: ${z-z not set}
	read x < IN
	echo 2: "x[$x]"
expected-stdout:
	1: x[A] y[B] z[]
	1a:
	2: x[A B]
---
name: read-IFS-2
description:
	Complex tests, IFS either colon (IFS-NWS) or backslash (tricky)
stdin:
	n=0
	showargs() { print -nr "$1"; shift; for s_arg in "$@"; do print -nr -- " [$s_arg]"; done; print; }
	(IFS=\\ a=\<\\\>; showargs 3 $a)
	(IFS=: b=\<:\>; showargs 4 $b)
	print -r '<\>' | (IFS=\\ read f g; showargs 5 "$f" "$g")
	print -r '<\\>' | (IFS=\\ read f g; showargs 6 "$f" "$g")
	print '<\\\n>' | (IFS=\\ read f g; showargs 7 "$f" "$g")
	print -r '<\>' | (IFS=\\ read f; showargs 8 "$f")
	print -r '<\\>' | (IFS=\\ read f; showargs 9 "$f")
	print '<\\\n>' | (IFS=\\ read f; showargs 10 "$f")
	print -r '<\>' | (IFS=\\ read -r f g; showargs 11 "$f" "$g")
	print -r '<\\>' | (IFS=\\ read -r f g; showargs 12 "$f" "$g")
	print '<\\\n>' | (IFS=\\ read -r f g; showargs 13 "$f" "$g")
	print -r '<\>' | (IFS=\\ read -r f; showargs 14 "$f")
	print -r '<\\>' | (IFS=\\ read -r f; showargs 15 "$f")
	print '<\\\n>' | (IFS=\\ read -r f; showargs 16 "$f")
	print -r '<:>' | (IFS=: read f g; showargs 17 "$f" "$g")
	print -r '<::>' | (IFS=: read f g; showargs 18 "$f" "$g")
	print '<:\n>' | (IFS=: read f g; showargs 19 "$f" "$g")
	print -r '<:>' | (IFS=: read f; showargs 20 "$f")
	print -r '<::>' | (IFS=: read f; showargs 21 "$f")
	print '<:\n>' | (IFS=: read f; showargs 22 "$f")
	print -r '<:>' | (IFS=: read -r f g; showargs 23 "$f" "$g")
	print -r '<::>' | (IFS=: read -r f g; showargs 24 "$f" "$g")
	print '<:\n>' | (IFS=: read -r f g; showargs 25 "$f" "$g")
	print -r '<:>' | (IFS=: read -r f; showargs 26 "$f")
	print -r '<::>' | (IFS=: read -r f; showargs 27 "$f")
	print '<:\n>' | (IFS=: read -r f; showargs 28 "$f")
expected-stdout:
	3 [<] [>]
	4 [<] [>]
	5 [<] [>]
	6 [<] [>]
	7 [<>] []
	8 [<>]
	9 [<\>]
	10 [<>]
	11 [<] [>]
	12 [<] [\>]
	13 [<] []
	14 [<\>]
	15 [<\\>]
	16 [<]
	17 [<] [>]
	18 [<] [:>]
	19 [<] []
	20 [<:>]
	21 [<::>]
	22 [<]
	23 [<] [>]
	24 [<] [:>]
	25 [<] []
	26 [<:>]
	27 [<::>]
	28 [<]
---
name: read-ksh-1
description:
	If no var specified, REPLY is used
stdin:
	echo "abc" > IN
	read < IN
	echo "[$REPLY]";
expected-stdout:
	[abc]
---
name: read-regress-1
description:
	Check a regression of read
file-setup: file 644 "foo"
	foo bar
	baz
	blah
stdin:
	while read a b c; do
		read d
		break
	done <foo
	echo "<$a|$b|$c><$d>"
expected-stdout:
	<foo|bar|><baz>
---
name: read-delim-1
description:
	Check read with delimiters
stdin:
	emit() {
		print -n 'foo bar\tbaz\nblah \0blub\tblech\nmyok meck \0'
	}
	emit | while IFS= read -d "" foo; do print -r -- "<$foo>"; done
	emit | while read -d "" foo; do print -r -- "<$foo>"; done
	emit | while read -d "eh?" foo; do print -r -- "<$foo>"; done
expected-stdout:
	<foo bar	baz
	blah >
	<blub	blech
	myok meck >
	<foo bar	baz
	blah>
	<blub	blech
	myok meck>
	<foo bar	baz
	blah blub	bl>
	<ch
	myok m>
---
name: read-ext-1
description:
	Check read with number of bytes specified, and -A
stdin:
	print 'foo\nbar' >x1
	print -n x >x2
	print 'foo\\ bar baz' >x3
	x1a=u; read x1a <x1
	x1b=u; read -N-1 x1b <x1
	x2a=u; read x2a <x2; r2a=$?
	x2b=u; read -N2 x2c <x2; r2b=$?
	x2c=u; read -n2 x2c <x2; r2c=$?
	x3a=u; read -A x3a <x3
	print -r "x1a=<$x1a>"
	print -r "x1b=<$x1b>"
	print -r "x2a=$r2a<$x2a>"
	print -r "x2b=$r2b<$x2b>"
	print -r "x2c=$r2c<$x2c>"
	print -r "x3a=<${x3a[0]}|${x3a[1]}|${x3a[2]}>"
expected-stdout:
	x1a=<foo>
	x1b=<foo
	bar>
	x2a=1<x>
	x2b=1<u>
	x2c=0<x>
	x3a=<foo bar|baz|>
---
name: regression-1
description:
	Lex array code had problems with this.
stdin:
	echo foo[
	n=bar
	echo "hi[ $n ]=1"
expected-stdout:
	foo[
	hi[ bar ]=1
---
name: regression-2
description:
	When PATH is set before running a command, the new path is
	not used in doing the path search
		$ echo echo hi > /tmp/q ; chmod a+rx /tmp/q
		$ PATH=/tmp q
		q: not found
		$
	in comexec() the two lines
		while (*vp != NULL)
			(void) typeset(*vp++, xxx, 0);
	need to be moved out of the switch to before findcom() is
	called - I don't know what this will break.
stdin:
	: "${PWD:-`pwd 2> /dev/null`}"
	: "${PWD:?"PWD not set - cannot do test"}"
	mkdir Y
	cat > Y/xxxscript << EOF
	#!/bin/sh
	# Need to restore path so echo can be found (some shells don't have
	# it as a built-in)
	PATH=\$OLDPATH
	echo hi
	exit 0
	EOF
	chmod a+rx Y/xxxscript
	export OLDPATH="$PATH"
	PATH=$PWD/Y xxxscript
	exit $?
expected-stdout:
	hi
---
name: regression-6
description:
	Parsing of $(..) expressions is non-optimal.  It is
	impossible to have any parentheses inside the expression.
	I.e.,
		$ ksh -c 'echo $(echo \( )'
		no closing quote
		$ ksh -c 'echo $(echo "(" )'
		no closing quote
		$
	The solution is to hack the parsing clode in lex.c, the
	question is how to hack it: should any parentheses be
	escaped by a backslash, or should recursive parsing be done
	(so quotes could also be used to hide hem).  The former is
	easier, the later better...
stdin:
	echo $(echo \( )
	echo $(echo "(" )
expected-stdout:
	(
	(
---
name: regression-9
description:
	Continue in a for loop does not work right:
		for i in a b c ; do
			if [ $i = b ] ; then
				continue
			fi
			echo $i
		done
	Prints a forever...
stdin:
	first=yes
	for i in a b c ; do
		if [ $i = b ] ; then
			if [ $first = no ] ; then
				echo 'continue in for loop broken'
				break	# hope break isn't broken too :-)
			fi
			first=no
			continue
		fi
	done
	echo bye
expected-stdout:
	bye
---
name: regression-10
description:
	The following:
		set -- `false`
		echo $?
	should print 0 according to POSIX (dash, bash, ksh93, posh)
	but not 0 according to the getopt(1) manual page, ksh88, and
	Bourne sh (such as /bin/sh on Solaris).
	We honour POSIX except when -o sh is set.
category: shell:legacy-no
stdin:
	showf() {
		[[ -o posix ]]; FPOSIX=$((1-$?))
		[[ -o sh ]]; FSH=$((1-$?))
		echo -n "FPOSIX=$FPOSIX FSH=$FSH "
	}
	set +o posix +o sh
	showf
	set -- `false`
	echo rv=$?
	set -o sh
	showf
	set -- `false`
	echo rv=$?
	set -o posix
	showf
	set -- `false`
	echo rv=$?
	set -o posix -o sh
	showf
	set -- `false`
	echo rv=$?
expected-stdout:
	FPOSIX=0 FSH=0 rv=0
	FPOSIX=0 FSH=1 rv=1
	FPOSIX=1 FSH=0 rv=0
	FPOSIX=1 FSH=1 rv=0
---
name: regression-10-legacy
description:
	The following:
		set -- `false`
		echo $?
	should print 0 according to POSIX (dash, bash, ksh93, posh)
	but not 0 according to the getopt(1) manual page, ksh88, and
	Bourne sh (such as /bin/sh on Solaris).
category: shell:legacy-yes
stdin:
	showf() {
		[[ -o posix ]]; FPOSIX=$((1-$?))
		[[ -o sh ]]; FSH=$((1-$?))
		echo -n "FPOSIX=$FPOSIX FSH=$FSH "
	}
	set +o posix +o sh
	showf
	set -- `false`
	echo rv=$?
	set -o sh
	showf
	set -- `false`
	echo rv=$?
	set -o posix
	showf
	set -- `false`
	echo rv=$?
	set -o posix -o sh
	showf
	set -- `false`
	echo rv=$?
expected-stdout:
	FPOSIX=0 FSH=0 rv=1
	FPOSIX=0 FSH=1 rv=1
	FPOSIX=1 FSH=0 rv=0
	FPOSIX=1 FSH=1 rv=0
---
name: regression-11
description:
	The following:
		x=/foo/bar/blah
		echo ${x##*/}
	should echo blah but on some machines echos /foo/bar/blah.
stdin:
	x=/foo/bar/blah
	echo ${x##*/}
expected-stdout:
	blah
---
name: regression-12
description:
	Both of the following echos produce the same output under sh/ksh.att:
		#!/bin/sh
		x="foo	bar"
		echo "`echo \"$x\"`"
		echo "`echo "$x"`"
	pdksh produces different output for the former (foo instead of foo\tbar)
stdin:
	x="foo	bar"
	echo "`echo \"$x\"`"
	echo "`echo "$x"`"
expected-stdout:
	foo	bar
	foo	bar
---
name: regression-13
description:
	The following command hangs forever:
		$ (: ; cat /etc/termcap) | sleep 2
	This is because the shell forks a shell to run the (..) command
	and this shell has the pipe open.  When the sleep dies, the cat
	doesn't get a SIGPIPE 'cause a process (ie, the second shell)
	still has the pipe open.
	
	NOTE: this test provokes a bizarre bug in ksh93 (shell starts reading
	      commands from /etc/termcap..)
time-limit: 10
stdin:
	echo A line of text that will be duplicated quite a number of times.> t1
	cat t1 t1 t1 t1  t1 t1 t1 t1  t1 t1 t1 t1  t1 t1 t1 t1  > t2
	cat t2 t2 t2 t2  t2 t2 t2 t2  t2 t2 t2 t2  t2 t2 t2 t2  > t1
	cat t1 t1 t1 t1 > t2
	(: ; cat t2 2>/dev/null) | sleep 1
---
name: regression-14
description:
	The command
		$ (foobar) 2> /dev/null
	generates no output under /bin/sh, but pdksh produces the error
		foobar: not found
	Also, the command
		$ foobar 2> /dev/null
	generates an error under /bin/sh and pdksh, but AT&T ksh88 produces
	no error (redirected to /dev/null).
stdin:
	(you/should/not/see/this/error/1) 2> /dev/null
	you/should/not/see/this/error/2 2> /dev/null
	true
---
name: regression-15
description:
	The command
		$ whence foobar
	generates a blank line under pdksh and sets the exit status to 0.
	AT&T ksh88 generates no output and sets the exit status to 1.  Also,
	the command
		$ whence foobar cat
	generates no output under AT&T ksh88 (pdksh generates a blank line
	and /bin/cat).
stdin:
	whence does/not/exist > /dev/null
	echo 1: $?
	echo 2: $(whence does/not/exist | wc -l)
	echo 3: $(whence does/not/exist cat | wc -l)
expected-stdout:
	1: 1
	2: 0
	3: 0
---
name: regression-16
description:
	${var%%expr} seems to be broken in many places.  On the mips
	the commands
		$ read line < /etc/passwd
		$ echo $line
		root:0:1:...
		$ echo ${line%%:*}
		root
		$ echo $line
		root
		$
	change the value of line.  On sun4s & pas, the echo ${line%%:*} doesn't
	work.  Haven't checked elsewhere...
script:
	read x
	y=$x
	echo ${x%%:*}
	echo $x
stdin:
	root:asdjhasdasjhs:0:1:Root:/:/bin/sh
expected-stdout:
	root
	root:asdjhasdasjhs:0:1:Root:/:/bin/sh
---
name: regression-17
description:
	The command
		. /foo/bar
	should set the exit status to non-zero (sh and AT&T ksh88 do).
	XXX doting a non existent file is a fatal error for a script
stdin:
	. does/not/exist
expected-exit: e != 0
expected-stderr-pattern: /.?/
---
name: regression-19
description:
	Both of the following echos should produce the same thing, but don't:
		$ x=foo/bar
		$ echo ${x%/*}
		foo
		$ echo "${x%/*}"
		foo/bar
stdin:
	x=foo/bar
	echo "${x%/*}"
expected-stdout:
	foo
---
name: regression-21
description:
	backslash does not work as expected in case labels:
	$ x='-x'
	$ case $x in
	-\?) echo hi
	esac
	hi
	$ x='-?'
	$ case $x in
	-\\?) echo hi
	esac
	hi
	$
stdin:
	case -x in
	-\?)	echo fail
	esac
---
name: regression-22
description:
	Quoting backquotes inside backquotes doesn't work:
	$ echo `echo hi \`echo there\` folks`
	asks for more info.  sh and AT&T ksh88 both echo
	hi there folks
stdin:
	echo `echo hi \`echo there\` folks`
expected-stdout:
	hi there folks
---
name: regression-23
description:
	)) is not treated `correctly':
	    $ (echo hi ; (echo there ; echo folks))
	    missing ((
	    $
	instead of (as sh and ksh.att)
	    $ (echo hi ; (echo there ; echo folks))
	    hi
	    there
	    folks
	    $
stdin:
	( : ; ( : ; echo hi))
expected-stdout:
	hi
---
name: regression-25
description:
	Check reading stdin in a while loop.  The read should only read
	a single line, not a whole stdio buffer; the cat should get
	the rest.
stdin:
	(echo a; echo b) | while read x ; do
	    echo $x
	    cat > /dev/null
	done
expected-stdout:
	a
---
name: regression-26
description:
	Check reading stdin in a while loop.  The read should read both
	lines, not just the first.
script:
	a=
	while [ "$a" != xxx ] ; do
	    last=$x
	    read x
	    cat /dev/null | sed 's/x/y/'
	    a=x$a
	done
	echo $last
stdin:
	a
	b
expected-stdout:
	b
---
name: regression-27
description:
	The command
		. /does/not/exist
	should cause a script to exit.
stdin:
	. does/not/exist
	echo hi
expected-exit: e != 0
expected-stderr-pattern: /does\/not\/exist/
---
name: regression-28
description:
	variable assignements not detected well
stdin:
	a.x=1 echo hi
expected-exit: e != 0
expected-stderr-pattern: /a\.x=1/
---
name: regression-29
description:
	alias expansion different from AT&T ksh88
stdin:
	alias a='for ' b='i in'
	a b hi ; do echo $i ; done
expected-stdout:
	hi
---
name: regression-30
description:
	strange characters allowed inside ${...}
stdin:
	echo ${a{b}}
expected-exit: e != 0
expected-stderr-pattern: /.?/
---
name: regression-31
description:
	Does read handle partial lines correctly
script:
	a= ret=
	while [ "$a" != xxx ] ; do
	    read x y z
	    ret=$?
	    a=x$a
	done
	echo "[$x]"
	echo $ret
stdin: !
	a A aA
	b B Bb
	c
expected-stdout:
	[c]
	1
---
name: regression-32
description:
	Does read set variables to null at eof?
script:
	a=
	while [ "$a" != xxx ] ; do
	    read x y z
	    a=x$a
	done
	echo 1: ${x-x not set} ${y-y not set} ${z-z not set}
	echo 2: ${x:+x not null} ${y:+y not null} ${z:+z not null}
stdin:
	a A Aa
	b B Bb
expected-stdout:
	1:
	2:
---
name: regression-33
description:
	Does umask print a leading 0 when umask is 3 digits?
stdin:
	# on MiNT, the first umask call seems to fail
	umask 022
	# now, the test proper
	umask 222
	umask
expected-stdout:
	0222
---
name: regression-35
description:
	Tempory files used for here-docs in functions get trashed after
	the function is parsed (before it is executed)
stdin:
	f1() {
		cat <<- EOF
			F1
		EOF
		f2() {
			cat <<- EOF
				F2
			EOF
		}
	}
	f1
	f2
	unset -f f1
	f2
expected-stdout:
	F1
	F2
	F2
---
name: regression-36
description:
	Command substitution breaks reading in while loop
	(test from <sjg@void.zen.oz.au>)
stdin:
	(echo abcdef; echo; echo 123) |
	    while read line
	    do
	      # the following line breaks it
	      c=`echo $line | wc -c`
	      echo $c
	    done
expected-stdout:
	7
	1
	4
---
name: regression-37
description:
	Machines with broken times() (reported by <sjg@void.zen.oz.au>)
	time does not report correct real time
stdin:
	time sleep 1
expected-stderr-pattern: !/^\s*0\.0[\s\d]+real|^\s*real[\s]+0+\.0/
---
name: regression-38
description:
	set -e doesn't ignore exit codes for if/while/until/&&/||/!.
arguments: !-e!
stdin:
	if false; then echo hi ; fi
	false || true
	false && true
	while false; do echo hi; done
	echo ok
expected-stdout:
	ok
---
name: regression-39
description:
	Only posh and oksh(2013-07) say ‚Äúhi‚Äù below; FreeBSD sh,
	GNU bash in POSIX mode, dash, ksh93, mksh don‚Äôt. All of
	them exit 0. The POSIX behaviour is needed by BSD make.
stdin:
	set -e
	echo `false; echo hi` $(<this-file-does-not-exist)
	echo $?
expected-stdout:
	
	0
expected-stderr-pattern: /this-file-does-not-exist/
---
name: regression-40
description:
	This used to cause a core dump
env-setup: !RANDOM=12!
stdin:
	echo hi
expected-stdout:
	hi
---
name: regression-41
description:
	foo should be set to bar (should not be empty)
stdin:
	foo=`
	echo bar`
	echo "($foo)"
expected-stdout:
	(bar)
---
name: regression-42
description:
	Can't use command line assignments to assign readonly parameters.
stdin:
	print '#!'"$__progname"'\nunset RANDOM\nexport | while IFS= read -r' \
	    'RANDOM; do eval '\''print -r -- "$RANDOM=$'\''"$RANDOM"'\'\"\'\; \
	    done >env; chmod +x env; PATH=.$PATHSEP$PATH
	foo=bar
	readonly foo
	foo=stuff env | grep '^foo'
expected-exit: e != 0
expected-stderr-pattern:
	/read-only/
---
name: regression-43
description:
	Can subshells be prefixed by redirections (historical shells allow
	this)
stdin:
	< /dev/null (sed 's/^/X/')
---
name: regression-45
description:
	Parameter assignments with [] recognised correctly
stdin:
	FOO=*[12]
	BAR=abc[
	MORE=[abc]
	JUNK=a[bc
	echo "<$FOO>"
	echo "<$BAR>"
	echo "<$MORE>"
	echo "<$JUNK>"
expected-stdout:
	<*[12]>
	<abc[>
	<[abc]>
	<a[bc>
---
name: regression-46
description:
	Check that alias expansion works in command substitutions and
	at the end of file.
stdin:
	alias x='echo hi'
	FOO="`x` "
	echo "[$FOO]"
	x
expected-stdout:
	[hi ]
	hi
---
name: regression-47
description:
	Check that aliases are fully read.
stdin:
	alias x='echo hi;
	echo there'
	x
	echo done
expected-stdout:
	hi
	there
	done
---
name: regression-48
description:
	Check that (here doc) temp files are not left behind after an exec.
stdin:
	mkdir foo || exit 1
	TMPDIR=$PWD/foo "$__progname" <<- 'EOF'
		x() {
			sed 's/^/X /' << E_O_F
			hi
			there
			folks
			E_O_F
			echo "done ($?)"
		}
		echo=echo; [ -x /bin/echo ] && echo=/bin/echo
		exec $echo subtest-1 hi
	EOF
	echo subtest-1 foo/*
	TMPDIR=$PWD/foo "$__progname" <<- 'EOF'
		echo=echo; [ -x /bin/echo ] && echo=/bin/echo
		sed 's/^/X /' << E_O_F; exec $echo subtest-2 hi
		a
		few
		lines
		E_O_F
	EOF
	echo subtest-2 foo/*
expected-stdout:
	subtest-1 hi
	subtest-1 foo/*
	X a
	X few
	X lines
	subtest-2 hi
	subtest-2 foo/*
---
name: regression-49
description:
	Check that unset params with attributes are reported by set, those
	sans attributes are not.
stdin:
	unset FOO BAR
	echo X$FOO
	export BAR
	typeset -i BLAH
	set | grep FOO
	set | grep BAR
	set | grep BLAH
expected-stdout:
	X
	BAR
	BLAH
---
name: regression-50
description:
	Check that aliases do not use continuation prompt after trailing
	semi-colon.
file-setup: file 644 "envf"
	PS1=Y
	PS2=X
env-setup: !ENV=./envf!
need-ctty: yes
arguments: !-i!
stdin:
	alias foo='echo hi ; '
	foo
	foo echo there
expected-stdout:
	hi
	hi
	there
expected-stderr: !
	YYYY
---
name: regression-51
description:
	Check that set allows both +o and -o options on same command line.
stdin:
	set a b c
	set -o noglob +o allexport
	echo A: $*, *
expected-stdout:
	A: a b c, *
---
name: regression-52
description:
	Check that globbing works in pipelined commands
file-setup: file 644 "envf"
	PS1=P
file-setup: file 644 "abc"
	stuff
env-setup: !ENV=./envf!
need-ctty: yes
arguments: !-i!
stdin:
	sed 's/^/X /' < ab*
	echo mark 1
	sed 's/^/X /' < ab* | sed 's/^/Y /'
	echo mark 2
expected-stdout:
	X stuff
	mark 1
	Y X stuff
	mark 2
expected-stderr: !
	PPPPP
---
name: regression-53
description:
	Check that getopts works in functions
stdin:
	bfunc() {
	    echo bfunc: enter "(args: $*; OPTIND=$OPTIND)"
	    while getopts B oc; do
		case $oc in
		  (B)
		    echo bfunc: B option
		    ;;
		  (*)
		    echo bfunc: odd option "($oc)"
		    ;;
		esac
	    done
	    echo bfunc: leave
	}
	
	function kfunc {
	    echo kfunc: enter "(args: $*; OPTIND=$OPTIND)"
	    while getopts K oc; do
		case $oc in
		  (K)
		    echo kfunc: K option
		    ;;
		  (*)
		    echo bfunc: odd option "($oc)"
		    ;;
		esac
	    done
	    echo kfunc: leave
	}
	
	set -- -f -b -k -l
	echo "line 1: OPTIND=$OPTIND"
	getopts kbfl optc
	echo "line 2: ret=$?, optc=$optc, OPTIND=$OPTIND"
	bfunc -BBB blah
	echo "line 3: OPTIND=$OPTIND"
	getopts kbfl optc
	echo "line 4: ret=$?, optc=$optc, OPTIND=$OPTIND"
	kfunc -KKK blah
	echo "line 5: OPTIND=$OPTIND"
	getopts kbfl optc
	echo "line 6: ret=$?, optc=$optc, OPTIND=$OPTIND"
	echo
	
	OPTIND=1
	set -- -fbkl
	echo "line 10: OPTIND=$OPTIND"
	getopts kbfl optc
	echo "line 20: ret=$?, optc=$optc, OPTIND=$OPTIND"
	bfunc -BBB blah
	echo "line 30: OPTIND=$OPTIND"
	getopts kbfl optc
	echo "line 40: ret=$?, optc=$optc, OPTIND=$OPTIND"
	kfunc -KKK blah
	echo "line 50: OPTIND=$OPTIND"
	getopts kbfl optc
	echo "line 60: ret=$?, optc=$optc, OPTIND=$OPTIND"
expected-stdout:
	line 1: OPTIND=1
	line 2: ret=0, optc=f, OPTIND=2
	bfunc: enter (args: -BBB blah; OPTIND=2)
	bfunc: B option
	bfunc: B option
	bfunc: leave
	line 3: OPTIND=2
	line 4: ret=0, optc=b, OPTIND=3
	kfunc: enter (args: -KKK blah; OPTIND=1)
	kfunc: K option
	kfunc: K option
	kfunc: K option
	kfunc: leave
	line 5: OPTIND=3
	line 6: ret=0, optc=k, OPTIND=4
	
	line 10: OPTIND=1
	line 20: ret=0, optc=f, OPTIND=2
	bfunc: enter (args: -BBB blah; OPTIND=2)
	bfunc: B option
	bfunc: B option
	bfunc: leave
	line 30: OPTIND=2
	line 40: ret=1, optc=?, OPTIND=2
	kfunc: enter (args: -KKK blah; OPTIND=1)
	kfunc: K option
	kfunc: K option
	kfunc: K option
	kfunc: leave
	line 50: OPTIND=2
	line 60: ret=1, optc=?, OPTIND=2
---
name: regression-54
description:
	Check that ; is not required before the then in if (( ... )) then ...
stdin:
	if (( 1 )) then
	    echo ok dparen
	fi
	if [[ -n 1 ]] then
	    echo ok dbrackets
	fi
expected-stdout:
	ok dparen
	ok dbrackets
---
name: regression-55
description:
	Check ${foo:%bar} is allowed (ksh88 allows it...)
stdin:
	x=fooXbarXblah
	echo 1 ${x%X*}
	echo 2 ${x:%X*}
	echo 3 ${x%%X*}
	echo 4 ${x:%%X*}
	echo 5 ${x#*X}
	echo 6 ${x:#*X}
	echo 7 ${x##*X}
	echo 8 ${x:##*X}
expected-stdout:
	1 fooXbar
	2 fooXbar
	3 foo
	4 foo
	5 barXblah
	6 barXblah
	7 blah
	8 blah
---
name: regression-57
description:
	Check if typeset output is correct for
	uninitialised array elements.
stdin:
	typeset -i xxx[4]
	echo A
	typeset -i | grep xxx | sed 's/^/    /'
	echo B
	typeset | grep xxx | sed 's/^/    /'
	
	xxx[1]=2+5
	echo M
	typeset -i | grep xxx | sed 's/^/    /'
	echo N
	typeset | grep xxx | sed 's/^/    /'
expected-stdout:
	A
	    xxx
	B
	    typeset -i xxx
	M
	    xxx[1]=7
	N
	    set -A xxx
	    typeset -i xxx[1]
---
name: regression-58
description:
	Check if trap exit is ok (exit not mistaken for signal name)
stdin:
	trap 'echo hi' exit
	trap exit 1
expected-stdout:
	hi
---
name: regression-59
description:
	Check if ${#array[*]} is calculated correctly.
stdin:
	a[12]=hi
	a[8]=there
	echo ${#a[*]}
expected-stdout:
	2
---
name: regression-60
description:
	Check if default exit status is previous command
stdin:
	(true; exit)
	echo A $?
	(false; exit)
	echo B $?
	( (exit 103) ; exit)
	echo C $?
expected-stdout:
	A 0
	B 1
	C 103
---
name: regression-61
description:
	Check if EXIT trap is executed for sub shells.
stdin:
	trap 'echo parent exit' EXIT
	echo start
	(echo A; echo A last)
	echo B
	(echo C; trap 'echo sub exit' EXIT; echo C last)
	echo parent last
expected-stdout:
	start
	A
	A last
	B
	C
	C last
	sub exit
	parent last
	parent exit
---
name: regression-62
description:
	Check if test -nt/-ot succeeds if second(first) file is missing.
stdin:
	matrix() {
		local a b c d e f g h
		test a -nt b; a=$?
		test b -nt a; b=$?
		test a -ot b; c=$?
		test b -ot a; d=$?
		test a -nt a; e=$?
		test b -nt b; f=$?
		test a -ot a; g=$?
		test b -ot b; h=$?
		echo $1 $a $b $c $d / $e $f $g $h .
	}
	matrix a
	:>a
	matrix b
	sleep 2		# mtime granularity for OS/2 and FAT
	:>b
	matrix c
	sleep 2
	echo dummy >a	# Debian GNU/Hurd #955270
	matrix d
	rm a
	matrix e
expected-stdout:
	a 1 1 1 1 / 1 1 1 1 .
	b 0 1 1 0 / 1 1 1 1 .
	c 1 0 0 1 / 1 1 1 1 .
	d 0 1 1 0 / 1 1 1 1 .
	e 1 0 0 1 / 1 1 1 1 .
---
name: regression-63
description:
	Check if typeset, export, and readonly work
stdin:
	{
		echo FNORD-0
		FNORD_A=1
		FNORD_B=2
		FNORD_C=3
		FNORD_D=4
		FNORD_E=5
		FNORD_F=6
		FNORD_G=7
		FNORD_H=8
		integer FNORD_E FNORD_F FNORD_G FNORD_H
		export FNORD_C FNORD_D FNORD_G FNORD_H
		readonly FNORD_B FNORD_D FNORD_F FNORD_H
		echo FNORD-1
		export
		echo FNORD-2
		export -p
		echo FNORD-3
		readonly
		echo FNORD-4
		readonly -p
		echo FNORD-5
		typeset
		echo FNORD-6
		typeset -p
		echo FNORD-7
		typeset -
		echo FNORD-8
	} | fgrep FNORD
	fnord=(42 23)
	typeset -p fnord
	echo FNORD-9
expected-stdout:
	FNORD-0
	FNORD-1
	FNORD_C
	FNORD_D
	FNORD_G
	FNORD_H
	FNORD-2
	export FNORD_C=3
	export FNORD_D=4
	export FNORD_G=7
	export FNORD_H=8
	FNORD-3
	FNORD_B
	FNORD_D
	FNORD_F
	FNORD_H
	FNORD-4
	readonly FNORD_B=2
	readonly FNORD_D=4
	readonly FNORD_F=6
	readonly FNORD_H=8
	FNORD-5
	typeset FNORD_A
	typeset -r FNORD_B
	typeset -x FNORD_C
	typeset -x -r FNORD_D
	typeset -i FNORD_E
	typeset -i -r FNORD_F
	typeset -i -x FNORD_G
	typeset -i -x -r FNORD_H
	FNORD-6
	typeset FNORD_A=1
	typeset -r FNORD_B=2
	typeset -x FNORD_C=3
	typeset -x -r FNORD_D=4
	typeset -i FNORD_E=5
	typeset -i -r FNORD_F=6
	typeset -i -x FNORD_G=7
	typeset -i -x -r FNORD_H=8
	FNORD-7
	FNORD_A=1
	FNORD_B=2
	FNORD_C=3
	FNORD_D=4
	FNORD_E=5
	FNORD_F=6
	FNORD_G=7
	FNORD_H=8
	FNORD-8
	set -A fnord
	typeset fnord[0]=42
	typeset fnord[1]=23
	FNORD-9
---
name: regression-64
description:
	Check that we can redefine functions calling time builtin
stdin:
	t() {
		time >/dev/null
	}
	t 2>/dev/null
	t() {
		time
	}
---
name: regression-65
description:
	check for a regression with sleep builtin and signal mask
category: !nojsig
time-limit: 5
stdin:
	sleep 1
	echo blub |&
	while read -p line; do :; done
	echo ok
expected-stdout:
	ok
---
name: regression-66
description:
	Check that quoting is sane
category: !nojsig
stdin:
	ac_space=' '
	ac_newline='
	'
	set | grep ^ac_ |&
	set -A lines
	while IFS= read -pr line; do
		if [[ $line = *space* ]]; then
			lines[0]=$line
		else
			lines[1]=$line
		fi
	done
	for line in "${lines[@]}"; do
		print -r -- "$line"
	done
expected-stdout:
	ac_space=' '
	ac_newline=$'\n'
---
name: regression-67
description:
	Check that we can both break and use source on the same line
stdin:
	for s in s; do break; done; print -s s
---
name: regression-68
description:
	Check that all common arithmetic operators work as expected
stdin:
	echo 1 $(( a = 5 )) .
	echo 2 $(( ++a )) , $(( a++ )) , $(( a )) .
	echo 3 $(( --a )) , $(( a-- )) , $(( a )) .
	echo 4 $(( a == 5 )) , $(( a == 6 )) .
	echo 5 $(( a != 5 )) , $(( a != 6 )) .
	echo 6 $(( a *= 3 )) .
	echo 7 $(( a /= 5 )) .
	echo 8 $(( a %= 2 )) .
	echo 9 $(( a += 9 )) .
	echo 10 $(( a -= 4 )) .
	echo 11 $(( a <<= 1 )) .
	echo 12 $(( a >>= 1 )) .
	echo 13 $(( a &= 4 )) .
	echo 14 $(( a ^= a )) .
	echo 15 $(( a |= 5 )) .
	echo 16 $(( 5 << 1 )) .
	echo 17 $(( 5 >> 1 )) .
	echo 18 $(( 5 <= 6 )) , $(( 5 <= 5 )) , $(( 5 <= 4 )) .
	echo 19 $(( 5 >= 6 )) , $(( 5 >= 5 )) , $(( 5 >= 4 )) .
	echo 20 $(( 5 < 6 )) , $(( 5 < 5 )) , $(( 5 < 4 )) .
	echo 21 $(( 5 > 6 )) , $(( 5 > 5 )) , $(( 5 > 4 )) .
	echo 22 $(( 0 && 0 )) , $(( 0 && 1 )) , $(( 1 && 0 )) , $(( 1 && 1 )) .
	echo 23 $(( 0 || 0 )) , $(( 0 || 1 )) , $(( 1 || 0 )) , $(( 1 || 1 )) .
	echo 24 $(( 5 * 3 )) .
	echo 25 $(( 7 / 2 )) .
	echo 26 $(( 5 % 5 )) , $(( 5 % 4 )) , $(( 5 % 1 )) , $(( 5 % -1 )) , $(( 5 % -2 )) .
	echo 27 $(( 5 + 2 )) , $(( 5 + 0 )) , $(( 5 + -2 )) .
	echo 28 $(( 5 - 2 )) , $(( 5 - 0 )) , $(( 5 - -2 )) .
	echo 29 $(( 6 & 4 )) , $(( 6 & 8 )) .
	echo 30 $(( 4 ^ 2 )) , $(( 4 ^ 4 )) .
	echo 31 $(( 4 | 2 )) , $(( 4 | 4 )) , $(( 4 | 0 )) .
	echo 32 $(( 0 ? 1 : 2 )) , $(( 3 ? 4 : 5 )) .
	echo 33 $(( 5 , 2 , 3 )) .
	echo 34 $(( ~0 )) , $(( ~1 )) , $(( ~~1 )) , $(( ~~2 )) .
	echo 35 $(( !0 )) , $(( !1 )) , $(( !!1 )) , $(( !!2 )) .
	echo 36 $(( (5) )) .
expected-stdout:
	1 5 .
	2 6 , 6 , 7 .
	3 6 , 6 , 5 .
	4 1 , 0 .
	5 0 , 1 .
	6 15 .
	7 3 .
	8 1 .
	9 10 .
	10 6 .
	11 12 .
	12 6 .
	13 4 .
	14 0 .
	15 5 .
	16 10 .
	17 2 .
	18 1 , 1 , 0 .
	19 0 , 1 , 1 .
	20 1 , 0 , 0 .
	21 0 , 0 , 1 .
	22 0 , 0 , 0 , 1 .
	23 0 , 1 , 1 , 1 .
	24 15 .
	25 3 .
	26 0 , 1 , 0 , 0 , 1 .
	27 7 , 5 , 3 .
	28 3 , 5 , 7 .
	29 4 , 0 .
	30 6 , 0 .
	31 6 , 4 , 4 .
	32 2 , 4 .
	33 3 .
	34 -1 , -2 , 1 , 2 .
	35 1 , 0 , 1 , 1 .
	36 5 .
---
name: regression-69
description:
	Check that all non-lksh arithmetic operators work as expected
category: shell:legacy-no
stdin:
	a=5 b=0x80000005
	echo 1 $(( a ^<= 1 )) , $(( b ^<= 1 )) .
	echo 2 $(( a ^>= 2 )) , $(( b ^>= 2 )) .
	echo 3 $(( 5 ^< 1 )) .
	echo 4 $(( 5 ^> 1 )) .
expected-stdout:
	1 10 , 11 .
	2 -2147483646 , -1073741822 .
	3 10 .
	4 -2147483646 .
---
name: export-1
description:
	Check allexport works, basic
stdin:
	qa=1
	set -A qb 2 3
	set -a
	qc=4
	set -A qd 5 6
	export -p | grep '^export q'
expected-stdout:
	export qc=4
	export qd[0]=5
	export qd[1]=6
---
name: readonly-0
description:
	Ensure readonly is honoured for assignments and unset
stdin:
	"$__progname" -c 'u=x; echo $? $u .' || echo aborted, $?
	echo =
	"$__progname" -c 'readonly u; u=x; echo $? $u .' || echo aborted, $?
	echo =
	"$__progname" -c 'u=x; readonly u; unset u; echo $? $u .' || echo aborted, $?
expected-stdout:
	0 x .
	=
	aborted, 2
	=
	1 x .
expected-stderr-pattern:
	/read-only/
---
name: readonly-1
description:
	http://austingroupbugs.net/view.php?id=367 for export
stdin:
	"$__progname" -c 'readonly foo; export foo=a; echo $?' || echo aborted, $?
expected-stdout:
	aborted, 2
expected-stderr-pattern:
	/read-only/
---
name: readonly-2a
description:
	Check that getopts works as intended, for readonly-2b to be valid
stdin:
	"$__progname" -c 'set -- -a b; getopts a c; echo $? $c .; getopts a c; echo $? $c .' || echo aborted, $?
expected-stdout:
	0 a .
	1 ? .
---
name: readonly-2b
description:
	http://austingroupbugs.net/view.php?id=367 for getopts
stdin:
	"$__progname" -c 'readonly c; set -- -a b; getopts a c; echo $? $c .' || echo aborted, $?
expected-stdout:
	2 .
expected-stderr-pattern:
	/read-only/
---
name: readonly-3
description:
	http://austingroupbugs.net/view.php?id=367 for read
stdin:
	echo x | "$__progname" -c 'read s; echo $? $s .' || echo aborted, $?
	echo y | "$__progname" -c 'readonly s; read s; echo $? $s .' || echo aborted, $?
expected-stdout:
	0 x .
	2 .
expected-stderr-pattern:
	/read-only/
---
name: readonly-4
description:
	Do not permit bypassing readonly for first array item
stdin:
	set -A arr -- foo bar
	readonly arr
	arr=baz
	print -r -- "${arr[@]}"
expected-exit: e != 0
expected-stderr-pattern:
	/read[ -]?only/
---
name: readonly-5
description:
	Ensure readonly is idempotent
stdin:
	readonly x=1
	readonly x
---
name: syntax-1
description:
	Check that lone ampersand is a syntax error
stdin:
	 &
expected-exit: e != 0
expected-stderr-pattern:
	/syntax error/
---
name: xxx-quoted-newline-1
description:
	Check that \<newline> works inside of ${}
stdin:
	abc=2
	echo ${ab\
	c}
expected-stdout:
	2
---
name: xxx-quoted-newline-2
description:
	Check that \<newline> works at the start of a here document
stdin:
	cat << EO\
	F
	hi
	EOF
expected-stdout:
	hi
---
name: xxx-quoted-newline-3
description:
	Check that \<newline> works at the end of a here document
stdin:
	cat << EOF
	hi
	EO\
	F
expected-stdout:
	hi
---
name: xxx-multi-assignment-cmd
description:
	Check that assignments in a command affect subsequent assignments
	in the same command
stdin:
	FOO=abc
	FOO=123 BAR=$FOO
	echo $BAR
expected-stdout:
	123
---
name: xxx-multi-assignment-posix-cmd
description:
	Check that the behaviour for multiple assignments with a
	command name matches POSIX. See:
	http://thread.gmane.org/gmane.comp.standards.posix.austin.general/1925
stdin:
	X=a Y=b; X=$Y Y=$X "$__progname" -c 'echo 1 $X $Y .'; echo 2 $X $Y .
	unset X Y Z
	X=a Y=${X=b} Z=$X "$__progname" -c 'echo 3 $Z .'
	unset X Y Z
	X=a Y=${X=b} Z=$X; echo 4 $Z .
expected-stdout:
	1 b a .
	2 a b .
	3 b .
	4 a .
---
name: xxx-multi-assignment-posix-nocmd
description:
	Check that the behaviour for multiple assignments with no
	command name matches POSIX (Debian #334182). See:
	http://thread.gmane.org/gmane.comp.standards.posix.austin.general/1925
stdin:
	X=a Y=b; X=$Y Y=$X; echo 1 $X $Y .
expected-stdout:
	1 b b .
---
name: xxx-multi-assignment-posix-subassign
description:
	Check that the behaviour for multiple assignments matches POSIX:
	- The assignment words shall be expanded in the current execution
	  environment.
	- The assignments happen in the temporary execution environment.
stdin:
	unset X Y Z
	Z=a Y=${X:=b} sh -c 'echo +$X+ +$Y+ +$Z+'
	echo /$X/
	# Now for the special case:
	unset X Y Z
	X= Y=${X:=b} sh -c 'echo +$X+ +$Y+'
	echo /$X/
expected-stdout:
	++ +b+ +a+
	/b/
	++ +b+
	/b/
---
name: xxx-exec-environment-1
description:
	Check to see if exec sets it's environment correctly
stdin:
	print '#!'"$__progname"'\nunset RANDOM\nexport | while IFS= read -r' \
	    'RANDOM; do eval '\''print -r -- "$RANDOM=$'\''"$RANDOM"'\'\"\'\; \
	    done >env; chmod +x env; PATH=.$PATHSEP$PATH
	FOO=bar exec env
expected-stdout-pattern:
	/(^|.*\n)FOO=bar\n/
---
name: xxx-exec-environment-2
description:
	Check to make sure exec doesn't change environment if a program
	isn't exec-ed
stdin:
	print '#!'"$__progname"'\nunset RANDOM\nexport | while IFS= read -r' \
	    'RANDOM; do eval '\''print -r -- "$RANDOM=$'\''"$RANDOM"'\'\"\'\; \
	    done >env; chmod +x env; PATH=.$PATHSEP$PATH
	env >bar1
	FOO=bar exec; env >bar2
	cmp -s bar1 bar2
---
name: exec-function-environment-1
description:
	Check assignments in function calls and whether they affect
	the current execution environment
stdin:
	f() { a=2; }; g() { b=3; echo y$c-; }; a=1 f; b=2; c=1 g
	echo x$a-$b- z$c-
expected-stdout:
	y1-
	x-3- z-
---
name: exec-modern-korn-shell
description:
	Check that exec can execute any command that makes it
	through syntax and parser
stdin:
	print '#!'"$__progname"'\necho tf' >lq
	chmod +x lq
	PATH=$PWD
	exec 2>&1
	foo() { print two; }
	print =1
	(exec print one)
	print =2
	(exec foo)
	print =3
	(exec ls)
	print =4
	(exec lq)
expected-stdout-pattern:
	/=1\none\n=2\ntwo\n=3\n.*: ls: inaccessible or not found\n=4\ntf\n/
---
name: exec-ksh88
description:
	Check that exec only executes after a PATH search
arguments: !-o!posix!
stdin:
	print '#!'"$__progname"'\necho tf' >lq
	chmod +x lq
	PATH=$PWD
	exec 2>&1
	foo() { print two; }
	print =1
	(exec print one)
	print =2
	(exec foo)
	print =3
	(exec ls)
	print =4
	(exec lq)
expected-stdout-pattern:
	/=1\n.*: print: inaccessible or not found\n=2\n.*: foo: inaccessible or not found\n=3\n.*: ls: inaccessible or not found\n=4\ntf\n/
---
name: xxx-what-do-you-call-this-1
stdin:
	echo "${foo:-"a"}*"
expected-stdout:
	a*
---
name: xxx-prefix-strip-1
stdin:
	foo='a cdef'
	echo ${foo#a c}
expected-stdout:
	def
---
name: xxx-prefix-strip-2
stdin:
	set a c
	x='a cdef'
	echo ${x#$*}
expected-stdout:
	def
---
name: xxx-variable-syntax-1
stdin:
	echo ${:}
expected-stderr-pattern:
	/bad substitution/
expected-exit: 1
---
name: xxx-variable-syntax-2
stdin:
	set 0
	echo ${*:0}
expected-stderr-pattern:
	/bad substitution/
expected-exit: 1
---
name: xxx-variable-syntax-3
stdin:
	set -A foo 0
	echo ${foo[*]:0}
expected-stderr-pattern:
	/bad substitution/
expected-exit: 1
---
name: xxx-variable-syntax-4
description:
	Not all kinds of trims are currently impossible, check those who do
stdin:
	foo() {
		echo "<$*> X${*:+ }X"
	}
	foo a b
	foo "" c
	foo ""
	foo "" ""
	IFS=:
	foo a b
	foo "" c
	foo ""
	foo "" ""
	IFS=
	foo a b
	foo "" c
	foo ""
	foo "" ""
expected-stdout:
	<a b> X X
	< c> X X
	<> XX
	< > X X
	<a:b> X X
	<:c> X X
	<> XX
	<:> X X
	<ab> X X
	<c> X X
	<> XX
	<> XX
---
name: xxx-substitution-eval-order
description:
	Check order of evaluation of expressions
stdin:
	i=1 x= y=
	set -A A abc def GHI j G k
	echo ${A[x=(i+=1)]#${A[y=(i+=2)]}}
	echo $x $y
expected-stdout:
	HI
	2 4
---
name: xxx-substitution-eval-order-2
description:
	Check some corner cases
stdin:
	unset var
	i=42
	: ${var+${q[i=777]}} required to be lazy by POSIX
	echo 1=$i
	var=meow
	i=42
	: ${var+${q[i=777]}} eval since var is now set
	echo 2=$i
	unset var
	i=42
	: ${var#${q[i=777]}} pattern is needed even if var is empty
	echo 3=$i
	var=meow
	i=42
	: ${var#${q[i=777]}}
	echo 4=$i
expected-stdout:
	1=42
	2=777
	3=777
	4=777
---
name: xxx-set-option-1
description:
	Check option parsing in set
stdin:
	set -vsA foo -- A 1 3 2
	echo ${foo[*]}
expected-stderr:
	echo ${foo[*]}
expected-stdout:
	1 2 3 A
---
name: xxx-exec-1
description:
	Check that exec exits for built-ins
need-ctty: yes
arguments: !-i!
stdin:
	exec echo hi
	echo still herre
expected-stdout:
	hi
expected-stderr-pattern: /.*/
---
name: xxx-while-1
description:
	Check the return value of while loops
	XXX need to do same for for/select/until loops
stdin:
	i=x
	while [ $i != xxx ] ; do
	    i=x$i
	    if [ $i = xxx ] ; then
		false
		continue
	    fi
	done
	echo loop1=$?
	
	i=x
	while [ $i != xxx ] ; do
	    i=x$i
	    if [ $i = xxx ] ; then
		false
		break
	    fi
	done
	echo loop2=$?
	
	i=x
	while [ $i != xxx ] ; do
	    i=x$i
	    false
	done
	echo loop3=$?
expected-stdout:
	loop1=0
	loop2=0
	loop3=1
---
name: xxx-status-1
description:
	Check that blank lines don't clear $?
need-ctty: yes
arguments: !-i!
stdin:
	(exit 1)
	echo $?
	(exit 1)
	
	echo $?
	true
expected-stdout:
	1
	1
expected-stderr-pattern: /.*/
---
name: xxx-status-2
description:
	Check that $? is preserved in subshells, includes, traps.
stdin:
	(exit 1)
	
	echo blank: $?
	
	(exit 2)
	(echo subshell: $?)
	
	echo 'echo include: $?' > foo
	(exit 3)
	. ./foo
	
	trap 'echo trap: $?' ERR
	(exit 4)
	echo exit: $?
expected-stdout:
	blank: 1
	subshell: 2
	include: 3
	trap: 4
	exit: 4
---
name: xxx-stat-1
description:
	Check that tests on files are consistent
	(fails when run as root, unfortunately)
category: disabled
stdin:
	mkdir a
	echo x >a/b
	test -e a/b; echo 1e $? .
	test -f a/b; echo 1f $? .
	chmod 0 a
	test -e a/b; echo 2e $? .
	test -f a/b; echo 2f $? .
	chmod 700 a
	test -e a/b; echo 3e $? .
	test -f a/b; echo 3f $? .
expected-stdout:
	1e 0 .
	1f 0 .
	2e 1 .
	2f 1 .
	3e 0 .
	3f 0 .
---
name: xxx-clean-chars-1
description:
	Check MAGIC character is stuffed correctly
stdin:
	echo `echo [£`
expected-stdout:
	[£
---
name: xxx-param-subst-qmark-1
description:
	Check suppresion of error message with null string.  According to
	POSIX, it shouldn't print the error as 'word' isn't ommitted.
	ksh88/93, Solaris /bin/sh and /usr/xpg4/bin/sh all print the error.
stdin:
	unset foo
	x=
	echo x${foo?$x}
expected-exit: 1
expected-stderr-pattern: !/not set/
---
name: xxx-param-subst-qmark-namespec
description:
	Check special names are output correctly
stdin:
	doit() {
		"$__progname" -c "$@" >o1 2>o2
		rv=$?
		echo RETVAL: $rv
		sed -e "s^${__progname%.exe}\.*e*x*e*: PROG: " -e 's/^/STDOUT: /g' <o1
		sed -e "s^${__progname%.exe}\.*e*x*e*: PROG: " -e 's/^/STDERR: /g' <o2
	}
	doit 'echo ${1x}'
	doit 'echo "${1x}"'
	doit 'echo ${1?}'
	doit 'echo ${19?}'
	doit 'echo ${!:?}'
	doit -u 'echo ${*:?}' foo ""
expected-stdout:
	RETVAL: 1
	STDERR: PROG: ${1x}: bad substitution
	RETVAL: 1
	STDERR: PROG: ${1x}: bad substitution
	RETVAL: 1
	STDERR: PROG: 1: parameter null or not set
	RETVAL: 1
	STDERR: PROG: 19: parameter null or not set
	RETVAL: 1
	STDERR: PROG: !: parameter null or not set
	RETVAL: 1
	STDERR: foo: ${*:?}: bad substitution
---
name: xxx-param-_-1
# fails due to weirdness of execv stuff
category: !os:uwin-nt
description:
	Check c flag is set.
arguments: !-c!echo "[$-]"!
expected-stdout-pattern: /^\[.*c.*\]$/
---
name: tilde-expand-1
description:
	Check tilde expansion after equal signs
env-setup: !HOME=/sweet!
stdin:
	echo ${A=a=}~ b=~ c=d~ ~
	export e=~ f=d~
	command command export g=~ h=d~
	echo ". $e . $f ."
	echo ". $g . $h ."
	set -o posix
	unset A e f g h
	echo ${A=a=}~ b=~ c=d~ ~
	export e=~ f=d~
	command command export g=~ h=d~
	echo ". $e . $f ."
	echo ". $g . $h ."
expected-stdout:
	a=/sweet b=/sweet c=d~ /sweet
	. /sweet . d~ .
	. /sweet . d~ .
	a=~ b=~ c=d~ /sweet
	. /sweet . d~ .
	. /sweet . d~ .
---
name: tilde-expand-2
description:
	Check tilde expansion works
env-setup: !HOME=/sweet!
stdin:
	:>'c=a'
	typeset c=[ab]
	:>'d=a'
	x=typeset; $x d=[ab]
	echo "<$c>" "<$d>"
	wd=$PWD
	cd /
	plus=$(print -r -- ~+)
	minus=$(print -r -- ~-)
	nix=$(print -r -- ~)
	[[ $plus = / ]]; echo one $? .
	[[ $minus = "$wd" ]]; echo two $? .
	[[ $nix = /sweet ]]; echo nix $? .
expected-stdout:
	<[ab]> <a>
	one 0 .
	two 0 .
	nix 0 .
---
name: tilde-expand-3
description:
	Check mostly Austin 351 stuff
stdin:
	showargs() { for s_arg in "$@"; do echo -n "<$s_arg> "; done; echo .; }
	set "1 b=2" "3 d=4"
	export a=$1 \c=$2
	showargs 1 "$a" "$b" "$c" "$d"
	unset a b c d
	HOME=/tmp
	export \a=~ b=~
	command export c=~
	builtin export d=~
	\\builtin export e=~
	showargs 2 "$a" "$b" "$c" "$d" "$e" ksh
	unset a b c d e
	set -o posix
	export \a=~ b=~
	command export c=~
	builtin export d=~
	\\builtin export e=~
	showargs 3 "$a" "$b" "$c" "$d" "$e" posix
	unset a b c d e
	set +o posix
	export a=$1
	showargs 4 "$a" "$b" ksh
	unset a b
	showargs 5 a=$1 ksh
	export \a=$1
	showargs 6 "$a" "$b" ksh
	unset a b
	set -o posix
	export a=$1
	showargs 7 "$a" "$b" posix
	unset a b
	showargs 8 a=$1 posix
	export \a=$1
	showargs 9 "$a" "$b" posix
	unset a b
	set +o posix
	command echo 10 ksh a=~
	command command export a=~
	showargs 11 "$a"
	unset a
	set -o posix
	command echo 12 posix a=~
	command command export a=~
	showargs 13 "$a"
	unset a
	# unspecified whether /tmp or ~
	var=export; command $var a=~
	showargs 14 "$a"
	echo 'echo "<$foo>"' >bar
	"$__progname" bar
	var=foo
	export $var=1
	"$__progname" bar
	export $var=~
	"$__progname" bar
	# unspecified
	command -- export a=~
	showargs 18 "$a"
	set -A bla
	typeset bla[1]=~:~
	typeset -g gbl=~ g2=$1
	local lcl=~ l2=$1
	readonly ro=~ r2=$1
	showargs 19 "${bla[1]}" a=~ "$gbl" "$lcl" "$ro" "$g2" "$l2" "$r2"
	set +o posix
	echo "20 some arbitrary stuff "=~
	set -o posix
	echo "21 some arbitrary stuff "=~
expected-stdout:
	<1> <1 b=2> <> <3> <4> .
	<2> </tmp> </tmp> </tmp> </tmp> </tmp> <ksh> .
	<3> <~> </tmp> </tmp> <~> </tmp> <posix> .
	<4> <1 b=2> <> <ksh> .
	<5> <a=1> <b=2> <ksh> .
	<6> <1> <2> <ksh> .
	<7> <1 b=2> <> <posix> .
	<8> <a=1> <b=2> <posix> .
	<9> <1> <2> <posix> .
	10 ksh a=/tmp
	<11> </tmp> .
	12 posix a=~
	<13> </tmp> .
	<14> <~> .
	<>
	<1>
	<~>
	<18> <~> .
	<19> </tmp:/tmp> <a=~> </tmp> </tmp> </tmp> <1 b=2> <1 b=2> <1 b=2> .
	20 some arbitrary stuff =/tmp
	21 some arbitrary stuff =~
---
name: exit-err-1
description:
	Check some "exit on error" conditions
stdin:
	print '#!'"$__progname"'\nexec "$1"' >env
	print '#!'"$__progname"'\nexit 1' >false
	chmod +x env false
	PATH=.$PATHSEP$PATH
	set -ex
	env false && echo something
	echo END
expected-stdout:
	END
expected-stderr:
	+ env false
	+ echo END
---
name: exit-err-2
description:
	Check some "exit on error" edge conditions (POSIXly)
stdin:
	print '#!'"$__progname"'\nexec "$1"' >env
	print '#!'"$__progname"'\nexit 1' >false
	print '#!'"$__progname"'\nexit 0' >true
	chmod +x env false
	PATH=.$PATHSEP$PATH
	set -ex
	if env true; then
		env false && echo something
	fi
	echo END
expected-stdout:
	END
expected-stderr:
	+ env true
	+ env false
	+ echo END
---
name: exit-err-3
description:
	pdksh regression which AT&T ksh does right
	TFM says: [set] -e | errexit
		Exit (after executing the ERR trap) ...
stdin:
	trap 'echo EXIT' EXIT
	trap 'echo ERR' ERR
	set -e
	cd /XXXXX 2>/dev/null
	echo DONE
	exit 0
expected-stdout:
	ERR
	EXIT
expected-exit: e != 0
---
name: exit-err-4
description:
	"set -e" test suite (POSIX)
stdin:
	set -e
	echo pre
	if true ; then
		false && echo foo
	fi
	echo bar
expected-stdout:
	pre
	bar
---
name: exit-err-5
description:
	"set -e" test suite (POSIX)
stdin:
	set -e
	foo() {
		while [ "$1" ]; do
			for E in $x; do
				[ "$1" = "$E" ] && { shift ; continue 2 ; }
			done
			x="$x $1"
			shift
		done
		echo $x
	}
	echo pre
	foo a b b c
	echo post
expected-stdout:
	pre
	a b c
	post
---
name: exit-err-6
description:
	"set -e" test suite (BSD make)
category: os:mirbsd
stdin:
	mkdir zd zd/a zd/b
	print 'all:\n\t@echo eins\n\t@exit 42\n' >zd/a/Makefile
	print 'all:\n\t@echo zwei\n' >zd/b/Makefile
	wd=$(pwd)
	set -e
	for entry in a b; do (  set -e;  if [[ -d $wd/zd/$entry.i386 ]]; then  _newdir_="$entry.i386";  else  _newdir_="$entry";  fi;  if [[ -z $_THISDIR_ ]]; then  _nextdir_="$_newdir_";  else  _nextdir_="$_THISDIR_/$_newdir_";  fi;  _makefile_spec_=;  [[ ! -f $wd/zd/$_newdir_/Makefile.bsd-wrapper ]]  || _makefile_spec_="-f Makefile.bsd-wrapper";  subskipdir=;  for skipdir in ; do  subentry=${skipdir#$entry};  if [[ $subentry != $skipdir ]]; then  if [[ -z $subentry ]]; then  echo "($_nextdir_ skipped)";  break;  fi;  subskipdir="$subskipdir ${subentry#/}";  fi;  done;  if [[ -z $skipdir || -n $subentry ]]; then  echo "===> $_nextdir_";  cd $wd/zd/$_newdir_;  make SKIPDIR="$subskipdir" $_makefile_spec_  _THISDIR_="$_nextdir_"   all;  fi;  ) done 2>&1 | sed "s!$wd!WD!g"
expected-stdout:
	===> a
	eins
	*** Error code 42
	
	Stop in WD/zd/a (line 2 of Makefile).
---
name: exit-err-7
description:
	"set -e" regression (LP#1104543)
stdin:
	set -e
	bla() {
		[ -x $PWD/nonexistant ] && $PWD/nonexistant
	}
	echo x
	bla
	echo y$?
expected-stdout:
	x
expected-exit: 1
---
name: exit-err-8
description:
	"set -e" regression (Debian #700526)
stdin:
	set -e
	_db_cmd() { return $1; }
	db_input() { _db_cmd 30; }
	db_go() { _db_cmd 0; }
	db_input || :
	db_go
	exit 0
---
name: exit-err-9
description:
	"set -e" versus bang pipelines
stdin:
	set -e
	! false | false
	echo 1 ok
	! false && false
	echo 2 wrong
expected-stdout:
	1 ok
expected-exit: 1
---
name: exit-err-10
description:
	Debian #269067 (cf. regression-38 but with eval)
arguments: !-e!
stdin:
	eval false || true
	echo = $? .
expected-stdout:
	= 0 .
---
name: exit-err-11
description:
	Fix -e inside eval, from Martijn Dekker; expected-stdout from ksh93
stdin:
	"$__progname" -c 'eval '\''echo ${-//[!eh]}; false; echo phantom e'\''; echo x$?'
	echo = $?
	"$__progname" -ec 'eval '\''echo ${-//[!eh]}; false; echo phantom e'\''; echo x$?'
	echo = $?
expected-stdout:
	h
	phantom e
	x0
	= 0
	eh
	= 1
---
name: exit-enoent-1
description:
	SUSv4 says that the shell should exit with 126/127 in some situations
stdin:
	i=0
	(echo; echo :) >x
	"$__progname" ./x >/dev/null 2>&1; r=$?; echo $((i++)) $r .
	"$__progname" -c ./x >/dev/null 2>&1; r=$?; echo $((i++)) $r .
	echo exit 42 >x
	"$__progname" ./x >/dev/null 2>&1; r=$?; echo $((i++)) $r .
	"$__progname" -c ./x >/dev/null 2>&1; r=$?; echo $((i++)) $r .
	rm -f x
	"$__progname" ./x >/dev/null 2>&1; r=$?; echo $((i++)) $r .
	"$__progname" -c ./x >/dev/null 2>&1; r=$?; echo $((i++)) $r .
expected-stdout:
	0 0 .
	1 126 .
	2 42 .
	3 126 .
	4 127 .
	5 127 .
---
name: exit-eval-1
description:
	Check eval vs substitution exit codes (ksh93 alike)
stdin:
	(exit 12)
	eval $(false)
	echo A $?
	(exit 12)
	eval ' $(false)'
	echo B $?
	(exit 12)
	eval " $(false)"
	echo C $?
	(exit 12)
	eval "eval $(false)"
	echo D $?
	(exit 12)
	eval 'eval '"$(false)"
	echo E $?
	IFS="$IFS:"
	(exit 12)
	eval $(echo :; false)
	echo F $?
	echo -n "G "
	(exit 12)
	eval 'echo $?'
	echo H $?
expected-stdout:
	A 0
	B 1
	C 0
	D 0
	E 0
	F 0
	G 12
	H 0
---
name: exit-trap-1
description:
	Check that "exit" with no arguments behaves SUSv4 conformant.
stdin:
	trap 'echo hi; exit' EXIT
	exit 9
expected-stdout:
	hi
expected-exit: 9
---
name: exit-trap-2
description:
	Check that ERR and EXIT traps are run just like GNU bash does.
	ksh93 runs ERtrap after ‚Äúparameter null or not set‚Äù (which mksh
	used to do) but (bug) continues ‚Äúand out‚Äù, exit 0, in +e eval-undef.
file-setup: file 644 "x"
	v=; unset v
	trap 'echo EXtrap' EXIT
	trap 'echo ERtrap' ERR
	set $1
	echo "and run $2"
	eval $2
	echo and out
file-setup: file 644 "xt"
	v=; unset v
	trap 'echo EXtrap' EXIT
	trap 'echo ERtrap' ERR
	set $1
	echo 'and run true'
	true
	echo and out
file-setup: file 644 "xf"
	v=; unset v
	trap 'echo EXtrap' EXIT
	trap 'echo ERtrap' ERR
	set $1
	echo 'and run false'
	false
	echo and out
file-setup: file 644 "xu"
	v=; unset v
	trap 'echo EXtrap' EXIT
	trap 'echo ERtrap' ERR
	set $1
	echo 'and run ${v?}'
	${v?}
	echo and out
stdin:
	runtest() {
		rm -f rc
		(
			"$__progname" "$@"
			echo $? >rc
		) 2>&1 | sed \
		    -e 's/parameter not set/parameter null or not set/' \
		    -e 's/[[]6]//' -e 's/: eval: line 1//' -e 's/: line 6//' \
		    -e "s^${__progname%.exe}\.*e*x*e*: <stdin>\[[0-9]*]PROG"
	}
	xe=-e
	echo : $xe
	runtest x $xe true
	echo = eval-true $(<rc) .
	runtest x $xe false
	echo = eval-false $(<rc) .
	runtest x $xe '${v?}'
	echo = eval-undef $(<rc) .
	runtest xt $xe
	echo = noeval-true $(<rc) .
	runtest xf $xe
	echo = noeval-false $(<rc) .
	runtest xu $xe
	echo = noeval-undef $(<rc) .
	xe=+e
	echo : $xe
	runtest x $xe true
	echo = eval-true $(<rc) .
	runtest x $xe false
	echo = eval-false $(<rc) .
	runtest x $xe '${v?}'
	echo = eval-undef $(<rc) .
	runtest xt $xe
	echo = noeval-true $(<rc) .
	runtest xf $xe
	echo = noeval-false $(<rc) .
	runtest xu $xe
	echo = noeval-undef $(<rc) .
expected-stdout:
	: -e
	and run true
	and out
	EXtrap
	= eval-true 0 .
	and run false
	ERtrap
	EXtrap
	= eval-false 1 .
	and run ${v?}
	x: v: parameter null or not set
	EXtrap
	= eval-undef 1 .
	and run true
	and out
	EXtrap
	= noeval-true 0 .
	and run false
	ERtrap
	EXtrap
	= noeval-false 1 .
	and run ${v?}
	xu: v: parameter null or not set
	EXtrap
	= noeval-undef 1 .
	: +e
	and run true
	and out
	EXtrap
	= eval-true 0 .
	and run false
	ERtrap
	ERtrap
	and out
	EXtrap
	= eval-false 0 .
	and run ${v?}
	x: v: parameter null or not set
	EXtrap
	= eval-undef 1 .
	and run true
	and out
	EXtrap
	= noeval-true 0 .
	and run false
	ERtrap
	and out
	EXtrap
	= noeval-false 0 .
	and run ${v?}
	xu: v: parameter null or not set
	EXtrap
	= noeval-undef 1 .
---
name: exit-trap-3
description:
	Check that the EXIT trap is run in many places, Debian #910276
stdin:
	fkt() {
		trap -- "echo $1 >&2" EXIT
	}
	fkt shell_exit
	$(fkt fn_exit)
	$(trap -- "echo comsub_exit >&2" EXIT)
	(trap -- "echo subshell_exit >&2" EXIT)
expected-stderr:
	fn_exit
	comsub_exit
	subshell_exit
	shell_exit
---
name: exit-trap-interactive
description:
	Check that interactive shell doesn't exit via EXIT trap on syntax error
arguments: !-i!
stdin:
	trap -- EXIT
	echo Syntax error <
	echo 'After error 1'
	trap 'echo Exit trap' EXIT
	echo Syntax error <
	echo 'After error 2'
	trap 'echo Exit trap' EXIT
	exit
	echo 'After exit'
expected-stdout:
	After error 1
	After error 2
	Exit trap
expected-stderr-pattern:
	/syntax error: unexpected 'newline'/
---
name: test-stlt-1
description:
	Check that test also can handle string1 < string2 etc.
stdin:
	test 2005/10/08 '<' 2005/08/21 && echo ja || echo nein
	test 2005/08/21 \< 2005/10/08 && echo ja || echo nein
	test 2005/10/08 '>' 2005/08/21 && echo ja || echo nein
	test 2005/08/21 \> 2005/10/08 && echo ja || echo nein
expected-stdout:
	nein
	ja
	ja
	nein
expected-stderr-pattern: !/unexpected op/
---
name: test-str-pattern
description:
	Check that [[ x = $y ]] can take extglobs, like ksh93
stdin:
	[[ -n $BASH_VERSION ]] && shopt -s extglob
	function one {
		n=$1 x=$2 y=$3 z=${4:-$3}
		[[ $x = $y ]]; a=$?
		[[ $x = "$y" ]]; b=$?
		eval '[[ $x = '"$z"' ]]; c=$?'
		eval '[[ $x = "'"$z"'" ]]; d=$?'
		echo $n $a $b $c $d .
	}
	x='a\'
	[[ $x = a\  ]]; echo 01 $? .
	[[ $x = a\\ ]]; echo 02 $? .
	one 03 'a\'	'a\'	'a\\'
	one 04 'a\b'	'a\b'
	one 05 'a\b'	'a\\b'
	one 06 'foo'	'f+(o)'
	one 07 'f+(o)'	'f+(o)'
	one 08 'f+(o'	'f+(o'	'f+\(o'
	one 09 foo	'f+(o'	'f+\(o'
	one 10 abcde	'a\*e'
	one 11 'a*e'	'a\*e'
	one 12 'a\*e'	'a\*e'
	echo extras:
	x='f+(o'
	z='f+(o'
	eval '[[ $x = "'"$z"'" ]]; echo 14 $? "(08:4)" .'
	x=foo
	eval '[[ $x = "'"$z"'" ]]; echo 15 $? "(09:4)" .'
expected-stdout:
	01 1 .
	02 0 .
	03 0 0 0 0 .
	04 1 0 1 0 .
	05 0 1 0 0 .
	06 0 1 0 1 .
	07 1 0 1 0 .
	08 0 0 0 1 .
	09 1 1 1 1 .
	10 1 1 1 1 .
	11 0 1 0 1 .
	12 1 0 1 0 .
	extras:
	14 0 (08:4) .
	15 1 (09:4) .
---
name: test-precedence-1
description:
	Check a weird precedence case (and POSIX echo)
stdin:
	test \( -f = -f \)
	rv=$?
	echo $rv
expected-stdout:
	0
---
name: test-option-1
description:
	Test the test -o operator
stdin:
	runtest() {
		test -o $1; echo $?
		[ -o $1 ]; echo $?
		[[ -o $1 ]]; echo $?
	}
	if_test() {
		test -o $1 -o -o !$1; echo $?
		[ -o $1 -o -o !$1 ]; echo $?
		[[ -o $1 || -o !$1 ]]; echo $?
		test -o ?$1; echo $?
	}
	echo 0y $(if_test utf8-mode) =
	echo 0n $(if_test utf8-hack) =
	echo 1= $(runtest utf8-hack) =
	echo 2= $(runtest !utf8-hack) =
	echo 3= $(runtest ?utf8-hack) =
	set +U
	echo 1+ $(runtest utf8-mode) =
	echo 2+ $(runtest !utf8-mode) =
	echo 3+ $(runtest ?utf8-mode) =
	set -U
	echo 1- $(runtest utf8-mode) =
	echo 2- $(runtest !utf8-mode) =
	echo 3- $(runtest ?utf8-mode) =
	echo = short flags =
	echo 0y $(if_test -U) =
	echo 0y $(if_test +U) =
	echo 0n $(if_test -_) =
	echo 0n $(if_test -U-) =
	echo 1= $(runtest -_) =
	echo 2= $(runtest !-_) =
	echo 3= $(runtest ?-_) =
	set +U
	echo 1+ $(runtest -U) =
	echo 2+ $(runtest !-U) =
	echo 3+ $(runtest ?-U) =
	echo 1+ $(runtest +U) =
	echo 2+ $(runtest !+U) =
	echo 3+ $(runtest ?+U) =
	set -U
	echo 1- $(runtest -U) =
	echo 2- $(runtest !-U) =
	echo 3- $(runtest ?-U) =
	echo 1- $(runtest +U) =
	echo 2- $(runtest !+U) =
	echo 3- $(runtest ?+U) =
expected-stdout:
	0y 0 0 0 0 =
	0n 1 1 1 1 =
	1= 1 1 1 =
	2= 1 1 1 =
	3= 1 1 1 =
	1+ 1 1 1 =
	2+ 0 0 0 =
	3+ 0 0 0 =
	1- 0 0 0 =
	2- 1 1 1 =
	3- 0 0 0 =
	= short flags =
	0y 0 0 0 0 =
	0y 0 0 0 0 =
	0n 1 1 1 1 =
	0n 1 1 1 1 =
	1= 1 1 1 =
	2= 1 1 1 =
	3= 1 1 1 =
	1+ 1 1 1 =
	2+ 0 0 0 =
	3+ 0 0 0 =
	1+ 1 1 1 =
	2+ 0 0 0 =
	3+ 0 0 0 =
	1- 0 0 0 =
	2- 1 1 1 =
	3- 0 0 0 =
	1- 0 0 0 =
	2- 1 1 1 =
	3- 0 0 0 =
---
name: test-varset-1
description:
	Test the test -v operator
stdin:
	[[ -v a ]]
	rv=$?; echo $((++i)) $rv
	a=
	[[ -v a ]]
	rv=$?; echo $((++i)) $rv
	unset a
	[[ -v a ]]
	rv=$?; echo $((++i)) $rv
	a=x
	[[ -v a ]]
	rv=$?; echo $((++i)) $rv
	nameref b=a
	[[ -v b ]]
	rv=$?; echo $((++i)) $rv
	unset a
	[[ -v b ]]
	rv=$?; echo $((++i)) $rv
	x[1]=y
	[[ -v x ]]
	rv=$?; echo $((++i)) $rv
	[[ -v x[0] ]]
	rv=$?; echo $((++i)) $rv
	[[ -v x[1] ]]
	rv=$?; echo $((++i)) $rv
	[[ -v x[2] ]]
	rv=$?; echo $((++i)) $rv
expected-stdout:
	1 1
	2 0
	3 1
	4 0
	5 0
	6 1
	7 1
	8 1
	9 0
	10 1
---
name: test-varset-2
description:
	test -v works only on scalars
stdin:
	[[ -v x[*] ]]
	echo ok
expected-exit: e != 0
expected-stderr-pattern:
	/unexpected '\*'/
---
name: test-stnze-1
description:
	Check that the short form [ $x ] works
stdin:
	i=0
	[ -n $x ]
	rv=$?; echo $((++i)) $rv
	[ $x ]
	rv=$?; echo $((++i)) $rv
	[ -n "$x" ]
	rv=$?; echo $((++i)) $rv
	[ "$x" ]
	rv=$?; echo $((++i)) $rv
	x=0
	[ -n $x ]
	rv=$?; echo $((++i)) $rv
	[ $x ]
	rv=$?; echo $((++i)) $rv
	[ -n "$x" ]
	rv=$?; echo $((++i)) $rv
	[ "$x" ]
	rv=$?; echo $((++i)) $rv
	x='1 -a 1 = 2'
	[ -n $x ]
	rv=$?; echo $((++i)) $rv
	[ $x ]
	rv=$?; echo $((++i)) $rv
	[ -n "$x" ]
	rv=$?; echo $((++i)) $rv
	[ "$x" ]
	rv=$?; echo $((++i)) $rv
expected-stdout:
	1 0
	2 1
	3 1
	4 1
	5 0
	6 0
	7 0
	8 0
	9 1
	10 1
	11 0
	12 0
---
name: test-stnze-2
description:
	Check that the short form [[ $x ]] works (ksh93 extension)
stdin:
	i=0
	[[ -n $x ]]
	rv=$?; echo $((++i)) $rv
	[[ $x ]]
	rv=$?; echo $((++i)) $rv
	[[ -n "$x" ]]
	rv=$?; echo $((++i)) $rv
	[[ "$x" ]]
	rv=$?; echo $((++i)) $rv
	x=0
	[[ -n $x ]]
	rv=$?; echo $((++i)) $rv
	[[ $x ]]
	rv=$?; echo $((++i)) $rv
	[[ -n "$x" ]]
	rv=$?; echo $((++i)) $rv
	[[ "$x" ]]
	rv=$?; echo $((++i)) $rv
	x='1 -a 1 = 2'
	[[ -n $x ]]
	rv=$?; echo $((++i)) $rv
	[[ $x ]]
	rv=$?; echo $((++i)) $rv
	[[ -n "$x" ]]
	rv=$?; echo $((++i)) $rv
	[[ "$x" ]]
	rv=$?; echo $((++i)) $rv
expected-stdout:
	1 1
	2 1
	3 1
	4 1
	5 0
	6 0
	7 0
	8 0
	9 0
	10 0
	11 0
	12 0
---
name: test-numeq
description:
	Check numeric -eq works (R40d regression); spotted by Martijn Dekker
stdin:
	tst() {
		eval "$2"
		case $? in
		(0) echo yepp 0 \#"$*" ;;
		(1) echo nope 1 \#"$*" ;;
		(2) echo terr 2 \#"$*" ;;
		(*) echo wtf\? $? \#"$*" ;;
		esac
	}
	tst 1 'test 2 -eq 2'
	tst 2 'test 2 -eq 2a'
	tst 3 'test 2 -eq 3'
	tst 4 'test 2 -ne 2'
	tst 5 'test 2 -ne 2a'
	tst 6 'test 2 -ne 3'
	tst 7 'test \! 2 -eq 2'
	tst 8 'test \! 2 -eq 2a'
	tst 9 'test \! 2 -eq 3'
expected-stdout:
	yepp 0 #1 test 2 -eq 2
	terr 2 #2 test 2 -eq 2a
	nope 1 #3 test 2 -eq 3
	nope 1 #4 test 2 -ne 2
	terr 2 #5 test 2 -ne 2a
	yepp 0 #6 test 2 -ne 3
	nope 1 #7 test \! 2 -eq 2
	terr 2 #8 test \! 2 -eq 2a
	yepp 0 #9 test \! 2 -eq 3
expected-stderr-pattern:
	/bad number/
---
name: mkshrc-1
description:
	Check that ~/.mkshrc works correctly.
	Part 1: verify user environment is not read (internal)
stdin:
	echo x $FNORD
expected-stdout:
	x
---
name: mkshrc-2a
description:
	Check that ~/.mkshrc works correctly.
	Part 2: verify mkshrc is not read (non-interactive shells)
file-setup: file 644 ".mkshrc"
	FNORD=42
env-setup: !HOME=.!ENV=!
stdin:
	echo x $FNORD
expected-stdout:
	x
---
name: mkshrc-2b
description:
	Check that ~/.mkshrc works correctly.
	Part 2: verify mkshrc can be read (interactive shells)
file-setup: file 644 ".mkshrc"
	FNORD=42
need-ctty: yes
arguments: !-i!
env-setup: !HOME=.!ENV=!PS1=!
stdin:
	echo x $FNORD
expected-stdout:
	x 42
expected-stderr-pattern:
	/(# )*/
---
name: mkshrc-3
description:
	Check that ~/.mkshrc works correctly.
	Part 3: verify mkshrc can be turned off
file-setup: file 644 ".mkshrc"
	FNORD=42
env-setup: !HOME=.!ENV=nonexistant!
stdin:
	echo x $FNORD
expected-stdout:
	x
---
name: sh-mode-1
description:
	Check that sh mode turns braceexpand off
	and that that works correctly
stdin:
	set -o braceexpand
	set +o sh
	[[ -o sh ]] && echo sh
	[[ -o !sh ]] && echo nosh
	[[ -o braceexpand ]] && echo brex
	[[ -o !braceexpand ]] && echo nobrex
	echo {a,b,c}
	set +o braceexpand
	echo {a,b,c}
	set -o braceexpand
	echo {a,b,c}
	set -o sh
	echo {a,b,c}
	[[ -o sh ]] && echo sh
	[[ -o !sh ]] && echo nosh
	[[ -o braceexpand ]] && echo brex
	[[ -o !braceexpand ]] && echo nobrex
	set -o braceexpand
	echo {a,b,c}
	[[ -o sh ]] && echo sh
	[[ -o !sh ]] && echo nosh
	[[ -o braceexpand ]] && echo brex
	[[ -o !braceexpand ]] && echo nobrex
	[[ $(exec -a -set "$__progname" -o) = *login+(' ')on* ]]; echo $?
expected-stdout:
	nosh
	brex
	a b c
	{a,b,c}
	a b c
	{a,b,c}
	sh
	nobrex
	a b c
	sh
	brex
	0
---
name: sh-mode-2a
description:
	Check that posix or sh mode is *not* automatically turned on
category: !binsh
stdin:
	for shell in {,-}{,r}{,k,mk}sh {,-}{,R}{,K,MK}SH.EXE; do
		ln -s "$__progname" ./$shell || cp "$__progname" ./$shell
		print -- $shell $(./$shell +l -c '
			[[ -o sh || -o posix ]] && echo sh
			[[ -o !sh && -o !posix ]] && echo nosh
			[[ -o restricted ]] && echo lim || echo ok
		    ')
	done
expected-stdout:
	sh nosh ok
	ksh nosh ok
	mksh nosh ok
	rsh nosh lim
	rksh nosh lim
	rmksh nosh lim
	-sh nosh ok
	-ksh nosh ok
	-mksh nosh ok
	-rsh nosh lim
	-rksh nosh lim
	-rmksh nosh lim
	SH.EXE nosh ok
	KSH.EXE nosh ok
	MKSH.EXE nosh ok
	RSH.EXE nosh lim
	RKSH.EXE nosh lim
	RMKSH.EXE nosh lim
	-SH.EXE nosh ok
	-KSH.EXE nosh ok
	-MKSH.EXE nosh ok
	-RSH.EXE nosh lim
	-RKSH.EXE nosh lim
	-RMKSH.EXE nosh lim
---
name: sh-mode-2b
description:
	Check that posix or sh mode *is* automatically turned on
category: binsh
stdin:
	for shell in {,-}{,r}{,k,mk}sh {,-}{,R}{,K,MK}SH.EXE; do
		ln -s "$__progname" ./$shell || cp "$__progname" ./$shell
		print -- $shell $(./$shell +l -c '
			[[ -o sh || -o posix ]] && echo sh
			[[ -o !sh && -o !posix ]] && echo nosh
			[[ -o restricted ]] && echo lim || echo ok
		    ')
	done
expected-stdout:
	sh sh ok
	ksh nosh ok
	mksh nosh ok
	rsh sh lim
	rksh nosh lim
	rmksh nosh lim
	-sh sh ok
	-ksh nosh ok
	-mksh nosh ok
	-rsh sh lim
	-rksh nosh lim
	-rmksh nosh lim
	SH.EXE sh ok
	KSH.EXE nosh ok
	MKSH.EXE nosh ok
	RSH.EXE sh lim
	RKSH.EXE nosh lim
	RMKSH.EXE nosh lim
	-SH.EXE sh ok
	-KSH.EXE nosh ok
	-MKSH.EXE nosh ok
	-RSH.EXE sh lim
	-RKSH.EXE nosh lim
	-RMKSH.EXE nosh lim
---
name: sh-options
description:
	Check that "set +o" DTRT per POSIX
stdin:
	t() {
		[[ -o vi ]]; a=$?
		[[ -o pipefail ]]; b=$?
		echo $((++i)) $a $b .
	}
	set -e
	set -o vi
	set +o pipefail
	set +e
	t
	x=$(set +o)
	set +o vi
	set -o pipefail
	t
	eval "$x"
	t
expected-stdout:
	1 0 1 .
	2 1 0 .
	3 0 1 .
---
name: pipeline-1
description:
	pdksh bug: last command of a pipeline is executed in a
	subshell - make sure it still is, scripts depend on it
file-setup: file 644 "abcx"
file-setup: file 644 "abcy"
stdin:
	echo *
	echo a | while read d; do
		echo $d
		echo $d*
		echo *
		set -o noglob
		echo $d*
		echo *
	done
	echo *
expected-stdout:
	abcx abcy
	a
	abcx abcy
	abcx abcy
	a*
	*
	abcx abcy
---
name: pipeline-2
description:
	check that co-processes work with TCOMs, TPIPEs and TPARENs
category: !nojsig
stdin:
	"$__progname" -c 'i=100; echo hi |& while read -p line; do echo "$((i++)) $line"; done'
	"$__progname" -c 'i=200; echo hi | cat |& while read -p line; do echo "$((i++)) $line"; done'
	"$__progname" -c 'i=300; (echo hi | cat) |& while read -p line; do echo "$((i++)) $line"; done'
expected-stdout:
	100 hi
	200 hi
	300 hi
---
name: pipeline-3
description:
	Check that PIPESTATUS does what it's supposed to
stdin:
	echo 1 $PIPESTATUS .
	echo 2 ${PIPESTATUS[0]} .
	echo 3 ${PIPESTATUS[1]} .
	(echo x; exit 12) | (cat; exit 23) | (cat; exit 42)
	echo 5 $? , $PIPESTATUS , ${PIPESTATUS[0]} , ${PIPESTATUS[1]} , ${PIPESTATUS[2]} , ${PIPESTATUS[3]} .
	echo 6 ${PIPESTATUS[0]} .
	set | fgrep PIPESTATUS
	echo 8 $(set | fgrep PIPESTATUS) .
expected-stdout:
	1 0 .
	2 0 .
	3 .
	x
	5 42 , 12 , 12 , 23 , 42 , .
	6 0 .
	PIPESTATUS[0]=0
	8 PIPESTATUS[0]=0 PIPESTATUS[1]=0 .
---
name: pipeline-4
description:
	Check that "set -o pipefail" does what it's supposed to
stdin:
	echo 1 "$("$__progname" -c '(exit 12) | (exit 23) | (exit 42); echo $?')" .
	echo 2 "$("$__progname" -c '! (exit 12) | (exit 23) | (exit 42); echo $?')" .
	echo 3 "$("$__progname" -o pipefail -c '(exit 12) | (exit 23) | (exit 42); echo $?')" .
	echo 4 "$("$__progname" -o pipefail -c '! (exit 12) | (exit 23) | (exit 42); echo $?')" .
	echo 5 "$("$__progname" -c '(exit 23) | (exit 42) | :; echo $?')" .
	echo 6 "$("$__progname" -c '! (exit 23) | (exit 42) | :; echo $?')" .
	echo 7 "$("$__progname" -o pipefail -c '(exit 23) | (exit 42) | :; echo $?')" .
	echo 8 "$("$__progname" -o pipefail -c '! (exit 23) | (exit 42) | :; echo $?')" .
	echo 9 "$("$__progname" -o pipefail -c 'x=$( (exit 23) | (exit 42) | :); echo $?')" .
expected-stdout:
	1 42 .
	2 0 .
	3 42 .
	4 0 .
	5 0 .
	6 1 .
	7 42 .
	8 0 .
	9 42 .
---
name: persist-history-1
description:
	Check if persistent history saving works
category: !no-histfile
need-ctty: yes
arguments: !-i!
env-setup: !ENV=./Env!HISTFILE=hist.file!
file-setup: file 644 "Env"
	PS1=X
stdin:
	cat hist.file
expected-stdout-pattern:
	/cat hist.file/
expected-stderr-pattern:
	/^X*$/
---
name: typeset-1
description:
	Check that typeset -g works correctly
stdin:
	set -A arrfoo 65
	foo() {
		typeset -g -Uui16 arrfoo[*]
	}
	echo before ${arrfoo[0]} .
	foo
	echo after ${arrfoo[0]} .
	set -A arrbar 65
	bar() {
		echo inside before ${arrbar[0]} .
		arrbar[0]=97
		echo inside changed ${arrbar[0]} .
		typeset -g -Uui16 arrbar[*]
		echo inside typeset ${arrbar[0]} .
		arrbar[0]=48
		echo inside changed ${arrbar[0]} .
	}
	echo before ${arrbar[0]} .
	bar
	echo after ${arrbar[0]} .
expected-stdout:
	before 65 .
	after 16#41 .
	before 65 .
	inside before 65 .
	inside changed 97 .
	inside typeset 16#61 .
	inside changed 16#30 .
	after 16#30 .
---
name: typeset-2
description:
	Check that typeset -p on arrays works correctly
stdin:
	set -A x -- a b c
	echo =
	typeset -p x
	echo =
	typeset -p x[1]
expected-stdout:
	=
	set -A x
	typeset x[0]=a
	typeset x[1]=b
	typeset x[2]=c
	=
	typeset x[1]=b
---
name: typeset-padding-1
description:
	Check if left/right justification works as per TFM
stdin:
	typeset -L10 ln=0hall0
	typeset -R10 rn=0hall0
	typeset -ZL10 lz=0hall0
	typeset -ZR10 rz=0hall0
	typeset -Z10 rx=" hallo "
	echo "<$ln> <$rn> <$lz> <$rz> <$rx>"
expected-stdout:
	<0hall0    > <    0hall0> <hall0     > <00000hall0> <0000 hallo>
---
name: typeset-padding-2
description:
	Check if base-!10 integers are padded right
stdin:
	typeset -Uui16 -L9 ln=16#1
	typeset -Uui16 -R9 rn=16#1
	typeset -Uui16 -Z9 zn=16#1
	typeset -L9 ls=16#1
	typeset -R9 rs=16#1
	typeset -Z9 zs=16#1
	echo "<$ln> <$rn> <$zn> <$ls> <$rs> <$zs>"
expected-stdout:
	<16#1     > <     16#1> <16#000001> <16#1     > <     16#1> <0000016#1>
---
name: typeset-padding-3
description:
	Check for a regression in which UTF-8 wasn‚Äôt left-padded right
stdin:
	set -U
	nl=$'\n'
	typeset -L20 x='.  ak'
	typeset -R20 y='.  ak'
	print -r -- "<$x> (1$nl<12345678910 345678920$nl<$y> 1)"
	typeset -L20 x='.  a·∫û'
	typeset -R20 y='.  a·∫û'
	print -r -- "<$x> (2$nl<12345678910 345678920$nl<$y> 2)"
expected-stdout:
	<.  ak               > (1
	<12345678910 345678920
	<               .  ak> 1)
	<.  a·∫û               > (2
	<12345678910 345678920
	<               .  a·∫û> 2)
---
name: utf8bom-1
description:
	Check that the UTF-8 Byte Order Mark is ignored as the first
	multibyte character of the shell input (with -c, from standard
	input, as file, or as eval argument), but nowhere else
# breaks on Mac OSX (HFS+ non-standard UTF-8 canonical decomposition)
category: !os:darwin,!shell:ebcdic-yes
stdin:
	mkdir foo
	print '#!/bin/sh\necho ohne' >foo/fnord
	print '#!/bin/sh\necho mit' >foo/Ôªøfnord
	print 'Ôªøfnord\nfnord\nÔªøfnord\nfnord' >foo/bar
	print eval \''Ôªøfnord\nfnord\nÔªøfnord\nfnord'\' >foo/zoo
	set -A anzahl -- foo/*
	echo got ${#anzahl[*]} files
	chmod +x foo/*
	export PATH=$(pwd)/foo$PATHSEP$PATH
	"$__progname" -c 'Ôªøfnord'
	echo =
	"$__progname" -c 'Ôªøfnord; fnord; Ôªøfnord; fnord'
	echo =
	"$__progname" foo/bar
	echo =
	"$__progname" <foo/bar
	echo =
	"$__progname" foo/zoo
	echo =
	"$__progname" -c 'echo Ôªø: $(Ôªøfnord)'
	rm -rf foo
expected-stdout:
	got 4 files
	ohne
	=
	ohne
	ohne
	mit
	ohne
	=
	ohne
	ohne
	mit
	ohne
	=
	ohne
	ohne
	mit
	ohne
	=
	ohne
	ohne
	mit
	ohne
	=
	Ôªø: ohne
---
name: utf8bom-2
description:
	Check that we can execute BOM-shebangs (failures not fatal)
	XXX if the OS can already execute them, we lose
	note: cygwin execve(2) doesn't return to us with ENOEXEC, we lose
	note: Ultrix perl5 t4 returns 65280 (exit-code 255) and no text
	XXX fails when LD_PRELOAD is set with -e and Perl chokes it (ASan)
need-pass: no
category: !os:cygwin,!os:midipix,!os:msys,!os:ultrix,!os:uwin-nt,!smksh
env-setup: !FOO=BAR!
stdin:
	print '#!'"$__progname"'\nprint "1 a=$ENV{FOO}";' >t1
	print 'Ôªø#!'"$__progname"'\nprint "2 a=$ENV{FOO}";' >t2
	print '#!'"$__perlname"'\nprint "3 a=$ENV{FOO}\n";' >t3
	print 'Ôªø#!'"$__perlname"'\nprint "4 a=$ENV{FOO}\n";' >t4
	chmod +x t?
	./t1
	./t2
	./t3
	./t4
expected-stdout:
	1 a=/nonexistant{FOO}
	2 a=/nonexistant{FOO}
	3 a=BAR
	4 a=BAR
expected-stderr-pattern:
	/(Unrecognized character .... ignored at \..t4 line 1)*/
---
name: utf8opt-1
description:
	Check that the utf8-mode flag is not set at non-interactive startup
env-setup: !PS1=!PS2=!LC_CTYPE=@utflocale@!
stdin:
	if [[ $- = *U* ]]; then
		echo is set
	else
		echo is not set
	fi
expected-stdout:
	is not set
---
name: utf8opt-2
description:
	Check that the utf8-mode flag is set at interactive startup.
	If your OS is old, try passing HAVE_SETLOCALE_CTYPE=0 to Build.sh
need-pass: no
category: !noutf8
need-ctty: yes
arguments: !-i!
env-setup: !PS1=!PS2=!LC_CTYPE=@utflocale@!
stdin:
	if [[ $- = *U* ]]; then
		echo is set
	else
		echo is not set
	fi
expected-stdout:
	is set
expected-stderr-pattern:
	/(# )*/
---
name: utf8opt-3a
description:
	Ensure ¬±U on the command line is honoured
	(these two tests may pass falsely depending on CPPFLAGS)
stdin:
	export i=0
	code='if [[ $- = *U* ]]; then echo $i on; else echo $i off; fi'
	let i++; "$__progname" -U -c "$code"
	let i++; "$__progname" +U -c "$code"
	echo $((++i)) done
expected-stdout:
	1 on
	2 off
	3 done
---
name: utf8opt-3b
description:
	Ensure ¬±U on the command line is honoured, interactive shells
need-ctty: yes
stdin:
	export i=0
	code='if [[ $- = *U* ]]; then echo $i on; else echo $i off; fi'
	let i++; "$__progname" -U -ic "$code"
	let i++; "$__progname" +U -ic "$code"
	echo $((++i)) done
expected-stdout:
	1 on
	2 off
	3 done
---
name: utf8bug-1
description:
	Ensure trailing combining characters are not lost
stdin:
	set -U
	a=a
	b=$'\u0301'
	x=$a$b
	print -r -- "<e$x>"
	x=$a
	x+=$b
	print -r -- "<e$x>"
	b=$'\u0301'b
	x=$a
	x+=$b
	print -r -- "<e$x>"
expected-stdout:
	<eaÃÅ>
	<eaÃÅ>
	<eaÃÅb>
---
name: aliases-1
description:
	Check if built-in shell aliases are okay
stdin:
	alias
	typeset -f
expected-stdout:
	autoload='\\builtin typeset -fu'
	functions='\\builtin typeset -f'
	hash='\\builtin alias -t'
	history='\\builtin fc -l'
	integer='\\builtin typeset -i'
	local='\\builtin typeset'
	login='\\builtin exec login'
	nameref='\\builtin typeset -n'
	nohup='nohup '
	r='\\builtin fc -e -'
	type='\\builtin whence -v'
---
name: aliases-2b
description:
	Check if ‚Äúset -o sh‚Äù does not influence built-in aliases
arguments: !-o!sh!
stdin:
	alias
	typeset -f
expected-stdout:
	autoload='\\builtin typeset -fu'
	functions='\\builtin typeset -f'
	hash='\\builtin alias -t'
	history='\\builtin fc -l'
	integer='\\builtin typeset -i'
	local='\\builtin typeset'
	login='\\builtin exec login'
	nameref='\\builtin typeset -n'
	nohup='nohup '
	r='\\builtin fc -e -'
	type='\\builtin whence -v'
---
name: aliases-3b
description:
	Check if running as sh does not influence built-in aliases
stdin:
	cp "$__progname" sh
	./sh -c 'alias; typeset -f'
	rm -f sh
expected-stdout:
	autoload='\\builtin typeset -fu'
	functions='\\builtin typeset -f'
	hash='\\builtin alias -t'
	history='\\builtin fc -l'
	integer='\\builtin typeset -i'
	local='\\builtin typeset'
	login='\\builtin exec login'
	nameref='\\builtin typeset -n'
	nohup='nohup '
	r='\\builtin fc -e -'
	type='\\builtin whence -v'
---
name: aliases-cmdline
description:
	Check that aliases work from the command line (Debian #517009)
	Note that due to the nature of the lexing process, defining
	aliases in COMSUBs then immediately using them, and things
	like 'alias foo=bar && foo', still fail.
stdin:
	"$__progname" -c $'alias a="echo OK"\na'
expected-stdout:
	OK
---
name: aliases-funcdef-1
description:
	Check if POSIX functions take precedences over aliases
stdin:
	alias foo='echo makro'
	foo() {
		echo funktion
	}
	foo
expected-stdout:
	makro
---
name: aliases-funcdef-2
description:
	Check if POSIX functions take precedences over aliases
stdin:
	alias foo='echo makro'
	foo () {
		echo funktion
	}
	foo
expected-stdout:
	makro
---
name: aliases-funcdef-3
description:
	Check if aliases take precedences over Korn functions
stdin:
	alias foo='echo makro'
	function foo {
		echo funktion
	}
	foo
expected-stdout:
	makro
---
name: aliases-funcdef-4
description:
	Functions should only take over if actually being defined
stdin:
	alias local
	:|| local() { :; }
	alias local
expected-stdout:
	local='\\builtin typeset'
	local='\\builtin typeset'
---
name: arrays-1
description:
	Check if Korn Shell arrays work as expected
stdin:
	v="c d"
	set -A foo -- a \$v "$v" '$v' b
	echo "${#foo[*]}|${foo[0]}|${foo[1]}|${foo[2]}|${foo[3]}|${foo[4]}|"
expected-stdout:
	5|a|$v|c d|$v|b|
---
name: arrays-2a
description:
	Check if bash-style arrays work as expected
stdin:
	v="c d"
	foo=(a \$v "$v" '$v' b)
	echo "${#foo[*]}|${foo[0]}|${foo[1]}|${foo[2]}|${foo[3]}|${foo[4]}|"
expected-stdout:
	5|a|$v|c d|$v|b|
---
name: arrays-2b
description:
	Check if bash-style arrays work as expected, with newlines
stdin:
	print '#!'"$__progname"'\nfor x in "$@"; do print -nr -- "$x|"; done' >pfp
	chmod +x pfp
	test -n "$ZSH_VERSION" && setopt KSH_ARRAYS
	v="e f"
	foo=(a
		bc
		d \$v "$v" '$v' g
	)
	./pfp "${#foo[*]}" "${foo[0]}" "${foo[1]}" "${foo[2]}" "${foo[3]}" "${foo[4]}" "${foo[5]}" "${foo[6]}"; echo
	foo=(a\
		bc
		d \$v "$v" '$v' g
	)
	./pfp "${#foo[*]}" "${foo[0]}" "${foo[1]}" "${foo[2]}" "${foo[3]}" "${foo[4]}" "${foo[5]}" "${foo[6]}"; echo
	foo=(a\
	bc\\
		d \$v "$v" '$v'
	g)
	./pfp "${#foo[*]}" "${foo[0]}" "${foo[1]}" "${foo[2]}" "${foo[3]}" "${foo[4]}" "${foo[5]}" "${foo[6]}"; echo
expected-stdout:
	7|a|bc|d|$v|e f|$v|g|
	7|a|bc|d|$v|e f|$v|g|
	6|abc\|d|$v|e f|$v|g||
---
name: arrays-3
description:
	Check if array bounds are uint32_t
stdin:
	set -A foo a b c
	foo[4097]=d
	foo[2147483637]=e
	echo ${foo[*]}
	foo[-1]=f
	echo ${foo[4294967295]} g ${foo[*]}
expected-stdout:
	a b c d e
	f g a b c d e f
---
name: arrays-4
description:
	Check if Korn Shell arrays with specified indices work as expected
stdin:
	v="c d"
	set -A foo -- [1]=\$v [2]="$v" [4]='$v' [0]=a [5]=b
	echo "${#foo[*]}|${foo[0]}|${foo[1]}|${foo[2]}|${foo[3]}|${foo[4]}|${foo[5]}|"
	# we don't want this at all:
	#	5|a|$v|c d||$v|b|
	set -A arr "[5]=meh"
	echo "<${arr[0]}><${arr[5]}>"
expected-stdout:
	5|[1]=$v|[2]=c d|[4]=$v|[0]=a|[5]=b||
	<[5]=meh><>
---
name: arrays-5
description:
	Check if bash-style arrays with specified indices work as expected
	(taken out temporarily to fix arrays-4; see also arrays-9a comment)
category: disabled
stdin:
	v="c d"
	foo=([1]=\$v [2]="$v" [4]='$v' [0]=a [5]=b)
	echo "${#foo[*]}|${foo[0]}|${foo[1]}|${foo[2]}|${foo[3]}|${foo[4]}|${foo[5]}|"
	x=([128]=foo bar baz)
	echo k= ${!x[*]} .
	echo v= ${x[*]} .
	# Check that we do not break this by globbing
	:>b=blah
	bleh=5
	typeset -a arr
	arr+=([bleh]=blah)
	echo "<${arr[0]}><${arr[5]}>"
expected-stdout:
	5|a|$v|c d||$v|b|
	k= 128 129 130 .
	v= foo bar baz .
	<><blah>
---
name: arrays-6
description:
	Check if we can get the array keys (indices) for indexed arrays,
	Korn shell style
stdin:
	of() {
		i=0
		for x in "$@"; do
			echo -n "$((i++))<$x>"
		done
		echo
	}
	foo[1]=eins
	set | grep '^foo'
	echo =
	foo[0]=zwei
	foo[4]=drei
	set | grep '^foo'
	echo =
	echo a $(of ${foo[*]}) = $(of ${bar[*]}) a
	echo b $(of "${foo[*]}") = $(of "${bar[*]}") b
	echo c $(of ${foo[@]}) = $(of ${bar[@]}) c
	echo d $(of "${foo[@]}") = $(of "${bar[@]}") d
	echo e $(of ${!foo[*]}) = $(of ${!bar[*]}) e
	echo f $(of "${!foo[*]}") = $(of "${!bar[*]}") f
	echo g $(of ${!foo[@]}) = $(of ${!bar[@]}) g
	echo h $(of "${!foo[@]}") = $(of "${!bar[@]}") h
expected-stdout:
	foo[1]=eins
	=
	foo[0]=zwei
	foo[1]=eins
	foo[4]=drei
	=
	a 0<zwei>1<eins>2<drei> = a
	b 0<zwei eins drei> = 0<> b
	c 0<zwei>1<eins>2<drei> = c
	d 0<zwei>1<eins>2<drei> = d
	e 0<0>1<1>2<4> = e
	f 0<0 1 4> = 0<> f
	g 0<0>1<1>2<4> = g
	h 0<0>1<1>2<4> = h
---
name: arrays-7
description:
	Check if we can get the array keys (indices) for indexed arrays,
	Korn shell style, in some corner cases
stdin:
	echo !arz: ${!arz}
	echo !arz[0]: ${!arz[0]}
	echo !arz[1]: ${!arz[1]}
	arz=foo
	echo !arz: ${!arz}
	echo !arz[0]: ${!arz[0]}
	echo !arz[1]: ${!arz[1]}
	unset arz
	echo !arz: ${!arz}
	echo !arz[0]: ${!arz[0]}
	echo !arz[1]: ${!arz[1]}
expected-stdout:
	!arz: arz
	!arz[0]: arz[0]
	!arz[1]: arz[1]
	!arz: arz
	!arz[0]: arz[0]
	!arz[1]: arz[1]
	!arz: arz
	!arz[0]: arz[0]
	!arz[1]: arz[1]
---
name: arrays-8
description:
	Check some behavioural rules for arrays.
stdin:
	fna() {
		set -A aa 9
	}
	fnb() {
		typeset ab
		set -A ab 9
	}
	fnc() {
		typeset ac
		set -A ac 91
		unset ac
		set -A ac 92
	}
	fnd() {
		set +A ad 9
	}
	fne() {
		unset ae
		set +A ae 9
	}
	fnf() {
		unset af[0]
		set +A af 9
	}
	fng() {
		unset ag[*]
		set +A ag 9
	}
	set -A aa 1 2
	set -A ab 1 2
	set -A ac 1 2
	set -A ad 1 2
	set -A ae 1 2
	set -A af 1 2
	set -A ag 1 2
	set -A ah 1 2
	typeset -Z3 aa ab ac ad ae af ag
	print 1a ${aa[*]} .
	print 1b ${ab[*]} .
	print 1c ${ac[*]} .
	print 1d ${ad[*]} .
	print 1e ${ae[*]} .
	print 1f ${af[*]} .
	print 1g ${ag[*]} .
	print 1h ${ah[*]} .
	fna
	fnb
	fnc
	fnd
	fne
	fnf
	fng
	typeset -Z5 ah[*]
	print 2a ${aa[*]} .
	print 2b ${ab[*]} .
	print 2c ${ac[*]} .
	print 2d ${ad[*]} .
	print 2e ${ae[*]} .
	print 2f ${af[*]} .
	print 2g ${ag[*]} .
	print 2h ${ah[*]} .
expected-stdout:
	1a 001 002 .
	1b 001 002 .
	1c 001 002 .
	1d 001 002 .
	1e 001 002 .
	1f 001 002 .
	1g 001 002 .
	1h 1 2 .
	2a 9 .
	2b 001 002 .
	2c 92 .
	2d 009 002 .
	2e 9 .
	2f 9 002 .
	2g 009 .
	2h 00001 00002 .
---
name: arrays-9a
description:
	Check that we can concatenate arrays
stdin:
	unset foo; foo=(bar); foo+=(baz); echo 1 ${!foo[*]} : ${foo[*]} .
	unset foo; foo=(foo bar); foo+=(baz); echo 2 ${!foo[*]} : ${foo[*]} .
#	unset foo; foo=([2]=foo [0]=bar); foo+=(baz [5]=quux); echo 3 ${!foo[*]} : ${foo[*]} .
expected-stdout:
	1 0 1 : bar baz .
	2 0 1 2 : foo bar baz .
#	3 0 2 3 5 : bar foo baz quux .
---
name: arrays-9b
description:
	Check that we can concatenate parameters too
stdin:
	unset foo; foo=bar; foo+=baz; echo 1 $foo .
	unset foo; typeset -i16 foo=10; foo+=20; echo 2 $foo .
expected-stdout:
	1 barbaz .
	2 16#a20 .
---
name: arrassign-basic
description:
	Check basic whitespace conserving properties of wdarrassign
stdin:
	a=($(echo a  b))
	b=($(echo "a  b"))
	c=("$(echo "a  b")")
	d=("$(echo a  b)")
	a+=($(echo c  d))
	b+=($(echo "c  d"))
	c+=("$(echo "c  d")")
	d+=("$(echo c  d)")
	echo ".a:${a[0]}.${a[1]}.${a[2]}.${a[3]}:"
	echo ".b:${b[0]}.${b[1]}.${b[2]}.${b[3]}:"
	echo ".c:${c[0]}.${c[1]}.${c[2]}.${c[3]}:"
	echo ".d:${d[0]}.${d[1]}.${d[2]}.${d[3]}:"
expected-stdout:
	.a:a.b.c.d:
	.b:a.b.c.d:
	.c:a  b.c  d..:
	.d:a b.c d..:
---
name: arrassign-eol
description:
	Commands after array assignments are not permitted
stdin:
	foo=(a b) env
expected-exit: e != 0
expected-stderr-pattern:
	/syntax error: unexpected 'env'/
---
name: arrassign-fnc-none
description:
	Check locality of array access inside a function
stdin:
	function fn {
		x+=(f)
		echo ".fn:${x[0]}.${x[1]}.${x[2]}.${x[3]}:"
	}
	function rfn {
		if [[ -n $BASH_VERSION ]]; then
			y=()
		else
			set -A y
		fi
		y+=(f)
		echo ".rfn:${y[0]}.${y[1]}.${y[2]}.${y[3]}:"
	}
	x=(m m)
	y=(m m)
	echo ".f0:${x[0]}.${x[1]}.${x[2]}.${x[3]}:"
	fn
	echo ".f1:${x[0]}.${x[1]}.${x[2]}.${x[3]}:"
	fn
	echo ".f2:${x[0]}.${x[1]}.${x[2]}.${x[3]}:"
	echo ".rf0:${y[0]}.${y[1]}.${y[2]}.${y[3]}:"
	rfn
	echo ".rf1:${y[0]}.${y[1]}.${y[2]}.${y[3]}:"
	rfn
	echo ".rf2:${y[0]}.${y[1]}.${y[2]}.${y[3]}:"
expected-stdout:
	.f0:m.m..:
	.fn:m.m.f.:
	.f1:m.m.f.:
	.fn:m.m.f.f:
	.f2:m.m.f.f:
	.rf0:m.m..:
	.rfn:f...:
	.rf1:f...:
	.rfn:f...:
	.rf2:f...:
---
name: arrassign-fnc-local
description:
	Check locality of array access inside a function
	with the bash/mksh/ksh93 local/typeset keyword
	(note: ksh93 has no local; typeset works only in FKSH)
stdin:
	function fn {
		typeset x
		x+=(f)
		echo ".fn:${x[0]}.${x[1]}.${x[2]}.${x[3]}:"
	}
	function rfn {
		if [[ -n $BASH_VERSION ]]; then
			y=()
		else
			set -A y
		fi
		typeset y
		y+=(f)
		echo ".rfn:${y[0]}.${y[1]}.${y[2]}.${y[3]}:"
	}
	function fnr {
		typeset z
		if [[ -n $BASH_VERSION ]]; then
			z=()
		else
			set -A z
		fi
		z+=(f)
		echo ".fnr:${z[0]}.${z[1]}.${z[2]}.${z[3]}:"
	}
	x=(m m)
	y=(m m)
	z=(m m)
	echo ".f0:${x[0]}.${x[1]}.${x[2]}.${x[3]}:"
	fn
	echo ".f1:${x[0]}.${x[1]}.${x[2]}.${x[3]}:"
	fn
	echo ".f2:${x[0]}.${x[1]}.${x[2]}.${x[3]}:"
	echo ".rf0:${y[0]}.${y[1]}.${y[2]}.${y[3]}:"
	rfn
	echo ".rf1:${y[0]}.${y[1]}.${y[2]}.${y[3]}:"
	rfn
	echo ".rf2:${y[0]}.${y[1]}.${y[2]}.${y[3]}:"
	echo ".f0r:${z[0]}.${z[1]}.${z[2]}.${z[3]}:"
	fnr
	echo ".f1r:${z[0]}.${z[1]}.${z[2]}.${z[3]}:"
	fnr
	echo ".f2r:${z[0]}.${z[1]}.${z[2]}.${z[3]}:"
expected-stdout:
	.f0:m.m..:
	.fn:f...:
	.f1:m.m..:
	.fn:f...:
	.f2:m.m..:
	.rf0:m.m..:
	.rfn:f...:
	.rf1:...:
	.rfn:f...:
	.rf2:...:
	.f0r:m.m..:
	.fnr:f...:
	.f1r:m.m..:
	.fnr:f...:
	.f2r:m.m..:
---
name: arrassign-fnc-global
description:
	Check locality of array access inside a function
	with the bash4/mksh/yash/zsh typeset -g keyword
stdin:
	function fn {
		typeset -g x
		x+=(f)
		echo ".fn:${x[0]}.${x[1]}.${x[2]}.${x[3]}:"
	}
	function rfn {
		set -A y
		typeset -g y
		y+=(f)
		echo ".rfn:${y[0]}.${y[1]}.${y[2]}.${y[3]}:"
	}
	function fnr {
		typeset -g z
		set -A z
		z+=(f)
		echo ".fnr:${z[0]}.${z[1]}.${z[2]}.${z[3]}:"
	}
	x=(m m)
	y=(m m)
	z=(m m)
	echo ".f0:${x[0]}.${x[1]}.${x[2]}.${x[3]}:"
	fn
	echo ".f1:${x[0]}.${x[1]}.${x[2]}.${x[3]}:"
	fn
	echo ".f2:${x[0]}.${x[1]}.${x[2]}.${x[3]}:"
	echo ".rf0:${y[0]}.${y[1]}.${y[2]}.${y[3]}:"
	rfn
	echo ".rf1:${y[0]}.${y[1]}.${y[2]}.${y[3]}:"
	rfn
	echo ".rf2:${y[0]}.${y[1]}.${y[2]}.${y[3]}:"
	echo ".f0r:${z[0]}.${z[1]}.${z[2]}.${z[3]}:"
	fnr
	echo ".f1r:${z[0]}.${z[1]}.${z[2]}.${z[3]}:"
	fnr
	echo ".f2r:${z[0]}.${z[1]}.${z[2]}.${z[3]}:"
expected-stdout:
	.f0:m.m..:
	.fn:m.m.f.:
	.f1:m.m.f.:
	.fn:m.m.f.f:
	.f2:m.m.f.f:
	.rf0:m.m..:
	.rfn:f...:
	.rf1:f...:
	.rfn:f...:
	.rf2:f...:
	.f0r:m.m..:
	.fnr:f...:
	.f1r:f...:
	.fnr:f...:
	.f2r:f...:
---
name: strassign-fnc-none
description:
	Check locality of string access inside a function
stdin:
	function fn {
		x+=f
		echo ".fn:$x:"
	}
	function rfn {
		y=
		y+=f
		echo ".rfn:$y:"
	}
	x=m
	y=m
	echo ".f0:$x:"
	fn
	echo ".f1:$x:"
	fn
	echo ".f2:$x:"
	echo ".rf0:$y:"
	rfn
	echo ".rf1:$y:"
	rfn
	echo ".rf2:$y:"
expected-stdout:
	.f0:m:
	.fn:mf:
	.f1:mf:
	.fn:mff:
	.f2:mff:
	.rf0:m:
	.rfn:f:
	.rf1:f:
	.rfn:f:
	.rf2:f:
---
name: strassign-fnc-local
description:
	Check locality of string access inside a function
	with the bash/mksh/ksh93 local/typeset keyword
	(note: ksh93 has no local; typeset works only in FKSH)
stdin:
	function fn {
		typeset x
		x+=f
		echo ".fn:$x:"
	}
	function rfn {
		y=
		typeset y
		y+=f
		echo ".rfn:$y:"
	}
	function fnr {
		typeset z
		z=
		z+=f
		echo ".fnr:$z:"
	}
	x=m
	y=m
	z=m
	echo ".f0:$x:"
	fn
	echo ".f1:$x:"
	fn
	echo ".f2:$x:"
	echo ".rf0:$y:"
	rfn
	echo ".rf1:$y:"
	rfn
	echo ".rf2:$y:"
	echo ".f0r:$z:"
	fnr
	echo ".f1r:$z:"
	fnr
	echo ".f2r:$z:"
expected-stdout:
	.f0:m:
	.fn:f:
	.f1:m:
	.fn:f:
	.f2:m:
	.rf0:m:
	.rfn:f:
	.rf1::
	.rfn:f:
	.rf2::
	.f0r:m:
	.fnr:f:
	.f1r:m:
	.fnr:f:
	.f2r:m:
---
name: strassign-fnc-global
description:
	Check locality of string access inside a function
	with the bash4/mksh/yash/zsh typeset -g keyword
stdin:
	function fn {
		typeset -g x
		x+=f
		echo ".fn:$x:"
	}
	function rfn {
		y=
		typeset -g y
		y+=f
		echo ".rfn:$y:"
	}
	function fnr {
		typeset -g z
		z=
		z+=f
		echo ".fnr:$z:"
	}
	x=m
	y=m
	z=m
	echo ".f0:$x:"
	fn
	echo ".f1:$x:"
	fn
	echo ".f2:$x:"
	echo ".rf0:$y:"
	rfn
	echo ".rf1:$y:"
	rfn
	echo ".rf2:$y:"
	echo ".f0r:$z:"
	fnr
	echo ".f1r:$z:"
	fnr
	echo ".f2r:$z:"
expected-stdout:
	.f0:m:
	.fn:mf:
	.f1:mf:
	.fn:mff:
	.f2:mff:
	.rf0:m:
	.rfn:f:
	.rf1:f:
	.rfn:f:
	.rf2:f:
	.f0r:m:
	.fnr:f:
	.f1r:f:
	.fnr:f:
	.f2r:f:
---
name: unset-fnc-local-ksh
description:
	Check that ‚Äúunset‚Äù removes a previous ‚Äúlocal‚Äù
	(ksh93 syntax compatible version); apparently,
	there are shells which fail this?
stdin:
	function f {
		echo f0: $x
		typeset x
		echo f1: $x
		x=fa
		echo f2: $x
		unset x
		echo f3: $x
		x=fb
		echo f4: $x
	}
	x=o
	echo before: $x
	f
	echo after: $x
expected-stdout:
	before: o
	f0: o
	f1:
	f2: fa
	f3: o
	f4: fb
	after: fb
---
name: unset-fnc-local-sh
description:
	Check that ‚Äúunset‚Äù removes a previous ‚Äúlocal‚Äù
	(Debian Policy ¬ß10.4 sh version); apparently,
	there are shells which fail this?
stdin:
	f() {
		echo f0: $x
		local x
		echo f1: $x
		x=fa
		echo f2: $x
		unset x
		echo f3: $x
		x=fb
		echo f4: $x
	}
	x=o
	echo before: $x
	f
	echo after: $x
expected-stdout:
	before: o
	f0: o
	f1:
	f2: fa
	f3: o
	f4: fb
	after: fb
---
name: varexpand-substr-1
description:
	Check if bash-style substring expansion works
	when using positive numerics
stdin:
	x=abcdefghi
	typeset -i y=123456789
	typeset -i 16 z=123456789	# 16#75bcd15
	echo a t${x:2:2} ${y:2:3} ${z:2:3} a
	echo b ${x::3} ${y::3} ${z::3} b
	echo c ${x:2:} ${y:2:} ${z:2:} c
	echo d ${x:2} ${y:2} ${z:2} d
	echo e ${x:2:6} ${y:2:6} ${z:2:7} e
	echo f ${x:2:7} ${y:2:7} ${z:2:8} f
	echo g ${x:2:8} ${y:2:8} ${z:2:9} g
expected-stdout:
	a tcd 345 #75 a
	b abc 123 16# b
	c c
	d cdefghi 3456789 #75bcd15 d
	e cdefgh 345678 #75bcd1 e
	f cdefghi 3456789 #75bcd15 f
	g cdefghi 3456789 #75bcd15 g
---
name: varexpand-substr-2
description:
	Check if bash-style substring expansion works
	when using negative numerics or expressions
stdin:
	x=abcdefghi
	typeset -i y=123456789
	typeset -i 16 z=123456789	# 16#75bcd15
	n=2
	echo a ${x:$n:3} ${y:$n:3} ${z:$n:3} a
	echo b ${x:(n):3} ${y:(n):3} ${z:(n):3} b
	echo c ${x:(-2):1} ${y:(-2):1} ${z:(-2):1} c
	echo d t${x: n:2} ${y: n:3} ${z: n:3} d
expected-stdout:
	a cde 345 #75 a
	b cde 345 #75 b
	c h 8 1 c
	d tcd 345 #75 d
---
name: varexpand-substr-3
description:
	Match bash5
stdin:
	export x=abcdefghi n=2
	"$__progname" -c 'echo v${x:(n)}x'
	"$__progname" -c 'echo w${x: n}x'
	"$__progname" -c 'echo x${x:n}x'
	"$__progname" -c 'echo y${x:}x'
	"$__progname" -c 'echo z${x}x'
	"$__progname" -c 'x=abcdef;y=123;echo q${x:${y:2:1}:2}q'
expected-stdout:
	vcdefghix
	wcdefghix
	xcdefghix
	zabcdefghix
	qdeq
expected-stderr-pattern:
	/x:}.*bad substitution/
---
name: varexpand-substr-4
description:
	Check corner cases for substring expansion
stdin:
	x=abcdefghi
	integer y=2
	echo a ${x:(y == 1 ? 2 : 3):4} a
expected-stdout:
	a defg a
---
name: varexpand-substr-5A
description:
	Check that substring expansions work on characters
stdin:
	set +U
	x=m√§h
	echo a ${x::1} ${x: -1} a
	echo b ${x::3} ${x: -3} b
	echo c ${x:1:2} ${x: -3:2} c
	echo d ${#x} d
expected-stdout:
	a m h a
	b m√§ √§h b
	c √§ √§ c
	d 4 d
---
name: varexpand-substr-5W
description:
	Check that substring expansions work on characters
stdin:
	set -U
	x=m√§h
	echo a ${x::1} ${x: -1} a
	echo b ${x::2} ${x: -2} b
	echo c ${x:1:1} ${x: -2:1} c
	echo d ${#x} d
expected-stdout:
	a m h a
	b m√§ √§h b
	c √§ √§ c
	d 3 d
---
name: varexpand-substr-6
description:
	Check that string substitution works correctly
stdin:
	foo=1
	bar=2
	baz=qwertyuiop
	echo a ${baz: foo: bar}
	echo b ${baz: foo: $bar}
	echo c ${baz: $foo: bar}
	echo d ${baz: $foo: $bar}
expected-stdout:
	a we
	b we
	c we
	d we
---
name: varexpand-special-hash
description:
	Check special ${var@x} expansion for x=hash
category: !shell:ebcdic-yes
stdin:
	typeset -i8 foo=10
	bar=baz
	unset baz
	print ${foo@#} ${bar@#} ${baz@#} .
expected-stdout:
	9B15FBFB CFBDD32B 00000000 .
---
name: varexpand-special-hash-ebcdic
description:
	Check special ${var@x} expansion for x=hash
category: !shell:ebcdic-no
stdin:
	typeset -i8 foo=10
	bar=baz
	unset baz
	print ${foo@#} ${bar@#} ${baz@#} .
expected-stdout:
	016AE33D 9769C4AF 00000000 .
---
name: varexpand-special-quote
description:
	Check special ${var@Q} expansion for quoted strings
category: !shell:faux-ebcdic
stdin:
	set +U
	i=x
	j=a\ b
	k=$'c
	d\xA0''e‚Ç¨f'
	print -r -- "<i=$i j=$j k=$k>"
	s="u=${i@Q} v=${j@Q} w=${k@Q}"
	print -r -- "s=\"$s\""
	eval "$s"
	typeset -p u v w
expected-stdout:
	<i=x j=a b k=c
	d†e‚Ç¨f>
	s="u=x v='a b' w=$'c\nd\240e\u20ACf'"
	typeset u=x
	typeset v='a b'
	typeset w=$'c\nd\240e\u20ACf'
---
name: varexpand-special-quote-faux-EBCDIC
description:
	Check special ${var@Q} expansion for quoted strings
category: shell:faux-ebcdic
stdin:
	set +U
	i=x
	j=a\ b
	k=$'c
	d\xA0''e‚Ç¨f'
	print -r -- "<i=$i j=$j k=$k>"
	s="u=${i@Q} v=${j@Q} w=${k@Q}"
	print -r -- "s=\"$s\""
	eval "$s"
	typeset -p u v w
expected-stdout:
	<i=x j=a b k=c
	d†e‚Ç¨f>
	s="u=x v='a b' w=$'c\nd†e\u20ACf'"
	typeset u=x
	typeset v='a b'
	typeset w=$'c\nd†e\u20ACf'
---
name: varexpand-null-1
description:
	Ensure empty strings expand emptily
stdin:
	print s ${a} . ${b} S
	print t ${a#?} . ${b%?} T
	print r ${a=} . ${b/c/d} R
	print q
	print s "${a}" . "${b}" S
	print t "${a#?}" . "${b%?}" T
	print r "${a=}" . "${b/c/d}" R
expected-stdout:
	s . S
	t . T
	r . R
	q
	s  .  S
	t  .  T
	r  .  R
---
name: varexpand-null-2
description:
	Ensure empty strings, when quoted, are expanded as empty strings
stdin:
	print '#!'"$__progname"'\nfor x in "$@"; do print -nr -- "<$x> "; done' >pfs
	chmod +x pfs
	./pfs 1 "${a}" 2 "${a#?}" + "${b%?}" 3 "${a=}" + "${b/c/d}"
	echo .
expected-stdout:
	<1> <> <2> <> <+> <> <3> <> <+> <> .
---
name: varexpand-null-3
description:
	Ensure concatenating behaviour matches other shells
stdin:
	showargs() { for s_arg in "$@"; do echo -n "<$s_arg> "; done; echo .; }
	showargs 0 ""$@
	x=; showargs 1 "$x"$@
	set A; showargs 2 "${@:+}"
	n() { echo "$#"; }
	unset e
	set -- a b
	n """$@"
	n "$@"
	n "$@"""
	n "$e""$@"
	n "$@"
	n "$@""$e"
	set --
	n """$@"
	n "$@"
	n "$@"""
	n "$e""$@"
	n "$@"
	n "$@""$e"
expected-stdout:
	<0> <> .
	<1> <> .
	<2> <> .
	2
	2
	2
	2
	2
	2
	1
	0
	1
	1
	0
	1
---
name: varexpand-funny-chars
description:
	Check some characters
	XXX \uEF80 is asymmetric, possibly buggy so we don‚Äôt check this
stdin:
	x=$'<\x00>'; typeset -p x
	x=$'<\x01>'; typeset -p x
	x=$'<\u0000>'; typeset -p x
	x=$'<\u0001>'; typeset -p x
expected-stdout:
	typeset x='<'
	typeset x=$'<\001>'
	typeset x='<'
	typeset x=$'<\001>'
---
name: print-funny-chars
description:
	Check print builtin's capability to output designated characters
stdin:
	{
		print '<\0144\0344\xDB\u00DB\u20AC\uDB\x40>'
		print '<\x00>'
		print '<\x01>'
		print '<\u0000>'
		print '<\u0001>'
	} | {
		# integer-base-one-3Ar
		typeset -Uui16 -Z11 pos=0
		typeset -Uui16 -Z5 hv=2147483647
		dasc=
		if read -arN -1 line; then
			typeset -i1 line
			i=0
			while (( i < ${#line[*]} )); do
				hv=${line[i++]}
				if (( (pos & 15) == 0 )); then
					(( pos )) && print -r -- "$dasc|"
					print -n "${pos#16#}  "
					dasc=' |'
				fi
				print -n "${hv#16#} "
				if (( (hv < 32) || (hv > 126) )); then
					dasc=$dasc.
				else
					dasc=$dasc${line[i-1]#1#}
				fi
				(( (pos++ & 15) == 7 )) && print -n -- '- '
			done
		fi
		while (( pos & 15 )); do
			print -n '   '
			(( (pos++ & 15) == 7 )) && print -n -- '- '
		done
		(( hv == 2147483647 )) || print -r -- "$dasc|"
	}
expected-stdout:
	00000000  3C 64 E4 DB C3 9B E2 82 - AC C3 9B 40 3E 0A 3C 00  |<d.........@>.<.|
	00000010  3E 0A 3C 01 3E 0A 3C 00 - 3E 0A 3C 01 3E 0A        |>.<.>.<.>.<.>.|
---
name: print-bksl-c
description:
	Check print builtin's \c escape
stdin:
	print '\ca'; print b
expected-stdout:
	ab
---
name: print-cr
description:
	Check that CR+LF is not collapsed into LF as some MSYS shells wrongly do
stdin:
	echo '#!'"$__progname" >foo
	cat >>foo <<-'EOF'
		print -n -- '220-blau.mirbsd.org ESMTP ready at Thu, 25 Jul 2013 15:57:57 GMT\r\n220->> Bitte keine Werbung einwerfen! <<\r\r\n220 Who do you wanna pretend to be today'
		print \?
	EOF
	chmod +x foo
	echo "[$(./foo)]"
	./foo | while IFS= read -r line; do
		print -r -- "{$line}"
	done
expected-stdout:
	[220-blau.mirbsd.org ESMTP ready at Thu, 25 Jul 2013 15:57:57 GMT
	220->> Bitte keine Werbung einwerfen! <<
	220 Who do you wanna pretend to be today?]
	{220-blau.mirbsd.org ESMTP ready at Thu, 25 Jul 2013 15:57:57 GMT}
	{220->> Bitte keine Werbung einwerfen! <<}
	{220 Who do you wanna pretend to be today?}
---
name: print-crlf
description:
	Check that CR+LF is shown and read as-is
category: shell:textmode-no
stdin:
	cat >foo <<-'EOF'
		x='bar
		' #
		echo .${#x} #
		if test x"$KSH_VERSION" = x""; then #
			printf '<%s>' "$x" #
		else #
			print -nr -- "<$x>" #
		fi #
	EOF
	echo "[$("$__progname" foo)]"
	"$__progname" foo | while IFS= read -r line; do
		print -r -- "{$line}"
	done
expected-stdout:
	[.5
	<bar
	>]
	{.5}
	{<bar}
---
name: print-crlf-textmode
description:
	Check that CR+LF is treated as newline
category: shell:textmode-yes
stdin:
	cat >foo <<-'EOF'
		x='bar
		' #
		echo .${#x} #
		if test x"$KSH_VERSION" = x""; then #
			printf '<%s>' "$x" #
		else #
			print -nr -- "<$x>" #
		fi #
	EOF
	echo "[$("$__progname" foo)]"
	"$__progname" foo | while IFS= read -r line; do
		print -r -- "{$line}"
	done
expected-stdout:
	[.4
	<bar
	>]
	{.4}
	{<bar}
---
name: print-lf
description:
	Check that LF-only is shown and read as-is
stdin:
	cat >foo <<-'EOF'
		x='bar
		' #
		echo .${#x} #
		if test x"$KSH_VERSION" = x""; then #
			printf '<%s>' "$x" #
		else #
			print -nr -- "<$x>" #
		fi #
	EOF
	echo "[$("$__progname" foo)]"
	"$__progname" foo | while IFS= read -r line; do
		print -r -- "{$line}"
	done
expected-stdout:
	[.4
	<bar
	>]
	{.4}
	{<bar}
---
name: print-nul-chars
description:
	Check handling of NUL characters for print and COMSUB
stdin:
	x=$(print '<\0>')
	print $(($(print '<\0>' | wc -c))) $(($(print "$x" | wc -c))) \
	    ${#x} "$x" '<\0>'
expected-stdout-pattern:
	/^4 3 2 <> <\0>$/
---
name: print-array
description:
	Check that print -A works as expected
stdin:
	print -An 0x20AC 0xC3 0xBC 8#101
	set -U
	print -A 0x20AC 0xC3 0xBC 8#102
expected-stdout:
	¨√ºA‚Ç¨√É¬ºB
---
name: print-escapes
description:
	Check backslash expansion by the print builtin
stdin:
	print '\ \!\"\#\$\%\&'\\\''\(\)\*\+\,\-\.\/\0\1\2\3\4\5\6\7\8' \
	    '\9\:\;\<\=\>\?\@\A\B\C\D\E\F\G\H\I\J\K\L\M\N\O\P\Q\R\S\T' \
	    '\U\V\W\X\Y\Z\[\\\]\^\_\`\a\b  \d\e\f\g\h\i\j\k\l\m\n\o\p' \
	    '\q\r\s\t\u\v\w\x\y\z\{\|\}\~' '\u20acd' '\U20acd' '\x123' \
	    '\0x' '\0123' '\01234' | {
		# integer-base-one-3As
		typeset -Uui16 -Z11 pos=0
		typeset -Uui16 -Z5 hv=2147483647
		typeset -i1 wc=0x0A
		dasc=
		nl=${wc#1#}
		while IFS= read -r line; do
			line=$line$nl
			while [[ -n $line ]]; do
				hv=1#${line::1}
				if (( (pos & 15) == 0 )); then
					(( pos )) && print -r -- "$dasc|"
					print -n "${pos#16#}  "
					dasc=' |'
				fi
				print -n "${hv#16#} "
				if (( (hv < 32) || (hv > 126) )); then
					dasc=$dasc.
				else
					dasc=$dasc${line::1}
				fi
				(( (pos++ & 15) == 7 )) && print -n -- '- '
				line=${line:1}
			done
		done
		while (( pos & 15 )); do
			print -n '   '
			(( (pos++ & 15) == 7 )) && print -n -- '- '
		done
		(( hv == 2147483647 )) || print -r -- "$dasc|"
	}
expected-stdout:
	00000000  5C 20 5C 21 5C 22 5C 23 - 5C 24 5C 25 5C 26 5C 27  |\ \!\"\#\$\%\&\'|
	00000010  5C 28 5C 29 5C 2A 5C 2B - 5C 2C 5C 2D 5C 2E 5C 2F  |\(\)\*\+\,\-\.\/|
	00000020  5C 31 5C 32 5C 33 5C 34 - 5C 35 5C 36 5C 37 5C 38  |\1\2\3\4\5\6\7\8|
	00000030  20 5C 39 5C 3A 5C 3B 5C - 3C 5C 3D 5C 3E 5C 3F 5C  | \9\:\;\<\=\>\?\|
	00000040  40 5C 41 5C 42 5C 43 5C - 44 1B 5C 46 5C 47 5C 48  |@\A\B\C\D.\F\G\H|
	00000050  5C 49 5C 4A 5C 4B 5C 4C - 5C 4D 5C 4E 5C 4F 5C 50  |\I\J\K\L\M\N\O\P|
	00000060  5C 51 5C 52 5C 53 5C 54 - 20 5C 55 5C 56 5C 57 5C  |\Q\R\S\T \U\V\W\|
	00000070  58 5C 59 5C 5A 5C 5B 5C - 5C 5D 5C 5E 5C 5F 5C 60  |X\Y\Z\[\\]\^\_\`|
	00000080  07 08 20 20 5C 64 1B 0C - 5C 67 5C 68 5C 69 5C 6A  |..  \d..\g\h\i\j|
	00000090  5C 6B 5C 6C 5C 6D 0A 5C - 6F 5C 70 20 5C 71 0D 5C  |\k\l\m.\o\p \q.\|
	000000A0  73 09 5C 75 0B 5C 77 5C - 78 5C 79 5C 7A 5C 7B 5C  |s.\u.\w\x\y\z\{\|
	000000B0  7C 5C 7D 5C 7E 20 E2 82 - AC 64 20 EF BF BD 20 12  ||\}\~ ...d ... .|
	000000C0  33 20 78 20 53 20 53 34 - 0A                       |3 x S S4.|
---
name: dollar-doublequoted-strings
description:
	Check that a $ preceding "‚Ä¶" is ignored
stdin:
	echo $"Localise me!"
	cat <<<$"Me too!"
	V=X
	aol=aol
	cat <<-$"aol"
		I do not take a $V for a V!
	aol
expected-stdout:
	Localise me!
	Me too!
	I do not take a $V for a V!
---
name: dollar-quoted-strings
description:
	Check backslash expansion by $'‚Ä¶' strings
stdin:
	print '#!'"$__progname"'\nfor x in "$@"; do print -r -- "$x"; done' >pfn
	chmod +x pfn
	./pfn $'\ \!\"\#\$\%\&\'\(\)\*\+\,\-\.\/ \1\2\3\4\5\6' \
	    $'a\0b' $'a\01b' $'\7\8\9\:\;\<\=\>\?\@\A\B\C\D\E\F\G\H\I' \
	    $'\J\K\L\M\N\O\P\Q\R\S\T\U1\V\W\X\Y\Z\[\\\]\^\_\`\a\b\d\e' \
	    $'\f\g\h\i\j\k\l\m\n\o\p\q\r\s\t\u1\v\w\x1\y\z\{\|\}\~ $x' \
	    $'\u20acd' $'\U20acd' $'\x123' $'fn\x0rd' $'\0234' $'\234' \
	    $'\2345' $'\ca' $'\c!' $'\c?' $'\c‚Ä¶' $'a\
	b' | {
		# integer-base-one-3As
		typeset -Uui16 -Z11 pos=0
		typeset -Uui16 -Z5 hv=2147483647
		typeset -i1 wc=0x0A
		dasc=
		nl=${wc#1#}
		while IFS= read -r line; do
			line=$line$nl
			while [[ -n $line ]]; do
				hv=1#${line::1}
				if (( (pos & 15) == 0 )); then
					(( pos )) && print -r -- "$dasc|"
					print -n "${pos#16#}  "
					dasc=' |'
				fi
				print -n "${hv#16#} "
				if (( (hv < 32) || (hv > 126) )); then
					dasc=$dasc.
				else
					dasc=$dasc${line::1}
				fi
				(( (pos++ & 15) == 7 )) && print -n -- '- '
				line=${line:1}
			done
		done
		while (( pos & 15 )); do
			print -n '   '
			(( (pos++ & 15) == 7 )) && print -n -- '- '
		done
		(( hv == 2147483647 )) || print -r -- "$dasc|"
	}
expected-stdout:
	00000000  20 21 22 23 24 25 26 27 - 28 29 2A 2B 2C 2D 2E 2F  | !"#$%&'()*+,-./|
	00000010  20 01 02 03 04 05 06 0A - 61 0A 61 01 62 0A 07 38  | .......a.a.b..8|
	00000020  39 3A 3B 3C 3D 3E 3F 40 - 41 42 43 44 1B 46 47 48  |9:;<=>?@ABCD.FGH|
	00000030  49 0A 4A 4B 4C 4D 4E 4F - 50 51 52 53 54 01 56 57  |I.JKLMNOPQRST.VW|
	00000040  58 59 5A 5B 5C 5D 5E 5F - 60 07 08 64 1B 0A 0C 67  |XYZ[\]^_`..d...g|
	00000050  68 69 6A 6B 6C 6D 0A 6F - 70 71 0D 73 09 01 0B 77  |hijklm.opq.s...w|
	00000060  01 79 7A 7B 7C 7D 7E 20 - 24 78 0A E2 82 AC 64 0A  |.yz{|}~ $x....d.|
	00000070  EF BF BD 0A C4 A3 0A 66 - 6E 0A 13 34 0A 9C 0A 9C  |.......fn..4....|
	00000080  35 0A 01 0A 01 0A 7F 0A - 82 80 A6 0A 61 0A 62 0A  |5...........a.b.|
---
name: dollar-quotes-in-heredocs-strings
description:
	They are, however, not parsed in here documents, here strings
	(outside of string delimiters) or regular strings, but in
	parameter substitutions.
stdin:
	cat <<EOF
		dollar = strchr(s, '$');	/* ' */
		foo " bar \" baz
	EOF
	cat <<$'a\tb'
	a\tb
	a	b
	cat <<<"dollar = strchr(s, '$');	/* ' */"
	cat <<<'dollar = strchr(s, '\''$'\'');	/* '\'' */'
	x="dollar = strchr(s, '$');	/* ' */"
	cat <<<"$x"
	cat <<<$'a\E[0m\tb'
	unset nl; print -r -- "x${nl:=$'\n'}y"
	echo "1 foo\"bar"
	# cf & HEREDOC
	cat <<EOF
	2 foo\"bar
	EOF
	# probably never reached for here strings?
	cat <<<"3 foo\"bar"
	cat <<<"4 foo\\\"bar"
	cat <<<'5 foo\"bar'
	# old scripts use this (e.g. ncurses)
	echo "^$"
	# make sure this works, outside of quotes
	cat <<<'7'$'\t''.'
expected-stdout:
		dollar = strchr(s, '$');	/* ' */
		foo " bar \" baz
	a\tb
	dollar = strchr(s, '$');	/* ' */
	dollar = strchr(s, '$');	/* ' */
	dollar = strchr(s, '$');	/* ' */
	a[0m	b
	x
	y
	1 foo"bar
	2 foo\"bar
	3 foo"bar
	4 foo\"bar
	5 foo\"bar
	^$
	7	.
---
name: dot-needs-argument
description:
	check Debian #415167 solution: '.' without arguments should fail
stdin:
	"$__progname" -c .
	"$__progname" -c source
expected-exit: e != 0
expected-stderr-pattern:
	/\.: missing argument.*\n.*source: missing argument/
---
name: dot-errorlevel
description:
	Ensure dot resets $?
stdin:
	:>dotfile
	(exit 42)
	. ./dotfile
	echo 1 $? .
expected-stdout:
	1 0 .
---
name: alias-function-no-conflict
description:
	make aliases not conflict with function definitions
stdin:
	# POSIX function can be defined, but alias overrides it
	alias foo='echo bar'
	foo
	foo() {
		echo baz
	}
	foo
	unset -f foo
	foo 2>/dev/null || echo rab
	# alias overrides ksh function
	alias korn='echo bar'
	korn
	function korn {
		echo baz
	}
	korn
	# alias temporarily overrides POSIX function
	bla() {
		echo bfn
	}
	bla
	alias bla='echo bal'
	bla
	unalias bla
	bla
expected-stdout:
	bar
	bar
	bar
	bar
	bar
	bfn
	bal
	bfn
---
name: bash-function-parens
description:
	ensure the keyword function is ignored when preceding
	POSIX style function declarations (bashism)
stdin:
	mk() {
		echo '#!'"$__progname"
		echo "$1 {"
		echo '	echo "bar='\''$0'\'\"
		echo '}'
		print -r -- "${2:-foo}"
	}
	mk 'function foo' >f-korn
	mk 'foo ()' >f-dash
	mk 'function foo ()' >f-bash
	print '#!'"$__progname"'\nprint -r -- "${0%/f-argh}"' >f-argh
	chmod +x f-*
	u=$(./f-argh)
	x="korn: $(./f-korn)"; echo "${x/@("$u")/.}"
	x="dash: $(./f-dash)"; echo "${x/@("$u")/.}"
	x="bash: $(./f-bash)"; echo "${x/@("$u")/.}"
expected-stdout:
	korn: bar='foo'
	dash: bar='./f-dash'
	bash: bar='./f-bash'
---
name: integer-base-one-1
description:
	check if the use of fake integer base 1 works
stdin:
	set -U
	typeset -Uui16 i0=1#Ô i1=1#‚Ç¨
	typeset -i1 o0a=64
	typeset -i1 o1a=0x263A
	typeset -Uui1 o0b=0x7E
	typeset -Uui1 o1b=0xFDD0
	integer px=0xCAFE 'p0=1# ' p1=1#‚Ä¶ pl=1#f
	echo "in <$i0> <$i1>"
	echo "out <${o0a#1#}|${o0b#1#}> <${o1a#1#}|${o1b#1#}>"
	typeset -Uui1 i0 i1
	echo "pass <$px> <$p0> <$p1> <$pl> <${i0#1#}|${i1#1#}>"
	typeset -Uui16 tv1=1#~ tv2=1# tv3=1#Ä tv4=1#Å tv5=1#¿ tv6=1#¡ tv7=1#¬† tv8=1#¬Ä
	echo "specX <${tv1#16#}> <${tv2#16#}> <${tv3#16#}> <${tv4#16#}> <${tv5#16#}> <${tv6#16#}> <${tv7#16#}> <${tv8#16#}>"
	typeset -i1 tv1 tv2 tv3 tv4 tv5 tv6 tv7 tv8
	echo "specW <${tv1#1#}> <${tv2#1#}> <${tv3#1#}> <${tv4#1#}> <${tv5#1#}> <${tv6#1#}> <${tv7#1#}> <${tv8#1#}>"
	typeset -i1 xs1=0xEF7F xs2=0xEF80 xs3=0xFDD0
	echo "specU <${xs1#1#}> <${xs2#1#}> <${xs3#1#}>"
expected-stdout:
	in <16#EFEF> <16#20AC>
	out <@|~> <‚ò∫|Ô∑ê>
	pass <16#cafe> <1# > <1#‚Ä¶> <1#f> <Ô|‚Ç¨>
	specX <7E> <7F> <EF80> <EF81> <EFC0> <EFC1> <A0> <80>
	specW <~> <> <Ä> <Å> <¿> <¡> <¬†> <¬Ä>
	specU <ÓΩø> <Ä> <Ô∑ê>
---
name: integer-base-one-2a
description:
	check if the use of fake integer base 1 stops at correct characters
stdin:
	set -U
	integer x=1#foo
	echo /$x/
expected-stderr-pattern:
	/1#foo: unexpected 'oo'/
expected-exit: e != 0
---
name: integer-base-one-2b
description:
	check if the use of fake integer base 1 stops at correct characters
stdin:
	set -U
	integer x=1#¿Ä
	echo /$x/
expected-stderr-pattern:
	/1#¿Ä: unexpected 'Ä'/
expected-exit: e != 0
---
name: integer-base-one-2c1
description:
	check if the use of fake integer base 1 stops at correct characters
stdin:
	set -U
	integer x=1#‚Ä¶
	echo /$x/
expected-stdout:
	/1#‚Ä¶/
---
name: integer-base-one-2c2
description:
	check if the use of fake integer base 1 stops at correct characters
stdin:
	set +U
	integer x=1#‚Ä¶
	echo /$x/
expected-stderr-pattern:
	/1#‚Ä¶: unexpected 'Ä'/
expected-exit: e != 0
---
name: integer-base-one-2d1
description:
	check if the use of fake integer base 1 handles octets okay
stdin:
	set -U
	typeset -i16 x=1#ˇ
	echo /$x/	# invalid utf-8
expected-stdout:
	/16#efff/
---
name: integer-base-one-2d2
description:
	check if the use of fake integer base 1 handles octets
stdin:
	set -U
	typeset -i16 x=1#¬
	echo /$x/	# invalid 2-byte
expected-stdout:
	/16#efc2/
---
name: integer-base-one-2d3
description:
	check if the use of fake integer base 1 handles octets
stdin:
	set -U
	typeset -i16 x=1#Ô
	echo /$x/	# invalid 2-byte
expected-stdout:
	/16#efef/
---
name: integer-base-one-2d4
description:
	check if the use of fake integer base 1 stops at invalid input
stdin:
	set -U
	typeset -i16 x=1#Ôø¿
	echo /$x/	# invalid 3-byte
expected-stderr-pattern:
	/1#Ôø¿: unexpected 'ø'/
expected-exit: e != 0
---
name: integer-base-one-2d5
description:
	check if the use of fake integer base 1 stops at invalid input
stdin:
	set -U
	typeset -i16 x=1#¿Ä
	echo /$x/	# non-minimalistic
expected-stderr-pattern:
	/1#¿Ä: unexpected 'Ä'/
expected-exit: e != 0
---
name: integer-base-one-2d6
description:
	check if the use of fake integer base 1 stops at invalid input
stdin:
	set -U
	typeset -i16 x=1#‡ÄÄ
	echo /$x/	# non-minimalistic
expected-stderr-pattern:
	/1#‡ÄÄ: unexpected 'Ä'/
expected-exit: e != 0
---
name: integer-base-one-3As
description:
	some sample code for hexdumping
	not NUL safe; input lines must be NL terminated
stdin:
	{
		print 'Hello, World!\\\n„Åì„Çì„Å´„Å°„ÅØÔºÅ'
		typeset -Uui16 i=0x100
		# change that to 0xFF once we can handle embedded
		# NUL characters in strings / here documents
		while (( i++ < 0x1FF )); do
			print -n "\x${i#16#1}"
		done
		print '\0z'
	} | {
		# integer-base-one-3As
		typeset -Uui16 -Z11 pos=0
		typeset -Uui16 -Z5 hv=2147483647
		typeset -i1 wc=0x0A
		dasc=
		nl=${wc#1#}
		while IFS= read -r line; do
			line=$line$nl
			while [[ -n $line ]]; do
				hv=1#${line::1}
				if (( (pos & 15) == 0 )); then
					(( pos )) && print -r -- "$dasc|"
					print -n "${pos#16#}  "
					dasc=' |'
				fi
				print -n "${hv#16#} "
				if (( (hv < 32) || (hv > 126) )); then
					dasc=$dasc.
				else
					dasc=$dasc${line::1}
				fi
				(( (pos++ & 15) == 7 )) && print -n -- '- '
				line=${line:1}
			done
		done
		while (( pos & 15 )); do
			print -n '   '
			(( (pos++ & 15) == 7 )) && print -n -- '- '
		done
		(( hv == 2147483647 )) || print -r -- "$dasc|"
	}
expected-stdout:
	00000000  48 65 6C 6C 6F 2C 20 57 - 6F 72 6C 64 21 5C 0A E3  |Hello, World!\..|
	00000010  81 93 E3 82 93 E3 81 AB - E3 81 A1 E3 81 AF EF BC  |................|
	00000020  81 0A 01 02 03 04 05 06 - 07 08 09 0A 0B 0C 0D 0E  |................|
	00000030  0F 10 11 12 13 14 15 16 - 17 18 19 1A 1B 1C 1D 1E  |................|
	00000040  1F 20 21 22 23 24 25 26 - 27 28 29 2A 2B 2C 2D 2E  |. !"#$%&'()*+,-.|
	00000050  2F 30 31 32 33 34 35 36 - 37 38 39 3A 3B 3C 3D 3E  |/0123456789:;<=>|
	00000060  3F 40 41 42 43 44 45 46 - 47 48 49 4A 4B 4C 4D 4E  |?@ABCDEFGHIJKLMN|
	00000070  4F 50 51 52 53 54 55 56 - 57 58 59 5A 5B 5C 5D 5E  |OPQRSTUVWXYZ[\]^|
	00000080  5F 60 61 62 63 64 65 66 - 67 68 69 6A 6B 6C 6D 6E  |_`abcdefghijklmn|
	00000090  6F 70 71 72 73 74 75 76 - 77 78 79 7A 7B 7C 7D 7E  |opqrstuvwxyz{|}~|
	000000A0  7F 80 81 82 83 84 85 86 - 87 88 89 8A 8B 8C 8D 8E  |................|
	000000B0  8F 90 91 92 93 94 95 96 - 97 98 99 9A 9B 9C 9D 9E  |................|
	000000C0  9F A0 A1 A2 A3 A4 A5 A6 - A7 A8 A9 AA AB AC AD AE  |................|
	000000D0  AF B0 B1 B2 B3 B4 B5 B6 - B7 B8 B9 BA BB BC BD BE  |................|
	000000E0  BF C0 C1 C2 C3 C4 C5 C6 - C7 C8 C9 CA CB CC CD CE  |................|
	000000F0  CF D0 D1 D2 D3 D4 D5 D6 - D7 D8 D9 DA DB DC DD DE  |................|
	00000100  DF E0 E1 E2 E3 E4 E5 E6 - E7 E8 E9 EA EB EC ED EE  |................|
	00000110  EF F0 F1 F2 F3 F4 F5 F6 - F7 F8 F9 FA FB FC FD FE  |................|
	00000120  FF 7A 0A                -                          |.z.|
---
name: integer-base-one-3Ws
description:
	some sample code for hexdumping UCS-2
	not NUL safe; input lines must be NL terminated
stdin:
	set -U
	{
		print 'Hello, World!\\\n„Åì„Çì„Å´„Å°„ÅØÔºÅ'
		typeset -Uui16 i=0x100
		# change that to 0xFF once we can handle embedded
		# NUL characters in strings / here documents
		while (( i++ < 0x1FF )); do
			print -n "\u${i#16#1}"
		done
		print
		print \\xff		# invalid utf-8
		print \\xc2		# invalid 2-byte
		print \\xef\\xbf\\xc0	# invalid 3-byte
		print \\xc0\\x80	# non-minimalistic
		print \\xe0\\x80\\x80	# non-minimalistic
		print 'ÔøΩÔøæÔøø'	# end of range
		print '\0z'		# embedded NUL
	} | {
		# integer-base-one-3Ws
		typeset -Uui16 -Z11 pos=0
		typeset -Uui16 -Z7 hv
		typeset -i1 wc=0x0A
		typeset -i lpos
		dasc=
		nl=${wc#1#}
		while IFS= read -r line; do
			line=$line$nl
			lpos=0
			while (( lpos < ${#line} )); do
				wc=1#${line:(lpos++):1}
				if (( (wc < 32) || \
				    ((wc > 126) && (wc < 160)) )); then
					dch=.
				elif (( (wc & 0xFF80) == 0xEF80 )); then
					dch=ÔøΩ
				else
					dch=${wc#1#}
				fi
				if (( (pos & 7) == 7 )); then
					dasc=$dasc$dch
					dch=
				elif (( (pos & 7) == 0 )); then
					(( pos )) && print -r -- "$dasc|"
					print -n "${pos#16#}  "
					dasc=' |'
				fi
				let hv=wc
				print -n "${hv#16#} "
				(( (pos++ & 7) == 3 )) && \
				    print -n -- '- '
				dasc=$dasc$dch
			done
		done
		while (( pos & 7 )); do
			print -n '     '
			(( (pos++ & 7) == 3 )) && print -n -- '- '
		done
		(( hv == 2147483647 )) || print -r -- "$dasc|"
	}
expected-stdout:
	00000000  0048 0065 006C 006C - 006F 002C 0020 0057  |Hello, W|
	00000008  006F 0072 006C 0064 - 0021 005C 000A 3053  |orld!\.„Åì|
	00000010  3093 306B 3061 306F - FF01 000A 0001 0002  |„Çì„Å´„Å°„ÅØÔºÅ...|
	00000018  0003 0004 0005 0006 - 0007 0008 0009 000A  |........|
	00000020  000B 000C 000D 000E - 000F 0010 0011 0012  |........|
	00000028  0013 0014 0015 0016 - 0017 0018 0019 001A  |........|
	00000030  001B 001C 001D 001E - 001F 0020 0021 0022  |..... !"|
	00000038  0023 0024 0025 0026 - 0027 0028 0029 002A  |#$%&'()*|
	00000040  002B 002C 002D 002E - 002F 0030 0031 0032  |+,-./012|
	00000048  0033 0034 0035 0036 - 0037 0038 0039 003A  |3456789:|
	00000050  003B 003C 003D 003E - 003F 0040 0041 0042  |;<=>?@AB|
	00000058  0043 0044 0045 0046 - 0047 0048 0049 004A  |CDEFGHIJ|
	00000060  004B 004C 004D 004E - 004F 0050 0051 0052  |KLMNOPQR|
	00000068  0053 0054 0055 0056 - 0057 0058 0059 005A  |STUVWXYZ|
	00000070  005B 005C 005D 005E - 005F 0060 0061 0062  |[\]^_`ab|
	00000078  0063 0064 0065 0066 - 0067 0068 0069 006A  |cdefghij|
	00000080  006B 006C 006D 006E - 006F 0070 0071 0072  |klmnopqr|
	00000088  0073 0074 0075 0076 - 0077 0078 0079 007A  |stuvwxyz|
	00000090  007B 007C 007D 007E - 007F 0080 0081 0082  |{|}~....|
	00000098  0083 0084 0085 0086 - 0087 0088 0089 008A  |........|
	000000A0  008B 008C 008D 008E - 008F 0090 0091 0092  |........|
	000000A8  0093 0094 0095 0096 - 0097 0098 0099 009A  |........|
	000000B0  009B 009C 009D 009E - 009F 00A0 00A1 00A2  |.....¬†¬°¬¢|
	000000B8  00A3 00A4 00A5 00A6 - 00A7 00A8 00A9 00AA  |¬£¬§¬•¬¶¬ß¬®¬©¬™|
	000000C0  00AB 00AC 00AD 00AE - 00AF 00B0 00B1 00B2  |¬´¬¨¬≠¬Æ¬Ø¬∞¬±¬≤|
	000000C8  00B3 00B4 00B5 00B6 - 00B7 00B8 00B9 00BA  |¬≥¬¥¬µ¬∂¬∑¬∏¬π¬∫|
	000000D0  00BB 00BC 00BD 00BE - 00BF 00C0 00C1 00C2  |¬ª¬º¬Ω¬æ¬ø√Ä√Å√Ç|
	000000D8  00C3 00C4 00C5 00C6 - 00C7 00C8 00C9 00CA  |√É√Ñ√Ö√Ü√á√à√â√ä|
	000000E0  00CB 00CC 00CD 00CE - 00CF 00D0 00D1 00D2  |√ã√å√ç√é√è√ê√ë√í|
	000000E8  00D3 00D4 00D5 00D6 - 00D7 00D8 00D9 00DA  |√ì√î√ï√ñ√ó√ò√ô√ö|
	000000F0  00DB 00DC 00DD 00DE - 00DF 00E0 00E1 00E2  |√õ√ú√ù√û√ü√†√°√¢|
	000000F8  00E3 00E4 00E5 00E6 - 00E7 00E8 00E9 00EA  |√£√§√•√¶√ß√®√©√™|
	00000100  00EB 00EC 00ED 00EE - 00EF 00F0 00F1 00F2  |√´√¨√≠√Æ√Ø√∞√±√≤|
	00000108  00F3 00F4 00F5 00F6 - 00F7 00F8 00F9 00FA  |√≥√¥√µ√∂√∑√∏√π√∫|
	00000110  00FB 00FC 00FD 00FE - 00FF 000A EFFF 000A  |√ª√º√Ω√æ√ø.ÔøΩ.|
	00000118  EFC2 000A EFEF EFBF - EFC0 000A EFC0 EF80  |ÔøΩ.ÔøΩÔøΩÔøΩ.ÔøΩÔøΩ|
	00000120  000A EFE0 EF80 EF80 - 000A FFFD EFEF EFBF  |.ÔøΩÔøΩÔøΩ.ÔøΩÔøΩÔøΩ|
	00000128  EFBE EFEF EFBF EFBF - 000A 007A 000A       |ÔøΩÔøΩÔøΩÔøΩ.z.|
---
name: integer-base-one-3Ar
description:
	some sample code for hexdumping; NUL and binary safe
stdin:
	{
		print 'Hello, World!\\\n„Åì„Çì„Å´„Å°„ÅØÔºÅ'
		typeset -Uui16 i=0x100
		# change that to 0xFF once we can handle embedded
		# NUL characters in strings / here documents
		while (( i++ < 0x1FF )); do
			print -n "\x${i#16#1}"
		done
		print '\0z'
	} | {
		# integer-base-one-3Ar
		typeset -Uui16 -Z11 pos=0
		typeset -Uui16 -Z5 hv=2147483647
		dasc=
		if read -arN -1 line; then
			typeset -i1 line
			i=0
			while (( i < ${#line[*]} )); do
				hv=${line[i++]}
				if (( (pos & 15) == 0 )); then
					(( pos )) && print -r -- "$dasc|"
					print -n "${pos#16#}  "
					dasc=' |'
				fi
				print -n "${hv#16#} "
				if (( (hv < 32) || (hv > 126) )); then
					dasc=$dasc.
				else
					dasc=$dasc${line[i-1]#1#}
				fi
				(( (pos++ & 15) == 7 )) && print -n -- '- '
			done
		fi
		while (( pos & 15 )); do
			print -n '   '
			(( (pos++ & 15) == 7 )) && print -n -- '- '
		done
		(( hv == 2147483647 )) || print -r -- "$dasc|"
	}
expected-stdout:
	00000000  48 65 6C 6C 6F 2C 20 57 - 6F 72 6C 64 21 5C 0A E3  |Hello, World!\..|
	00000010  81 93 E3 82 93 E3 81 AB - E3 81 A1 E3 81 AF EF BC  |................|
	00000020  81 0A 01 02 03 04 05 06 - 07 08 09 0A 0B 0C 0D 0E  |................|
	00000030  0F 10 11 12 13 14 15 16 - 17 18 19 1A 1B 1C 1D 1E  |................|
	00000040  1F 20 21 22 23 24 25 26 - 27 28 29 2A 2B 2C 2D 2E  |. !"#$%&'()*+,-.|
	00000050  2F 30 31 32 33 34 35 36 - 37 38 39 3A 3B 3C 3D 3E  |/0123456789:;<=>|
	00000060  3F 40 41 42 43 44 45 46 - 47 48 49 4A 4B 4C 4D 4E  |?@ABCDEFGHIJKLMN|
	00000070  4F 50 51 52 53 54 55 56 - 57 58 59 5A 5B 5C 5D 5E  |OPQRSTUVWXYZ[\]^|
	00000080  5F 60 61 62 63 64 65 66 - 67 68 69 6A 6B 6C 6D 6E  |_`abcdefghijklmn|
	00000090  6F 70 71 72 73 74 75 76 - 77 78 79 7A 7B 7C 7D 7E  |opqrstuvwxyz{|}~|
	000000A0  7F 80 81 82 83 84 85 86 - 87 88 89 8A 8B 8C 8D 8E  |................|
	000000B0  8F 90 91 92 93 94 95 96 - 97 98 99 9A 9B 9C 9D 9E  |................|
	000000C0  9F A0 A1 A2 A3 A4 A5 A6 - A7 A8 A9 AA AB AC AD AE  |................|
	000000D0  AF B0 B1 B2 B3 B4 B5 B6 - B7 B8 B9 BA BB BC BD BE  |................|
	000000E0  BF C0 C1 C2 C3 C4 C5 C6 - C7 C8 C9 CA CB CC CD CE  |................|
	000000F0  CF D0 D1 D2 D3 D4 D5 D6 - D7 D8 D9 DA DB DC DD DE  |................|
	00000100  DF E0 E1 E2 E3 E4 E5 E6 - E7 E8 E9 EA EB EC ED EE  |................|
	00000110  EF F0 F1 F2 F3 F4 F5 F6 - F7 F8 F9 FA FB FC FD FE  |................|
	00000120  FF 00 7A 0A             -                          |..z.|
---
name: integer-base-one-3Wr
description:
	some sample code for hexdumping UCS-2; NUL and binary safe
stdin:
	set -U
	{
		print 'Hello, World!\\\n„Åì„Çì„Å´„Å°„ÅØÔºÅ'
		typeset -Uui16 i=0x100
		# change that to 0xFF once we can handle embedded
		# NUL characters in strings / here documents
		while (( i++ < 0x1FF )); do
			print -n "\u${i#16#1}"
		done
		print
		print \\xff		# invalid utf-8
		print \\xc2		# invalid 2-byte
		print \\xef\\xbf\\xc0	# invalid 3-byte
		print \\xc0\\x80	# non-minimalistic
		print \\xe0\\x80\\x80	# non-minimalistic
		print 'ÔøΩÔøæÔøø'	# end of range
		print '\0z'		# embedded NUL
	} | {
		# integer-base-one-3Wr
		typeset -Uui16 -Z11 pos=0
		typeset -Uui16 -Z7 hv=2147483647
		dasc=
		if read -arN -1 line; then
			typeset -i1 line
			i=0
			while (( i < ${#line[*]} )); do
				hv=${line[i++]}
				if (( (hv < 32) || \
				    ((hv > 126) && (hv < 160)) )); then
					dch=.
				elif (( (hv & 0xFF80) == 0xEF80 )); then
					dch=ÔøΩ
				else
					dch=${line[i-1]#1#}
				fi
				if (( (pos & 7) == 7 )); then
					dasc=$dasc$dch
					dch=
				elif (( (pos & 7) == 0 )); then
					(( pos )) && print -r -- "$dasc|"
					print -n "${pos#16#}  "
					dasc=' |'
				fi
				print -n "${hv#16#} "
				(( (pos++ & 7) == 3 )) && \
				    print -n -- '- '
				dasc=$dasc$dch
			done
		fi
		while (( pos & 7 )); do
			print -n '     '
			(( (pos++ & 7) == 3 )) && print -n -- '- '
		done
		(( hv == 2147483647 )) || print -r -- "$dasc|"
	}
expected-stdout:
	00000000  0048 0065 006C 006C - 006F 002C 0020 0057  |Hello, W|
	00000008  006F 0072 006C 0064 - 0021 005C 000A 3053  |orld!\.„Åì|
	00000010  3093 306B 3061 306F - FF01 000A 0001 0002  |„Çì„Å´„Å°„ÅØÔºÅ...|
	00000018  0003 0004 0005 0006 - 0007 0008 0009 000A  |........|
	00000020  000B 000C 000D 000E - 000F 0010 0011 0012  |........|
	00000028  0013 0014 0015 0016 - 0017 0018 0019 001A  |........|
	00000030  001B 001C 001D 001E - 001F 0020 0021 0022  |..... !"|
	00000038  0023 0024 0025 0026 - 0027 0028 0029 002A  |#$%&'()*|
	00000040  002B 002C 002D 002E - 002F 0030 0031 0032  |+,-./012|
	00000048  0033 0034 0035 0036 - 0037 0038 0039 003A  |3456789:|
	00000050  003B 003C 003D 003E - 003F 0040 0041 0042  |;<=>?@AB|
	00000058  0043 0044 0045 0046 - 0047 0048 0049 004A  |CDEFGHIJ|
	00000060  004B 004C 004D 004E - 004F 0050 0051 0052  |KLMNOPQR|
	00000068  0053 0054 0055 0056 - 0057 0058 0059 005A  |STUVWXYZ|
	00000070  005B 005C 005D 005E - 005F 0060 0061 0062  |[\]^_`ab|
	00000078  0063 0064 0065 0066 - 0067 0068 0069 006A  |cdefghij|
	00000080  006B 006C 006D 006E - 006F 0070 0071 0072  |klmnopqr|
	00000088  0073 0074 0075 0076 - 0077 0078 0079 007A  |stuvwxyz|
	00000090  007B 007C 007D 007E - 007F 0080 0081 0082  |{|}~....|
	00000098  0083 0084 0085 0086 - 0087 0088 0089 008A  |........|
	000000A0  008B 008C 008D 008E - 008F 0090 0091 0092  |........|
	000000A8  0093 0094 0095 0096 - 0097 0098 0099 009A  |........|
	000000B0  009B 009C 009D 009E - 009F 00A0 00A1 00A2  |.....¬†¬°¬¢|
	000000B8  00A3 00A4 00A5 00A6 - 00A7 00A8 00A9 00AA  |¬£¬§¬•¬¶¬ß¬®¬©¬™|
	000000C0  00AB 00AC 00AD 00AE - 00AF 00B0 00B1 00B2  |¬´¬¨¬≠¬Æ¬Ø¬∞¬±¬≤|
	000000C8  00B3 00B4 00B5 00B6 - 00B7 00B8 00B9 00BA  |¬≥¬¥¬µ¬∂¬∑¬∏¬π¬∫|
	000000D0  00BB 00BC 00BD 00BE - 00BF 00C0 00C1 00C2  |¬ª¬º¬Ω¬æ¬ø√Ä√Å√Ç|
	000000D8  00C3 00C4 00C5 00C6 - 00C7 00C8 00C9 00CA  |√É√Ñ√Ö√Ü√á√à√â√ä|
	000000E0  00CB 00CC 00CD 00CE - 00CF 00D0 00D1 00D2  |√ã√å√ç√é√è√ê√ë√í|
	000000E8  00D3 00D4 00D5 00D6 - 00D7 00D8 00D9 00DA  |√ì√î√ï√ñ√ó√ò√ô√ö|
	000000F0  00DB 00DC 00DD 00DE - 00DF 00E0 00E1 00E2  |√õ√ú√ù√û√ü√†√°√¢|
	000000F8  00E3 00E4 00E5 00E6 - 00E7 00E8 00E9 00EA  |√£√§√•√¶√ß√®√©√™|
	00000100  00EB 00EC 00ED 00EE - 00EF 00F0 00F1 00F2  |√´√¨√≠√Æ√Ø√∞√±√≤|
	00000108  00F3 00F4 00F5 00F6 - 00F7 00F8 00F9 00FA  |√≥√¥√µ√∂√∑√∏√π√∫|
	00000110  00FB 00FC 00FD 00FE - 00FF 000A EFFF 000A  |√ª√º√Ω√æ√ø.ÔøΩ.|
	00000118  EFC2 000A EFEF EFBF - EFC0 000A EFC0 EF80  |ÔøΩ.ÔøΩÔøΩÔøΩ.ÔøΩÔøΩ|
	00000120  000A EFE0 EF80 EF80 - 000A FFFD EFEF EFBF  |.ÔøΩÔøΩÔøΩ.ÔøΩÔøΩÔøΩ|
	00000128  EFBE EFEF EFBF EFBF - 000A 0000 007A 000A  |ÔøΩÔøΩÔøΩÔøΩ..z.|
---
name: integer-base-one-4
description:
	Check if ksh93-style base-one integers work
category: !smksh
stdin:
	set -U
	echo 1 $(('a'))
	(echo 2f $(('aa'))) 2>&1 | sed "s/^[^']*'/2p '/"
	echo 3 $(('‚Ä¶'))
	x="'a'"
	echo "4 <$x>"
	echo 5 $(($x))
	echo 6 $((x))
expected-stdout:
	1 97
	2p 'aa': multi-character character constant
	3 8230
	4 <'a'>
	5 97
	6 97
---
name: integer-base-one-5A
description:
	Check to see that we‚Äôre NUL and UCS safe
category: !shell:ebcdic-yes
stdin:
	set +U
	print 'a\0b\xfdz' >x
	read -a y <x
	set -U
	typeset -Uui16 y
	print ${y[*]} .
expected-stdout:
	16#61 16#0 16#62 16#FD 16#7A .
---
name: integer-base-one-5E
description:
	Check to see that we‚Äôre NUL and UCS safe
category: !shell:ebcdic-no
stdin:
	set +U
	print 'a\0b\xfdz' >x
	read -a y <x
	set -U
	typeset -Uui16 y
	print ${y[*]} .
expected-stdout:
	16#81 16#0 16#82 16#FD 16#A9 .
---
name: integer-base-one-5W
description:
	Check to see that we‚Äôre NUL and UCS safe
stdin:
	set -U
	print 'a\0b‚Ç¨c' >x
	read -a y <x
	set +U
	typeset -Uui16 y
	print ${y[*]} .
expected-stdout:
	16#61 16#0 16#62 16#20AC 16#63 .
---
name: ulimit-1
description:
	Check that ulimit as used in dot.mksh works or is stubbed
stdin:
	ulimit -c 0
---
name: ulimit-2
description:
	Check if we can use a specific syntax idiom for ulimit
	XXX Haiku works, but only for -n and -V
category: !os:haiku,!os:syllable
stdin:
	if ! x=$(ulimit -d) || [[ $x = unknown ]]; then
		#echo expected to fail on this OS
		echo okay
	else
		ulimit -dS $x && echo okay
	fi
expected-stdout:
	okay
---
name: ulimit-3
description:
	Check that there are no duplicate limits (if this fails,
	immediately contact with system information the developers)
stdin:
	[[ -z $(set | grep ^opt) ]]; mis=$?
	set | grep ^opt | sed 's/^/unexpectedly set in environment: /'
	opta='<used for showing all limits>'
	optH='<used to set hard limits>'
	optS='<used to set soft limits>'
	ulimit -a >tmpf
	set -o noglob
	while IFS= read -r line; do
		x=${line:1:1}
		if [[ -z $x || ${#x}/${%x} != 1/1 ]]; then
			print -r -- "weird line: $line"
			(( mis |= 1 ))
			continue
		fi
		set -- $line
		nameref v=opt$x
		if [[ -n $v ]]; then
			print -r -- "duplicate -$x \"$2\" already seen as \"$v\""
			(( mis |= 2 ))
		fi
		v=$2
	done <tmpf
	if (( mis & 2 )); then
		echo failed
	elif (( mis & 1 )); then
		echo inconclusive
	else
		echo done
	fi
expected-stdout:
	done
---
name: redir-1
description:
	Check some of the most basic invariants of I/O redirection
stdin:
	i=0
	function d {
		print o$i.
		print -u2 e$((i++)).
	}
	d >a 2>b
	echo =1=
	cat a
	echo =2=
	cat b
	echo =3=
	d 2>&1 >c
	echo =4=
	cat c
	echo =5=
expected-stdout:
	=1=
	o0.
	=2=
	e0.
	=3=
	e1.
	=4=
	o1.
	=5=
---
name: bashiop-1
description:
	Check if GNU bash-like I/O redirection works
	Part 1: this is also supported by GNU bash
stdin:
	exec 3>&1
	function threeout {
		echo ras
		echo dwa >&2
		echo tri >&3
	}
	threeout &>foo
	echo ===
	cat foo
expected-stdout:
	tri
	===
	ras
	dwa
---
name: bashiop-2a
description:
	Check if GNU bash-like I/O redirection works
	Part 2: this is *not* supported by GNU bash
stdin:
	exec 3>&1
	function threeout {
		echo ras
		echo dwa >&2
		echo tri >&3
	}
	threeout 3&>foo
	echo ===
	cat foo
expected-stdout:
	ras
	===
	dwa
	tri
---
name: bashiop-2b
description:
	Check if GNU bash-like I/O redirection works
	Part 2: this is *not* supported by GNU bash
stdin:
	exec 3>&1
	function threeout {
		echo ras
		echo dwa >&2
		echo tri >&3
	}
	threeout 3>foo &>&3
	echo ===
	cat foo
expected-stdout:
	===
	ras
	dwa
	tri
---
name: bashiop-2c
description:
	Check if GNU bash-like I/O redirection works
	Part 2: this is supported by GNU bash 4 only
stdin:
	echo mir >foo
	set -o noclobber
	exec 3>&1
	function threeout {
		echo ras
		echo dwa >&2
		echo tri >&3
	}
	threeout &>>foo
	echo ===
	cat foo
expected-stdout:
	tri
	===
	mir
	ras
	dwa
---
name: bashiop-3a
description:
	Check if GNU bash-like I/O redirection fails correctly
	Part 1: this is also supported by GNU bash
stdin:
	echo mir >foo
	set -o noclobber
	exec 3>&1
	function threeout {
		echo ras
		echo dwa >&2
		echo tri >&3
	}
	threeout &>foo
	echo ===
	cat foo
expected-stdout:
	===
	mir
expected-stderr-pattern: /.*: can't (create|overwrite) .*/
---
name: bashiop-3b
description:
	Check if GNU bash-like I/O redirection fails correctly
	Part 2: this is *not* supported by GNU bash
stdin:
	echo mir >foo
	set -o noclobber
	exec 3>&1
	function threeout {
		echo ras
		echo dwa >&2
		echo tri >&3
	}
	threeout &>|foo
	echo ===
	cat foo
expected-stdout:
	tri
	===
	ras
	dwa
---
name: bashiop-4
description:
	Check if GNU bash-like I/O redirection works
	Part 4: this is also supported by GNU bash,
	but failed in some mksh versions
stdin:
	exec 3>&1
	function threeout {
		echo ras
		echo dwa >&2
		echo tri >&3
	}
	function blubb {
		[[ -e bar ]] && threeout "$bf" &>foo
	}
	blubb
	echo -n >bar
	blubb
	echo ===
	cat foo
expected-stdout:
	tri
	===
	ras
	dwa
---
name: bashiop-5
description:
	Check if GNU bash-like I/O redirection is only supported
	in !POSIX !sh mode as it breaks existing scripts' syntax
stdin:
	:>x; echo 1 "$("$__progname" -c 'echo foo>/dev/null&>x echo bar')" = "$(<x)" .
	:>x; echo 2 "$("$__progname" -o posix -c 'echo foo>/dev/null&>x echo bar')" = "$(<x)" .
	:>x; echo 3 "$("$__progname" -o sh -c 'echo foo>/dev/null&>x echo bar')" = "$(<x)" .
expected-stdout:
	1  = foo echo bar .
	2  = bar .
	3  = bar .
---
name: oksh-eval
description:
	Check expansions.
stdin:
	a=
	for n in ${a#*=}; do echo 1hu ${n} .; done
	for n in "${a#*=}"; do echo 1hq ${n} .; done
	for n in ${a##*=}; do echo 2hu ${n} .; done
	for n in "${a##*=}"; do echo 2hq ${n} .; done
	for n in ${a%=*}; do echo 1pu ${n} .; done
	for n in "${a%=*}"; do echo 1pq ${n} .; done
	for n in ${a%%=*}; do echo 2pu ${n} .; done
	for n in "${a%%=*}"; do echo 2pq ${n} .; done
expected-stdout:
	1hq .
	2hq .
	1pq .
	2pq .
---
name: oksh-and-list-error-1
description:
	Test exit status of rightmost element in 2 element && list in -e mode
stdin:
	true && false
	echo "should not print"
arguments: !-e!
expected-exit: e != 0
---
name: oksh-and-list-error-2
description:
	Test exit status of rightmost element in 3 element && list in -e mode
stdin:
	true && true && false
	echo "should not print"
arguments: !-e!
expected-exit: e != 0
---
name: oksh-or-list-error-1
description:
	Test exit status of || list in -e mode
stdin:
	false || false
	echo "should not print"
arguments: !-e!
expected-exit: e != 0
---
name: oksh-longline-crash
description:
	This used to cause a core dump
stdin:
	ulimit -c 0
	deplibs="-lz -lpng /usr/local/lib/libjpeg.la -ltiff -lm -lX11 -lXext /usr/local/lib/libiconv.la -L/usr/local/lib -L/usr/ports/devel/gettext/w-gettext-0.10.40/gettext-0.10.40/intl/.libs /usr/local/lib/libintl.la /usr/local/lib/libglib.la /usr/local/lib/libgmodule.la -lintl -lm -lX11 -lXext -L/usr/X11R6/lib -lglib -lgmodule -L/usr/local/lib /usr/local/lib/libgdk.la -lintl -lm -lX11 -lXext -L/usr/X11R6/lib -lglib -lgmodule -L/usr/local/lib /usr/local/lib/libgtk.la -ltiff -ljpeg -lz -lpng -lm -lX11 -lXext -lintl -lglib -lgmodule -lgdk -lgtk -L/usr/X11R6/lib -lglib -lgmodule -L/usr/local/lib /usr/local/lib/libgdk_pixbuf.la -lz -lpng /usr/local/lib/libiconv.la -L/usr/local/lib -L/usr/ports/devel/gettext/w-gettext-0.10.40/gettext-0.10.40/intl/.libs /usr/local/lib/libintl.la /usr/local/lib/libglib.la -lm -lm /usr/local/lib/libaudiofile.la -lm -lm -laudiofile -L/usr/local/lib /usr/local/lib/libesd.la -lm -lz -L/usr/local/lib /usr/local/lib/libgnomesupport.la -lm -lz -lm -lglib -L/usr/local/lib /usr/local/lib/libgnome.la -lX11 -lXext /usr/local/lib/libiconv.la -L/usr/local/lib -L/usr/ports/devel/gettext/w-gettext-0.10.40/gettext-0.10.40/intl/.libs /usr/local/lib/libintl.la /usr/local/lib/libgmodule.la -lintl -lm -lX11 -lXext -L/usr/X11R6/lib -lglib -lgmodule -L/usr/local/lib /usr/local/lib/libgdk.la -lintl -lm -lX11 -lXext -L/usr/X11R6/lib -lglib -lgmodule -L/usr/local/lib /usr/local/lib/libgtk.la -lICE -lSM -lz -lpng /usr/local/lib/libungif.la /usr/local/lib/libjpeg.la -ltiff -lm -lz -lpng /usr/local/lib/libungif.la -lz /usr/local/lib/libjpeg.la -ltiff -L/usr/local/lib -L/usr/X11R6/lib /usr/local/lib/libgdk_imlib.la -lm -L/usr/local/lib /usr/local/lib/libart_lgpl.la -lm -lz -lm -lX11 -lXext -lintl -lglib -lgmodule -lgdk -lgtk -lICE -lSM -lm -lX11 -lXext -lintl -lglib -lgmodule -lgdk -lgtk -L/usr/X11R6/lib -lm -lz -lpng -lungif -lz -ljpeg -ltiff -ljpeg -lgdk_imlib -lglib -lm -laudiofile -lm -laudiofile -lesd -L/usr/local/lib /usr/local/lib/libgnomeui.la -lz -lz /usr/local/lib/libxml.la -lz -lz -lz /usr/local/lib/libxml.la -lm -lX11 -lXext /usr/local/lib/libiconv.la -L/usr/ports/devel/gettext/w-gettext-0.10.40/gettext-0.10.40/intl/.libs /usr/local/lib/libintl.la /usr/local/lib/libglib.la /usr/local/lib/libgmodule.la -lintl -lglib -lgmodule /usr/local/lib/libgdk.la /usr/local/lib/libgtk.la -L/usr/X11R6/lib -L/usr/local/lib /usr/local/lib/libglade.la -lz -lz -lz /usr/local/lib/libxml.la /usr/local/lib/libglib.la -lm -lm /usr/local/lib/libaudiofile.la -lm -lm -laudiofile /usr/local/lib/libesd.la -lm -lz /usr/local/lib/libgnomesupport.la -lm -lz -lm -lglib /usr/local/lib/libgnome.la -lX11 -lXext /usr/local/lib/libiconv.la -L/usr/ports/devel/gettext/w-gettext-0.10.40/gettext-0.10.40/intl/.libs /usr/local/lib/libintl.la /usr/local/lib/libgmodule.la -lintl -lm -lX11 -lXext -lglib -lgmodule /usr/local/lib/libgdk.la -lintl -lm -lX11 -lXext -lglib -lgmodule /usr/local/lib/libgtk.la -lICE -lSM -lz -lpng /usr/local/lib/libungif.la /usr/local/lib/libjpeg.la -ltiff -lm -lz -lz /usr/local/lib/libgdk_imlib.la /usr/local/lib/libart_lgpl.la -lm -lz -lm -lX11 -lXext -lintl -lglib -lgmodule -lgdk -lgtk -lm -lX11 -lXext -lintl -lglib -lgmodule -lgdk -lgtk -lm -lz -lungif -lz -ljpeg -ljpeg -lgdk_imlib -lglib -lm -laudiofile -lm -laudiofile -lesd /usr/local/lib/libgnomeui.la -L/usr/X11R6/lib -L/usr/local/lib /usr/local/lib/libglade-gnome.la /usr/local/lib/libglib.la -lm -lm /usr/local/lib/libaudiofile.la -lm -lm -laudiofile -L/usr/local/lib /usr/local/lib/libesd.la -lm -lz -L/usr/local/lib /usr/local/lib/libgnomesupport.la -lm -lz -lm -lglib -L/usr/local/lib /usr/local/lib/libgnome.la -lX11 -lXext /usr/local/lib/libiconv.la -L/usr/local/lib -L/usr/ports/devel/gettext/w-gettext-0.10.40/gettext-0.10.40/intl/.libs /usr/local/lib/libintl.la /usr/local/lib/libgmodule.la -lintl -lm -lX11 -lXext -L/usr/X11R6/lib -lglib -lgmodule -L/usr/local/lib /usr/local/lib/libgdk.la -lintl -lm -lX11 -lXext -L/usr/X11R6/lib -lglib -lgmodule -L/usr/local/lib /usr/local/lib/libgtk.la -lICE -lSM -lz -lpng /usr/local/lib/libungif.la /usr/local/lib/libjpeg.la -ltiff -lm -lz -lpng /usr/local/lib/libungif.la -lz /usr/local/lib/libjpeg.la -ltiff -L/usr/local/lib -L/usr/X11R6/lib /usr/local/lib/libgdk_imlib.la -lm -L/usr/local/lib /usr/local/lib/libart_lgpl.la -lm -lz -lm -lX11 -lXext -lintl -lglib -lgmodule -lgdk -lgtk -lICE -lSM -lm -lX11 -lXext -lintl -lglib -lgmodule -lgdk -lgtk -L/usr/X11R6/lib -lm -lz -lpng -lungif -lz -ljpeg -ltiff -ljpeg -lgdk_imlib -lglib -lm -laudiofile -lm -laudiofile -lesd -L/usr/local/lib /usr/local/lib/libgnomeui.la -L/usr/X11R6/lib -L/usr/local/lib"
	specialdeplibs="-lgnomeui -lart_lgpl -lgdk_imlib -ltiff -ljpeg -lungif -lpng -lz -lSM -lICE -lgtk -lgdk -lgmodule -lintl -lXext -lX11 -lgnome -lgnomesupport -lesd -laudiofile -lm -lglib"
	for deplib in $deplibs; do
		case $deplib in
		-L*)
			new_libs="$deplib $new_libs"
			;;
		*)
			case " $specialdeplibs " in
			*" $deplib "*)
				new_libs="$deplib $new_libs";;
			esac
			;;
		esac
	done
---
name: oksh-seterror-1
description:
	The -e flag should be ignored when executing a compound list
	followed by an if statement.
stdin:
	if true; then false && false; fi
	true
arguments: !-e!
expected-exit: e == 0
---
name: oksh-seterror-2
description:
	The -e flag should be ignored when executing a compound list
	followed by an if statement.
stdin:
	if true; then if true; then false && false; fi; fi
	true
arguments: !-e!
expected-exit: e == 0
---
name: oksh-seterror-3
description:
	The -e flag should be ignored when executing a compound list
	followed by an elif statement.
stdin:
	if true; then :; elif true; then false && false; fi
arguments: !-e!
expected-exit: e == 0
---
name: oksh-seterror-4
description:
	The -e flag should be ignored when executing a pipeline
	beginning with '!'
stdin:
	for i in 1 2 3
	do
		false && false
		true || false
	done
arguments: !-e!
expected-exit: e == 0
---
name: oksh-seterror-5
description:
	The -e flag should be ignored when executing a pipeline
	beginning with '!'
stdin:
	! true | false
	true
arguments: !-e!
expected-exit: e == 0
---
name: oksh-seterror-6
description:
	When trapping ERR and EXIT, both traps should run in -e mode
	when an error occurs.
stdin:
	trap 'echo EXIT' EXIT
	trap 'echo ERR' ERR
	set -e
	false
	echo DONE
	exit 0
arguments: !-e!
expected-exit: e != 0
expected-stdout:
	ERR
	EXIT
---
name: oksh-seterror-7
description:
	The -e flag within a command substitution should be honored
stdin:
	echo $( set -e; false; echo foo )
arguments: !-e!
expected-stdout:
	
---
name: oksh-input-comsub
description:
	A command substitution using input redirection should exit with
	failure if the input file does not exist.
stdin:
	var=$(< non-existent)
expected-exit: e != 0
expected-stderr-pattern: /non-existent/
---
name: oksh-empty-for-list
description:
	A for list which expands to zero items should not execute the body.
stdin:
	set foo bar baz ; for out in ; do echo $out ; done
---
name: oksh-varfunction-mod1
description:
	(Inspired by PR 2450 on OpenBSD.) Calling
		FOO=bar f
	where f is a ksh style function, should not set FOO in the current
	env. If f is a Bourne style function, (new) also not. Furthermore,
	the function should receive a correct value of FOO. However, differing
	from oksh, setting FOO in the function itself must change the value in
	setting FOO in the function itself should not change the value in
	global environment.
stdin:
	print '#!'"$__progname"'\nunset RANDOM\nexport | while IFS= read -r' \
	    'RANDOM; do eval '\''print -r -- "$RANDOM=$'\''"$RANDOM"'\'\"\'\; \
	    done >env; chmod +x env; PATH=.$PATHSEP$PATH
	function k {
		if [ x$FOO != xbar ]; then
			echo 1
			return 1
		fi
		x=$(env | grep FOO)
		if [ "x$x" != "xFOO=bar" ]; then
			echo 2
			return 1;
		fi
		FOO=foo
		return 0
	}
	b () {
		if [ x$FOO != xbar ]; then
			echo 3
			return 1
		fi
		x=$(env | grep FOO)
		if [ "x$x" != "xFOO=bar" ]; then
			echo 4
			return 1;
		fi
		FOO=foo
		return 0
	}
	FOO=bar k
	if [ $? != 0 ]; then
		exit 1
	fi
	if [ x$FOO != x ]; then
		exit 1
	fi
	FOO=bar b
	if [ $? != 0 ]; then
		exit 1
	fi
	if [ x$FOO != x ]; then
		exit 1
	fi
	FOO=barbar
	FOO=bar k
	if [ $? != 0 ]; then
		exit 1
	fi
	if [ x$FOO != xbarbar ]; then
		exit 1
	fi
	FOO=bar b
	if [ $? != 0 ]; then
		exit 1
	fi
	if [ x$FOO != xbarbar ]; then
		exit 1
	fi
---
name: fd-cloexec-1
description:
	Verify that file descriptors > 2 are private for Korn shells
	AT&T ksh93 does this still, which means we must keep it as well
	XXX fails on some old Perl installations
need-pass: no
stdin:
	cat >cld <<-EOF
		#!$__perlname
		open(my \$fh, ">&", 9) or die "E: open \$!";
		syswrite(\$fh, "Fowl\\n", 5) or die "E: write \$!";
	EOF
	chmod +x cld
	exec 9>&1
	./cld
expected-exit: e != 0
expected-stderr-pattern:
	/E: open /
---
name: fd-cloexec-2
description:
	Verify that file descriptors > 2 are not private for POSIX shells
	See Debian Bug #154540, Closes: #499139
	XXX fails on some old Perl installations
need-pass: no
stdin:
	cat >cld <<-EOF
		#!$__perlname
		open(my \$fh, ">&", 9) or die "E: open \$!";
		syswrite(\$fh, "Fowl\\n", 5) or die "E: write \$!";
	EOF
	chmod +x cld
	test -n "$POSH_VERSION" || set -o posix
	exec 9>&1
	./cld
expected-stdout:
	Fowl
---
name: fd-cloexec-3
description:
	Another check for close-on-exec
stdin:
	print '#!'"$__progname" >ts
	cat >>ts <<'EOF'
	s=ERR
	read -rN-1 -u$1 s 2>/dev/null; e=$?
	print -r -- "($1, $((!e)), $s)"
	EOF
	chmod +x ts
	print foo >tx
	runtest() {
		s=$1; shift
		print -r -- $("$__progname" "$@" -c "$s") "$@" .
	}
	runtest 'exec 3<tx; ./ts 3 3<&3; ./ts 3'
	runtest 'exec 3<tx; ./ts 3 3<&3; ./ts 3' -o posix
	runtest 'exec 3<tx; ./ts 3 3<&3; ./ts 3' -o sh
	runtest 'exec 3<tx; ./ts 4 4<&3; ./ts 4 4<&3'
	runtest 'exec 3<tx; ./ts 3 3<&3; ./ts 3 3<&3'
expected-stdout:
	(3, 1, foo) (3, 0, ERR) .
	(3, 1, foo) (3, 1, ) -o posix .
	(3, 1, foo) (3, 1, ) -o sh .
	(4, 1, foo) (4, 1, ) .
	(3, 1, foo) (3, 1, ) .
---
name: comsub-1a
description:
	COMSUB are now parsed recursively, so this works
	see also regression-6: matching parenthesƒìs bug
	Fails on: pdksh bash2 bash3 zsh
	Passes on: bash4 ksh93 mksh(20110313+)
stdin:
	echo 1 $(case 1 in (1) echo yes;; (2) echo no;; esac) .
	echo 2 $(case 1 in 1) echo yes;; 2) echo no;; esac) .
	TEST=1234; echo 3 ${TEST: $(case 1 in (1) echo 1;; (*) echo 2;; esac)} .
	TEST=5678; echo 4 ${TEST: $(case 1 in 1) echo 1;; *) echo 2;; esac)} .
	a=($(case 1 in (1) echo 1;; (*) echo 2;; esac)); echo 5 ${a[0]} .
	a=($(case 1 in 1) echo 1;; *) echo 2;; esac)); echo 6 ${a[0]} .
expected-stdout:
	1 yes .
	2 yes .
	3 234 .
	4 678 .
	5 1 .
	6 1 .
---
name: comsub-1b
description:
	COMSUB are now parsed recursively, so this works
	Fails on: pdksh bash2 bash3 bash4 zsh
	Passes on: ksh93 mksh(20110313+)
stdin:
	echo 1 $(($(case 1 in (1) echo 1;; (*) echo 2;; esac)+10)) .
	echo 2 $(($(case 1 in 1) echo 1;; *) echo 2;; esac)+20)) .
	(( a = $(case 1 in (1) echo 1;; (*) echo 2;; esac) )); echo 3 $a .
	(( a = $(case 1 in 1) echo 1;; *) echo 2;; esac) )); echo 4 $a .
	a=($(($(case 1 in (1) echo 1;; (*) echo 2;; esac)+10))); echo 5 ${a[0]} .
	a=($(($(case 1 in 1) echo 1;; *) echo 2;; esac)+20))); echo 6 ${a[0]} .
expected-stdout:
	1 11 .
	2 21 .
	3 1 .
	4 1 .
	5 11 .
	6 21 .
---
name: comsub-2
description:
	RedHat BZ#496791 ‚Äì another case of missing recursion
	in parsing COMSUB expressions
	Fails on: pdksh bash2 bash3¬π bash4¬π zsh
	Passes on: ksh93 mksh(20110305+)
	‚ë† bash[34] seem to choke on comment ending with backslash-newline
stdin:
	# a comment with " ' \
	x=$(
	echo yes
	# a comment with " ' \
	)
	echo $x
expected-stdout:
	yes
---
name: comsub-3
description:
	Extended test for COMSUB explaining why a recursive parser
	is a must (a non-recursive parser cannot pass all three of
	these test cases, especially the ‚Äò#‚Äô is difficult)
stdin:
	print '#!'"$__progname"'\necho 1234' >id; chmod +x id; PATH=.$PATHSEP$PATH
	echo $(typeset -i10 x=16#20; echo $x)
	echo $(typeset -Uui16 x=16#$(id -u)
	) .
	echo $(c=1; d=1
	typeset -Uui16 a=36#foo; c=2
	typeset -Uui16 b=36 #foo; d=2
	echo $a $b $c $d)
expected-stdout:
	32
	.
	16#4F68 16#24 2 1
---
name: comsub-4
description:
	Check the tree dump functions for !MKSH_SMALL functionality
category: !smksh
stdin:
	x() { case $1 in u) echo x ;;& *) echo $1 ;; esac; }
	typeset -f x
expected-stdout:
	x() {
		case $1 in
		(u)
			\echo x 
			;|
		(*)
			\echo $1 
			;;
		esac 
	} 
---
name: comsub-5
description:
	Check COMSUB works with aliases (does not expand them twice)
	and reentrancy safety
stdin:
	print '#!'"$__progname"'\nfor x in "$@"; do print -r -- "$x"; done' >pfn
	chmod +x pfn
	alias echo='echo a'
	foo() {
		echo moo
		./pfn "$(echo foo)"
	}
	./pfn "$(echo b)"
	typeset -f foo >x
	cat x
	foo
	. ./x
	typeset -f foo
	foo
expected-stdout:
	a b
	foo() {
		\echo a moo 
		./pfn "$(\echo a foo )" 
	} 
	a moo
	a foo
	foo() {
		\echo a moo 
		./pfn "$(\echo a foo )" 
	} 
	a moo
	a foo
---
name: comsub-torture
description:
	Check the tree dump functions work correctly
stdin:
	if [[ -z $__progname ]]; then echo >&2 call me with __progname; exit 1; fi
	while IFS= read -r line; do
		if [[ $line = '#1' ]]; then
			lastf=0
			continue
		elif [[ $line = EOFN* ]]; then
			fbody=$fbody$'\n'$line
			continue
		elif [[ $line != '#'* ]]; then
			fbody=$fbody$'\n\t'$line
			continue
		fi
		if (( lastf )); then
			x="inline_${nextf}() {"$fbody$'\n}\n'
			print -nr -- "$x"
			print -r -- "${x}typeset -f inline_$nextf" | "$__progname"
			x="function comsub_$nextf { x=\$("$fbody$'\n); }\n'
			print -nr -- "$x"
			print -r -- "${x}typeset -f comsub_$nextf" | "$__progname"
			x="function reread_$nextf { x=\$(("$fbody$'\n)|tr u x); }\n'
			print -nr -- "$x"
			print -r -- "${x}typeset -f reread_$nextf" | "$__progname"
		fi
		lastf=1
		fbody=
		nextf=${line#?}
	done <<'EOD'
	#1
	#TCOM
	vara=1  varb='2  3'  cmd  arg1  $arg2  "$arg3  4"
	#TPAREN_TPIPE_TLIST
	(echo $foo  |  tr -dc 0-9; echo)
	#TAND_TOR
	cmd  &&  echo ja  ||  echo nein
	#TSELECT
	select  file  in  *;  do  echo  "<$file>" ;  break ;  done
	#TFOR_TTIME
	time  for  i  in  {1,2,3}  ;  do  echo  $i ;  done
	#TCASE
	case  $foo  in  1)  echo eins;& 2) echo zwei  ;| *) echo kann net bis drei z√§hlen;;  esac
	#TIF_TBANG_TDBRACKET_TELIF
	if  !  [[  1  =  1  ]]  ;  then  echo eins;  elif [[ 1 = 2 ]]; then echo zwei  ;else echo drei; fi
	#TWHILE
	i=1; while (( i < 10 )); do echo $i; let ++i; done
	#TUNTIL
	i=10; until  (( !--i )) ; do echo $i; done
	#TCOPROC
	cat  *  |&  ls
	#TFUNCT_TBRACE_TASYNC
	function  korn  {  echo eins; echo zwei ;  }
	bourne  ()  {  logger *  &  }
	#IOREAD_IOCAT
	tr  x  u  0<foo  >>bar
	#IOWRITE_IOCLOB_IOHERE_noIOSKIP
	cat  >|bar  <<'EOFN'
	foo
	EOFN
	#IOWRITE_noIOCLOB_IOHERE_IOSKIP
	cat  1>bar  <<-EOFI
	foo
	EOFI
	#IORDWR_IODUP
	sh  1<>/dev/console  0<&1  2>&1
	#COMSUB_EXPRSUB_FUNSUB_VALSUB
	echo $(true) $((1+ 2)) ${  :;} ${| REPLY=x;}
	#QCHAR_OQUOTE_CQUOTE
	echo fo\ob\"a\`r\'b\$az
	echo "fo\ob\"a\`r\'b\$az"
	echo 'fo\ob\"a\`r'\''b\$az'
	#OSUBST_CSUBST_OPAT_SPAT_CPAT
	[[ ${foo#bl\(u\)b} = @(bar|baz) ]]
	#heredoc_closed
	x=$(cat <<EOFN
	note there must be no space between EOFN and )
	EOFN); echo $x
	#heredoc_space
	x=$(cat <<EOFN\ 
	note the space between EOFN and ) is actually part of the here document marker
	EOFN ); echo $x
	#patch_motd
	x=$(sysctl -n kern.version | sed 1q)
	[[ -s /etc/motd && "$([[ "$(head -1 /etc/motd)" != $x ]] && \
	    ed -s /etc/motd 2>&1 <<-EOF
		1,/^\$/d
		0a
			$x
	
		.
		wq
	EOF)" = @(?) ]] && rm -f /etc/motd
	if [[ ! -s /etc/motd ]]; then
		install -c -o root -g wheel -m 664 /dev/null /etc/motd
		print -- "$x\n" >/etc/motd
	fi
	#wdarrassign
	case x in
	x) a+=b; c+=(d e)
	esac
	#0
	EOD
expected-stdout:
	inline_TCOM() {
		vara=1  varb='2  3'  cmd  arg1  $arg2  "$arg3  4"
	}
	inline_TCOM() {
		vara=1 varb="2  3" \cmd arg1 $arg2 "$arg3  4" 
	} 
	function comsub_TCOM { x=$(
		vara=1  varb='2  3'  cmd  arg1  $arg2  "$arg3  4"
	); }
	function comsub_TCOM {
		x=$(vara=1 varb="2  3" \cmd arg1 $arg2 "$arg3  4" ) 
	} 
	function reread_TCOM { x=$((
		vara=1  varb='2  3'  cmd  arg1  $arg2  "$arg3  4"
	)|tr u x); }
	function reread_TCOM {
		x=$( ( vara=1 varb="2  3" \cmd arg1 $arg2 "$arg3  4" ) | \tr u x ) 
	} 
	inline_TPAREN_TPIPE_TLIST() {
		(echo $foo  |  tr -dc 0-9; echo)
	}
	inline_TPAREN_TPIPE_TLIST() {
		( \echo $foo | \tr -dc 0-9 
		  \echo ) 
	} 
	function comsub_TPAREN_TPIPE_TLIST { x=$(
		(echo $foo  |  tr -dc 0-9; echo)
	); }
	function comsub_TPAREN_TPIPE_TLIST {
		x=$( ( \echo $foo | \tr -dc 0-9 ; \echo ) ) 
	} 
	function reread_TPAREN_TPIPE_TLIST { x=$((
		(echo $foo  |  tr -dc 0-9; echo)
	)|tr u x); }
	function reread_TPAREN_TPIPE_TLIST {
		x=$( ( ( \echo $foo | \tr -dc 0-9 ; \echo ) ) | \tr u x ) 
	} 
	inline_TAND_TOR() {
		cmd  &&  echo ja  ||  echo nein
	}
	inline_TAND_TOR() {
		\cmd && \echo ja || \echo nein 
	} 
	function comsub_TAND_TOR { x=$(
		cmd  &&  echo ja  ||  echo nein
	); }
	function comsub_TAND_TOR {
		x=$(\cmd && \echo ja || \echo nein ) 
	} 
	function reread_TAND_TOR { x=$((
		cmd  &&  echo ja  ||  echo nein
	)|tr u x); }
	function reread_TAND_TOR {
		x=$( ( \cmd && \echo ja || \echo nein ) | \tr u x ) 
	} 
	inline_TSELECT() {
		select  file  in  *;  do  echo  "<$file>" ;  break ;  done
	}
	inline_TSELECT() {
		select file in * 
		do
			\echo "<$file>" 
			\break 
		done 
	} 
	function comsub_TSELECT { x=$(
		select  file  in  *;  do  echo  "<$file>" ;  break ;  done
	); }
	function comsub_TSELECT {
		x=$(select file in * ; do \echo "<$file>" ; \break ; done ) 
	} 
	function reread_TSELECT { x=$((
		select  file  in  *;  do  echo  "<$file>" ;  break ;  done
	)|tr u x); }
	function reread_TSELECT {
		x=$( ( select file in * ; do \echo "<$file>" ; \break ; done ) | \tr u x ) 
	} 
	inline_TFOR_TTIME() {
		time  for  i  in  {1,2,3}  ;  do  echo  $i ;  done
	}
	inline_TFOR_TTIME() {
		time for i in {1,2,3} 
		do
			\echo $i 
		done 
	} 
	function comsub_TFOR_TTIME { x=$(
		time  for  i  in  {1,2,3}  ;  do  echo  $i ;  done
	); }
	function comsub_TFOR_TTIME {
		x=$(time for i in {1,2,3} ; do \echo $i ; done ) 
	} 
	function reread_TFOR_TTIME { x=$((
		time  for  i  in  {1,2,3}  ;  do  echo  $i ;  done
	)|tr u x); }
	function reread_TFOR_TTIME {
		x=$( ( time for i in {1,2,3} ; do \echo $i ; done ) | \tr u x ) 
	} 
	inline_TCASE() {
		case  $foo  in  1)  echo eins;& 2) echo zwei  ;| *) echo kann net bis drei z√§hlen;;  esac
	}
	inline_TCASE() {
		case $foo in
		(1)
			\echo eins 
			;&
		(2)
			\echo zwei 
			;|
		(*)
			\echo kann net bis drei z√§hlen 
			;;
		esac 
	} 
	function comsub_TCASE { x=$(
		case  $foo  in  1)  echo eins;& 2) echo zwei  ;| *) echo kann net bis drei z√§hlen;;  esac
	); }
	function comsub_TCASE {
		x=$(case $foo in (1) \echo eins  ;& (2) \echo zwei  ;| (*) \echo kann net bis drei z√§hlen  ;; esac ) 
	} 
	function reread_TCASE { x=$((
		case  $foo  in  1)  echo eins;& 2) echo zwei  ;| *) echo kann net bis drei z√§hlen;;  esac
	)|tr u x); }
	function reread_TCASE {
		x=$( ( case $foo in (1) \echo eins  ;& (2) \echo zwei  ;| (*) \echo kann net bis drei z√§hlen  ;; esac ) | \tr u x ) 
	} 
	inline_TIF_TBANG_TDBRACKET_TELIF() {
		if  !  [[  1  =  1  ]]  ;  then  echo eins;  elif [[ 1 = 2 ]]; then echo zwei  ;else echo drei; fi
	}
	inline_TIF_TBANG_TDBRACKET_TELIF() {
		if ! [[ 1 = 1 ]] 
		then
			\echo eins 
		elif [[ 1 = 2 ]] 
		then
			\echo zwei 
		else
			\echo drei 
		fi 
	} 
	function comsub_TIF_TBANG_TDBRACKET_TELIF { x=$(
		if  !  [[  1  =  1  ]]  ;  then  echo eins;  elif [[ 1 = 2 ]]; then echo zwei  ;else echo drei; fi
	); }
	function comsub_TIF_TBANG_TDBRACKET_TELIF {
		x=$(if ! [[ 1 = 1 ]] ; then \echo eins ; elif [[ 1 = 2 ]] ; then \echo zwei ; else \echo drei ; fi ) 
	} 
	function reread_TIF_TBANG_TDBRACKET_TELIF { x=$((
		if  !  [[  1  =  1  ]]  ;  then  echo eins;  elif [[ 1 = 2 ]]; then echo zwei  ;else echo drei; fi
	)|tr u x); }
	function reread_TIF_TBANG_TDBRACKET_TELIF {
		x=$( ( if ! [[ 1 = 1 ]] ; then \echo eins ; elif [[ 1 = 2 ]] ; then \echo zwei ; else \echo drei ; fi ) | \tr u x ) 
	} 
	inline_TWHILE() {
		i=1; while (( i < 10 )); do echo $i; let ++i; done
	}
	inline_TWHILE() {
		i=1 
		while {
			      \\builtin let " i < 10 " 
		      } 
		do
			\echo $i 
			\let ++i 
		done 
	} 
	function comsub_TWHILE { x=$(
		i=1; while (( i < 10 )); do echo $i; let ++i; done
	); }
	function comsub_TWHILE {
		x=$(i=1 ; while { \\builtin let " i < 10 " ; } ; do \echo $i ; \let ++i ; done ) 
	} 
	function reread_TWHILE { x=$((
		i=1; while (( i < 10 )); do echo $i; let ++i; done
	)|tr u x); }
	function reread_TWHILE {
		x=$( ( i=1 ; while { \\builtin let " i < 10 " ; } ; do \echo $i ; \let ++i ; done ) | \tr u x ) 
	} 
	inline_TUNTIL() {
		i=10; until  (( !--i )) ; do echo $i; done
	}
	inline_TUNTIL() {
		i=10 
		until {
			      \\builtin let " !--i " 
		      } 
		do
			\echo $i 
		done 
	} 
	function comsub_TUNTIL { x=$(
		i=10; until  (( !--i )) ; do echo $i; done
	); }
	function comsub_TUNTIL {
		x=$(i=10 ; until { \\builtin let " !--i " ; } ; do \echo $i ; done ) 
	} 
	function reread_TUNTIL { x=$((
		i=10; until  (( !--i )) ; do echo $i; done
	)|tr u x); }
	function reread_TUNTIL {
		x=$( ( i=10 ; until { \\builtin let " !--i " ; } ; do \echo $i ; done ) | \tr u x ) 
	} 
	inline_TCOPROC() {
		cat  *  |&  ls
	}
	inline_TCOPROC() {
		\cat * |& 
		\ls 
	} 
	function comsub_TCOPROC { x=$(
		cat  *  |&  ls
	); }
	function comsub_TCOPROC {
		x=$(\cat * |&  \ls ) 
	} 
	function reread_TCOPROC { x=$((
		cat  *  |&  ls
	)|tr u x); }
	function reread_TCOPROC {
		x=$( ( \cat * |&  \ls ) | \tr u x ) 
	} 
	inline_TFUNCT_TBRACE_TASYNC() {
		function  korn  {  echo eins; echo zwei ;  }
		bourne  ()  {  logger *  &  }
	}
	inline_TFUNCT_TBRACE_TASYNC() {
		function korn {
			\echo eins 
			\echo zwei 
		} 
		bourne() {
			\logger * & 
		} 
	} 
	function comsub_TFUNCT_TBRACE_TASYNC { x=$(
		function  korn  {  echo eins; echo zwei ;  }
		bourne  ()  {  logger *  &  }
	); }
	function comsub_TFUNCT_TBRACE_TASYNC {
		x=$(function korn { \echo eins ; \echo zwei ; } ; bourne() { \logger * &  } ) 
	} 
	function reread_TFUNCT_TBRACE_TASYNC { x=$((
		function  korn  {  echo eins; echo zwei ;  }
		bourne  ()  {  logger *  &  }
	)|tr u x); }
	function reread_TFUNCT_TBRACE_TASYNC {
		x=$( ( function korn { \echo eins ; \echo zwei ; } ; bourne() { \logger * &  } ) | \tr u x ) 
	} 
	inline_IOREAD_IOCAT() {
		tr  x  u  0<foo  >>bar
	}
	inline_IOREAD_IOCAT() {
		\tr x u <foo >>bar 
	} 
	function comsub_IOREAD_IOCAT { x=$(
		tr  x  u  0<foo  >>bar
	); }
	function comsub_IOREAD_IOCAT {
		x=$(\tr x u <foo >>bar ) 
	} 
	function reread_IOREAD_IOCAT { x=$((
		tr  x  u  0<foo  >>bar
	)|tr u x); }
	function reread_IOREAD_IOCAT {
		x=$( ( \tr x u <foo >>bar ) | \tr u x ) 
	} 
	inline_IOWRITE_IOCLOB_IOHERE_noIOSKIP() {
		cat  >|bar  <<'EOFN'
		foo
	EOFN
	}
	inline_IOWRITE_IOCLOB_IOHERE_noIOSKIP() {
		\cat >|bar <<"EOFN" 
		foo
	EOFN
	
	} 
	function comsub_IOWRITE_IOCLOB_IOHERE_noIOSKIP { x=$(
		cat  >|bar  <<'EOFN'
		foo
	EOFN
	); }
	function comsub_IOWRITE_IOCLOB_IOHERE_noIOSKIP {
		x=$(\cat >|bar <<"EOFN" 
		foo
	EOFN
	) 
	} 
	function reread_IOWRITE_IOCLOB_IOHERE_noIOSKIP { x=$((
		cat  >|bar  <<'EOFN'
		foo
	EOFN
	)|tr u x); }
	function reread_IOWRITE_IOCLOB_IOHERE_noIOSKIP {
		x=$( ( \cat >|bar <<"EOFN" 
		foo
	EOFN
	) | \tr u x ) 
	} 
	inline_IOWRITE_noIOCLOB_IOHERE_IOSKIP() {
		cat  1>bar  <<-EOFI
		foo
		EOFI
	}
	inline_IOWRITE_noIOCLOB_IOHERE_IOSKIP() {
		\cat >bar <<-EOFI 
	foo
	EOFI
	
	} 
	function comsub_IOWRITE_noIOCLOB_IOHERE_IOSKIP { x=$(
		cat  1>bar  <<-EOFI
		foo
		EOFI
	); }
	function comsub_IOWRITE_noIOCLOB_IOHERE_IOSKIP {
		x=$(\cat >bar <<-EOFI 
	foo
	EOFI
	) 
	} 
	function reread_IOWRITE_noIOCLOB_IOHERE_IOSKIP { x=$((
		cat  1>bar  <<-EOFI
		foo
		EOFI
	)|tr u x); }
	function reread_IOWRITE_noIOCLOB_IOHERE_IOSKIP {
		x=$( ( \cat >bar <<-EOFI 
	foo
	EOFI
	) | \tr u x ) 
	} 
	inline_IORDWR_IODUP() {
		sh  1<>/dev/console  0<&1  2>&1
	}
	inline_IORDWR_IODUP() {
		\sh 1<>/dev/console <&1 2>&1 
	} 
	function comsub_IORDWR_IODUP { x=$(
		sh  1<>/dev/console  0<&1  2>&1
	); }
	function comsub_IORDWR_IODUP {
		x=$(\sh 1<>/dev/console <&1 2>&1 ) 
	} 
	function reread_IORDWR_IODUP { x=$((
		sh  1<>/dev/console  0<&1  2>&1
	)|tr u x); }
	function reread_IORDWR_IODUP {
		x=$( ( \sh 1<>/dev/console <&1 2>&1 ) | \tr u x ) 
	} 
	inline_COMSUB_EXPRSUB_FUNSUB_VALSUB() {
		echo $(true) $((1+ 2)) ${  :;} ${| REPLY=x;}
	}
	inline_COMSUB_EXPRSUB_FUNSUB_VALSUB() {
		\echo $(\true ) $((1+ 2)) ${ \: ;} ${|REPLY=x ;} 
	} 
	function comsub_COMSUB_EXPRSUB_FUNSUB_VALSUB { x=$(
		echo $(true) $((1+ 2)) ${  :;} ${| REPLY=x;}
	); }
	function comsub_COMSUB_EXPRSUB_FUNSUB_VALSUB {
		x=$(\echo $(\true ) $((1+ 2)) ${ \: ;} ${|REPLY=x ;} ) 
	} 
	function reread_COMSUB_EXPRSUB_FUNSUB_VALSUB { x=$((
		echo $(true) $((1+ 2)) ${  :;} ${| REPLY=x;}
	)|tr u x); }
	function reread_COMSUB_EXPRSUB_FUNSUB_VALSUB {
		x=$( ( \echo $(\true ) $((1+ 2)) ${ \: ;} ${|REPLY=x ;} ) | \tr u x ) 
	} 
	inline_QCHAR_OQUOTE_CQUOTE() {
		echo fo\ob\"a\`r\'b\$az
		echo "fo\ob\"a\`r\'b\$az"
		echo 'fo\ob\"a\`r'\''b\$az'
	}
	inline_QCHAR_OQUOTE_CQUOTE() {
		\echo fo\ob\"a\`r\'b\$az 
		\echo "fo\ob\"a\`r\'b\$az" 
		\echo "fo\\ob\\\"a\\\`r"\'"b\\\$az" 
	} 
	function comsub_QCHAR_OQUOTE_CQUOTE { x=$(
		echo fo\ob\"a\`r\'b\$az
		echo "fo\ob\"a\`r\'b\$az"
		echo 'fo\ob\"a\`r'\''b\$az'
	); }
	function comsub_QCHAR_OQUOTE_CQUOTE {
		x=$(\echo fo\ob\"a\`r\'b\$az ; \echo "fo\ob\"a\`r\'b\$az" ; \echo "fo\\ob\\\"a\\\`r"\'"b\\\$az" ) 
	} 
	function reread_QCHAR_OQUOTE_CQUOTE { x=$((
		echo fo\ob\"a\`r\'b\$az
		echo "fo\ob\"a\`r\'b\$az"
		echo 'fo\ob\"a\`r'\''b\$az'
	)|tr u x); }
	function reread_QCHAR_OQUOTE_CQUOTE {
		x=$( ( \echo fo\ob\"a\`r\'b\$az ; \echo "fo\ob\"a\`r\'b\$az" ; \echo "fo\\ob\\\"a\\\`r"\'"b\\\$az" ) | \tr u x ) 
	} 
	inline_OSUBST_CSUBST_OPAT_SPAT_CPAT() {
		[[ ${foo#bl\(u\)b} = @(bar|baz) ]]
	}
	inline_OSUBST_CSUBST_OPAT_SPAT_CPAT() {
		[[ ${foo#bl\(u\)b} = @(bar|baz) ]] 
	} 
	function comsub_OSUBST_CSUBST_OPAT_SPAT_CPAT { x=$(
		[[ ${foo#bl\(u\)b} = @(bar|baz) ]]
	); }
	function comsub_OSUBST_CSUBST_OPAT_SPAT_CPAT {
		x=$([[ ${foo#bl\(u\)b} = @(bar|baz) ]] ) 
	} 
	function reread_OSUBST_CSUBST_OPAT_SPAT_CPAT { x=$((
		[[ ${foo#bl\(u\)b} = @(bar|baz) ]]
	)|tr u x); }
	function reread_OSUBST_CSUBST_OPAT_SPAT_CPAT {
		x=$( ( [[ ${foo#bl\(u\)b} = @(bar|baz) ]] ) | \tr u x ) 
	} 
	inline_heredoc_closed() {
		x=$(cat <<EOFN
		note there must be no space between EOFN and )
	EOFN); echo $x
	}
	inline_heredoc_closed() {
		x=$(\cat <<EOFN 
		note there must be no space between EOFN and )
	EOFN
	) 
		\echo $x 
	} 
	function comsub_heredoc_closed { x=$(
		x=$(cat <<EOFN
		note there must be no space between EOFN and )
	EOFN); echo $x
	); }
	function comsub_heredoc_closed {
		x=$(x=$(\cat <<EOFN 
		note there must be no space between EOFN and )
	EOFN
	) ; \echo $x ) 
	} 
	function reread_heredoc_closed { x=$((
		x=$(cat <<EOFN
		note there must be no space between EOFN and )
	EOFN); echo $x
	)|tr u x); }
	function reread_heredoc_closed {
		x=$( ( x=$(\cat <<EOFN 
		note there must be no space between EOFN and )
	EOFN
	) ; \echo $x ) | \tr u x ) 
	} 
	inline_heredoc_space() {
		x=$(cat <<EOFN\ 
		note the space between EOFN and ) is actually part of the here document marker
	EOFN ); echo $x
	}
	inline_heredoc_space() {
		x=$(\cat <<EOFN\  
		note the space between EOFN and ) is actually part of the here document marker
	EOFN 
	) 
		\echo $x 
	} 
	function comsub_heredoc_space { x=$(
		x=$(cat <<EOFN\ 
		note the space between EOFN and ) is actually part of the here document marker
	EOFN ); echo $x
	); }
	function comsub_heredoc_space {
		x=$(x=$(\cat <<EOFN\  
		note the space between EOFN and ) is actually part of the here document marker
	EOFN 
	) ; \echo $x ) 
	} 
	function reread_heredoc_space { x=$((
		x=$(cat <<EOFN\ 
		note the space between EOFN and ) is actually part of the here document marker
	EOFN ); echo $x
	)|tr u x); }
	function reread_heredoc_space {
		x=$( ( x=$(\cat <<EOFN\  
		note the space between EOFN and ) is actually part of the here document marker
	EOFN 
	) ; \echo $x ) | \tr u x ) 
	} 
	inline_patch_motd() {
		x=$(sysctl -n kern.version | sed 1q)
		[[ -s /etc/motd && "$([[ "$(head -1 /etc/motd)" != $x ]] && \
		    ed -s /etc/motd 2>&1 <<-EOF
			1,/^\$/d
			0a
				$x
		
			.
			wq
		EOF)" = @(?) ]] && rm -f /etc/motd
		if [[ ! -s /etc/motd ]]; then
			install -c -o root -g wheel -m 664 /dev/null /etc/motd
			print -- "$x\n" >/etc/motd
		fi
	}
	inline_patch_motd() {
		x=$(\sysctl -n kern.version | \sed 1q ) 
		[[ -s /etc/motd && "$([[ "$(\head -1 /etc/motd )" != $x ]] && \ed -s /etc/motd 2>&1 <<-EOF 
	1,/^\$/d
	0a
	$x
	
	.
	wq
	EOF
	)" = @(?) ]] && \rm -f /etc/motd 
		if [[ ! -s /etc/motd ]] 
		then
			\install -c -o root -g wheel -m 664 /dev/null /etc/motd 
			\print -- "$x\n" >/etc/motd 
		fi 
	} 
	function comsub_patch_motd { x=$(
		x=$(sysctl -n kern.version | sed 1q)
		[[ -s /etc/motd && "$([[ "$(head -1 /etc/motd)" != $x ]] && \
		    ed -s /etc/motd 2>&1 <<-EOF
			1,/^\$/d
			0a
				$x
		
			.
			wq
		EOF)" = @(?) ]] && rm -f /etc/motd
		if [[ ! -s /etc/motd ]]; then
			install -c -o root -g wheel -m 664 /dev/null /etc/motd
			print -- "$x\n" >/etc/motd
		fi
	); }
	function comsub_patch_motd {
		x=$(x=$(\sysctl -n kern.version | \sed 1q ) ; [[ -s /etc/motd && "$([[ "$(\head -1 /etc/motd )" != $x ]] && \ed -s /etc/motd 2>&1 <<-EOF 
	1,/^\$/d
	0a
	$x
	
	.
	wq
	EOF
	)" = @(?) ]] && \rm -f /etc/motd ; if [[ ! -s /etc/motd ]] ; then \install -c -o root -g wheel -m 664 /dev/null /etc/motd ; \print -- "$x\n" >/etc/motd ; fi ) 
	} 
	function reread_patch_motd { x=$((
		x=$(sysctl -n kern.version | sed 1q)
		[[ -s /etc/motd && "$([[ "$(head -1 /etc/motd)" != $x ]] && \
		    ed -s /etc/motd 2>&1 <<-EOF
			1,/^\$/d
			0a
				$x
		
			.
			wq
		EOF)" = @(?) ]] && rm -f /etc/motd
		if [[ ! -s /etc/motd ]]; then
			install -c -o root -g wheel -m 664 /dev/null /etc/motd
			print -- "$x\n" >/etc/motd
		fi
	)|tr u x); }
	function reread_patch_motd {
		x=$( ( x=$(\sysctl -n kern.version | \sed 1q ) ; [[ -s /etc/motd && "$([[ "$(\head -1 /etc/motd )" != $x ]] && \ed -s /etc/motd 2>&1 <<-EOF 
	1,/^\$/d
	0a
	$x
	
	.
	wq
	EOF
	)" = @(?) ]] && \rm -f /etc/motd ; if [[ ! -s /etc/motd ]] ; then \install -c -o root -g wheel -m 664 /dev/null /etc/motd ; \print -- "$x\n" >/etc/motd ; fi ) | \tr u x ) 
	} 
	inline_wdarrassign() {
		case x in
		x) a+=b; c+=(d e)
		esac
	}
	inline_wdarrassign() {
		case x in
		(x)
			a+=b 
			\\builtin set -A c+ -- d e 
			;;
		esac 
	} 
	function comsub_wdarrassign { x=$(
		case x in
		x) a+=b; c+=(d e)
		esac
	); }
	function comsub_wdarrassign {
		x=$(case x in (x) a+=b ; \\builtin set -A c+ -- d e  ;; esac ) 
	} 
	function reread_wdarrassign { x=$((
		case x in
		x) a+=b; c+=(d e)
		esac
	)|tr u x); }
	function reread_wdarrassign {
		x=$( ( case x in (x) a+=b ; \\builtin set -A c+ -- d e  ;; esac ) | \tr u x ) 
	} 
---
name: comsub-torture-io
description:
	Check the tree dump functions work correctly with I/O redirection
stdin:
	if [[ -z $__progname ]]; then echo >&2 call me with __progname; exit 1; fi
	while IFS= read -r line; do
		if [[ $line = '#1' ]]; then
			lastf=0
			continue
		elif [[ $line = EOFN* ]]; then
			fbody=$fbody$'\n'$line
			continue
		elif [[ $line != '#'* ]]; then
			fbody=$fbody$'\n\t'$line
			continue
		fi
		if (( lastf )); then
			x="inline_${nextf}() {"$fbody$'\n}\n'
			print -nr -- "$x"
			print -r -- "${x}typeset -f inline_$nextf" | "$__progname"
			x="function comsub_$nextf { x=\$("$fbody$'\n); }\n'
			print -nr -- "$x"
			print -r -- "${x}typeset -f comsub_$nextf" | "$__progname"
			x="function reread_$nextf { x=\$(("$fbody$'\n)|tr u x); }\n'
			print -nr -- "$x"
			print -r -- "${x}typeset -f reread_$nextf" | "$__progname"
		fi
		lastf=1
		fbody=
		nextf=${line#?}
	done <<'EOD'
	#1
	#TCOM
	vara=1  varb='2  3'  cmd  arg1  $arg2  "$arg3  4" >&3
	#TPAREN_TPIPE_TLIST
	(echo $foo  |  tr -dc 0-9 >&3; echo >&3) >&3
	#TAND_TOR
	cmd  >&3 &&  >&3 echo ja  ||  echo >&3 nein
	#TSELECT
	select  file  in  *;  do  echo  "<$file>" ;  break >&3 ;  done >&3
	#TFOR_TTIME
	for  i  in  {1,2,3}  ;  do  time  >&3 echo  $i ;  done >&3
	#TCASE
	case  $foo  in  1)  echo eins >&3;& 2) echo zwei >&3  ;| *) echo kann net bis drei z√§hlen >&3;;  esac >&3
	#TIF_TBANG_TDBRACKET_TELIF
	if  !  [[  1  =  1  ]]  >&3 ;  then  echo eins;  elif [[ 1 = 2 ]] >&3; then echo zwei  ;else echo drei; fi >&3
	#TWHILE
	i=1; while (( i < 10 )) >&3; do echo $i; let ++i; done >&3
	#TUNTIL
	i=10; until  (( !--i )) >&3 ; do echo $i; done >&3
	#TCOPROC
	cat  *  >&3 |&  >&3 ls
	#TFUNCT_TBRACE_TASYNC
	function  korn  {  echo eins; echo >&3 zwei ;  }
	bourne  ()  {  logger *  >&3 &  }
	#COMSUB_EXPRSUB
	echo $(true >&3) $((1+ 2))
	#0
	EOD
expected-stdout:
	inline_TCOM() {
		vara=1  varb='2  3'  cmd  arg1  $arg2  "$arg3  4" >&3
	}
	inline_TCOM() {
		vara=1 varb="2  3" \cmd arg1 $arg2 "$arg3  4" >&3 
	} 
	function comsub_TCOM { x=$(
		vara=1  varb='2  3'  cmd  arg1  $arg2  "$arg3  4" >&3
	); }
	function comsub_TCOM {
		x=$(vara=1 varb="2  3" \cmd arg1 $arg2 "$arg3  4" >&3 ) 
	} 
	function reread_TCOM { x=$((
		vara=1  varb='2  3'  cmd  arg1  $arg2  "$arg3  4" >&3
	)|tr u x); }
	function reread_TCOM {
		x=$( ( vara=1 varb="2  3" \cmd arg1 $arg2 "$arg3  4" >&3 ) | \tr u x ) 
	} 
	inline_TPAREN_TPIPE_TLIST() {
		(echo $foo  |  tr -dc 0-9 >&3; echo >&3) >&3
	}
	inline_TPAREN_TPIPE_TLIST() {
		( \echo $foo | \tr -dc 0-9 >&3 
		  \echo >&3 ) >&3 
	} 
	function comsub_TPAREN_TPIPE_TLIST { x=$(
		(echo $foo  |  tr -dc 0-9 >&3; echo >&3) >&3
	); }
	function comsub_TPAREN_TPIPE_TLIST {
		x=$( ( \echo $foo | \tr -dc 0-9 >&3 ; \echo >&3 ) >&3 ) 
	} 
	function reread_TPAREN_TPIPE_TLIST { x=$((
		(echo $foo  |  tr -dc 0-9 >&3; echo >&3) >&3
	)|tr u x); }
	function reread_TPAREN_TPIPE_TLIST {
		x=$( ( ( \echo $foo | \tr -dc 0-9 >&3 ; \echo >&3 ) >&3 ) | \tr u x ) 
	} 
	inline_TAND_TOR() {
		cmd  >&3 &&  >&3 echo ja  ||  echo >&3 nein
	}
	inline_TAND_TOR() {
		\cmd >&3 && \echo ja >&3 || \echo nein >&3 
	} 
	function comsub_TAND_TOR { x=$(
		cmd  >&3 &&  >&3 echo ja  ||  echo >&3 nein
	); }
	function comsub_TAND_TOR {
		x=$(\cmd >&3 && \echo ja >&3 || \echo nein >&3 ) 
	} 
	function reread_TAND_TOR { x=$((
		cmd  >&3 &&  >&3 echo ja  ||  echo >&3 nein
	)|tr u x); }
	function reread_TAND_TOR {
		x=$( ( \cmd >&3 && \echo ja >&3 || \echo nein >&3 ) | \tr u x ) 
	} 
	inline_TSELECT() {
		select  file  in  *;  do  echo  "<$file>" ;  break >&3 ;  done >&3
	}
	inline_TSELECT() {
		select file in * 
		do
			\echo "<$file>" 
			\break >&3 
		done >&3 
	} 
	function comsub_TSELECT { x=$(
		select  file  in  *;  do  echo  "<$file>" ;  break >&3 ;  done >&3
	); }
	function comsub_TSELECT {
		x=$(select file in * ; do \echo "<$file>" ; \break >&3 ; done >&3 ) 
	} 
	function reread_TSELECT { x=$((
		select  file  in  *;  do  echo  "<$file>" ;  break >&3 ;  done >&3
	)|tr u x); }
	function reread_TSELECT {
		x=$( ( select file in * ; do \echo "<$file>" ; \break >&3 ; done >&3 ) | \tr u x ) 
	} 
	inline_TFOR_TTIME() {
		for  i  in  {1,2,3}  ;  do  time  >&3 echo  $i ;  done >&3
	}
	inline_TFOR_TTIME() {
		for i in {1,2,3} 
		do
			time \echo $i >&3 
		done >&3 
	} 
	function comsub_TFOR_TTIME { x=$(
		for  i  in  {1,2,3}  ;  do  time  >&3 echo  $i ;  done >&3
	); }
	function comsub_TFOR_TTIME {
		x=$(for i in {1,2,3} ; do time \echo $i >&3 ; done >&3 ) 
	} 
	function reread_TFOR_TTIME { x=$((
		for  i  in  {1,2,3}  ;  do  time  >&3 echo  $i ;  done >&3
	)|tr u x); }
	function reread_TFOR_TTIME {
		x=$( ( for i in {1,2,3} ; do time \echo $i >&3 ; done >&3 ) | \tr u x ) 
	} 
	inline_TCASE() {
		case  $foo  in  1)  echo eins >&3;& 2) echo zwei >&3  ;| *) echo kann net bis drei z√§hlen >&3;;  esac >&3
	}
	inline_TCASE() {
		case $foo in
		(1)
			\echo eins >&3 
			;&
		(2)
			\echo zwei >&3 
			;|
		(*)
			\echo kann net bis drei z√§hlen >&3 
			;;
		esac >&3 
	} 
	function comsub_TCASE { x=$(
		case  $foo  in  1)  echo eins >&3;& 2) echo zwei >&3  ;| *) echo kann net bis drei z√§hlen >&3;;  esac >&3
	); }
	function comsub_TCASE {
		x=$(case $foo in (1) \echo eins >&3  ;& (2) \echo zwei >&3  ;| (*) \echo kann net bis drei z√§hlen >&3  ;; esac >&3 ) 
	} 
	function reread_TCASE { x=$((
		case  $foo  in  1)  echo eins >&3;& 2) echo zwei >&3  ;| *) echo kann net bis drei z√§hlen >&3;;  esac >&3
	)|tr u x); }
	function reread_TCASE {
		x=$( ( case $foo in (1) \echo eins >&3  ;& (2) \echo zwei >&3  ;| (*) \echo kann net bis drei z√§hlen >&3  ;; esac >&3 ) | \tr u x ) 
	} 
	inline_TIF_TBANG_TDBRACKET_TELIF() {
		if  !  [[  1  =  1  ]]  >&3 ;  then  echo eins;  elif [[ 1 = 2 ]] >&3; then echo zwei  ;else echo drei; fi >&3
	}
	inline_TIF_TBANG_TDBRACKET_TELIF() {
		if ! [[ 1 = 1 ]] >&3 
		then
			\echo eins 
		elif [[ 1 = 2 ]] >&3 
		then
			\echo zwei 
		else
			\echo drei 
		fi >&3 
	} 
	function comsub_TIF_TBANG_TDBRACKET_TELIF { x=$(
		if  !  [[  1  =  1  ]]  >&3 ;  then  echo eins;  elif [[ 1 = 2 ]] >&3; then echo zwei  ;else echo drei; fi >&3
	); }
	function comsub_TIF_TBANG_TDBRACKET_TELIF {
		x=$(if ! [[ 1 = 1 ]] >&3 ; then \echo eins ; elif [[ 1 = 2 ]] >&3 ; then \echo zwei ; else \echo drei ; fi >&3 ) 
	} 
	function reread_TIF_TBANG_TDBRACKET_TELIF { x=$((
		if  !  [[  1  =  1  ]]  >&3 ;  then  echo eins;  elif [[ 1 = 2 ]] >&3; then echo zwei  ;else echo drei; fi >&3
	)|tr u x); }
	function reread_TIF_TBANG_TDBRACKET_TELIF {
		x=$( ( if ! [[ 1 = 1 ]] >&3 ; then \echo eins ; elif [[ 1 = 2 ]] >&3 ; then \echo zwei ; else \echo drei ; fi >&3 ) | \tr u x ) 
	} 
	inline_TWHILE() {
		i=1; while (( i < 10 )) >&3; do echo $i; let ++i; done >&3
	}
	inline_TWHILE() {
		i=1 
		while {
			      \\builtin let " i < 10 " 
		      } >&3 
		do
			\echo $i 
			\let ++i 
		done >&3 
	} 
	function comsub_TWHILE { x=$(
		i=1; while (( i < 10 )) >&3; do echo $i; let ++i; done >&3
	); }
	function comsub_TWHILE {
		x=$(i=1 ; while { \\builtin let " i < 10 " ; } >&3 ; do \echo $i ; \let ++i ; done >&3 ) 
	} 
	function reread_TWHILE { x=$((
		i=1; while (( i < 10 )) >&3; do echo $i; let ++i; done >&3
	)|tr u x); }
	function reread_TWHILE {
		x=$( ( i=1 ; while { \\builtin let " i < 10 " ; } >&3 ; do \echo $i ; \let ++i ; done >&3 ) | \tr u x ) 
	} 
	inline_TUNTIL() {
		i=10; until  (( !--i )) >&3 ; do echo $i; done >&3
	}
	inline_TUNTIL() {
		i=10 
		until {
			      \\builtin let " !--i " 
		      } >&3 
		do
			\echo $i 
		done >&3 
	} 
	function comsub_TUNTIL { x=$(
		i=10; until  (( !--i )) >&3 ; do echo $i; done >&3
	); }
	function comsub_TUNTIL {
		x=$(i=10 ; until { \\builtin let " !--i " ; } >&3 ; do \echo $i ; done >&3 ) 
	} 
	function reread_TUNTIL { x=$((
		i=10; until  (( !--i )) >&3 ; do echo $i; done >&3
	)|tr u x); }
	function reread_TUNTIL {
		x=$( ( i=10 ; until { \\builtin let " !--i " ; } >&3 ; do \echo $i ; done >&3 ) | \tr u x ) 
	} 
	inline_TCOPROC() {
		cat  *  >&3 |&  >&3 ls
	}
	inline_TCOPROC() {
		\cat * >&3 |& 
		\ls >&3 
	} 
	function comsub_TCOPROC { x=$(
		cat  *  >&3 |&  >&3 ls
	); }
	function comsub_TCOPROC {
		x=$(\cat * >&3 |&  \ls >&3 ) 
	} 
	function reread_TCOPROC { x=$((
		cat  *  >&3 |&  >&3 ls
	)|tr u x); }
	function reread_TCOPROC {
		x=$( ( \cat * >&3 |&  \ls >&3 ) | \tr u x ) 
	} 
	inline_TFUNCT_TBRACE_TASYNC() {
		function  korn  {  echo eins; echo >&3 zwei ;  }
		bourne  ()  {  logger *  >&3 &  }
	}
	inline_TFUNCT_TBRACE_TASYNC() {
		function korn {
			\echo eins 
			\echo zwei >&3 
		} 
		bourne() {
			\logger * >&3 & 
		} 
	} 
	function comsub_TFUNCT_TBRACE_TASYNC { x=$(
		function  korn  {  echo eins; echo >&3 zwei ;  }
		bourne  ()  {  logger *  >&3 &  }
	); }
	function comsub_TFUNCT_TBRACE_TASYNC {
		x=$(function korn { \echo eins ; \echo zwei >&3 ; } ; bourne() { \logger * >&3 &  } ) 
	} 
	function reread_TFUNCT_TBRACE_TASYNC { x=$((
		function  korn  {  echo eins; echo >&3 zwei ;  }
		bourne  ()  {  logger *  >&3 &  }
	)|tr u x); }
	function reread_TFUNCT_TBRACE_TASYNC {
		x=$( ( function korn { \echo eins ; \echo zwei >&3 ; } ; bourne() { \logger * >&3 &  } ) | \tr u x ) 
	} 
	inline_COMSUB_EXPRSUB() {
		echo $(true >&3) $((1+ 2))
	}
	inline_COMSUB_EXPRSUB() {
		\echo $(\true >&3 ) $((1+ 2)) 
	} 
	function comsub_COMSUB_EXPRSUB { x=$(
		echo $(true >&3) $((1+ 2))
	); }
	function comsub_COMSUB_EXPRSUB {
		x=$(\echo $(\true >&3 ) $((1+ 2)) ) 
	} 
	function reread_COMSUB_EXPRSUB { x=$((
		echo $(true >&3) $((1+ 2))
	)|tr u x); }
	function reread_COMSUB_EXPRSUB {
		x=$( ( \echo $(\true >&3 ) $((1+ 2)) ) | \tr u x ) 
	} 
---
name: funsub-1
description:
	Check that non-subenvironment command substitution works
stdin:
	set -e
	foo=bar
	echo "ob $foo ."
	echo "${
		echo "ib $foo :"
		foo=baz
		echo "ia $foo :"
		false
	}" .
	echo "oa $foo ."
expected-stdout:
	ob bar .
	ib bar :
	ia baz : .
	oa baz .
---
name: funsub-2
description:
	You can now reliably use local and return in funsubs
	(not exit though)
stdin:
	x=q; e=1; x=${ echo a; e=2; echo x$e;}; echo 1:y$x,$e,$?.
	x=q; e=1; x=${ echo a; typeset e=2; echo x$e;}; echo 2:y$x,$e,$?.
	x=q; e=1; x=${ echo a; typeset e=2; return 3; echo x$e;}; echo 3:y$x,$e,$?.
expected-stdout:
	1:ya x2,2,0.
	2:ya x2,1,0.
	3:ya,1,3.
---
name: valsub-1
description:
	Check that "value substitutions" work as advertised
stdin:
	x=1
	y=2
	z=3
	REPLY=4
	echo "before:	x<$x> y<$y> z<$z> R<$REPLY>"
	x=${|
		local y
		echo "start:	x<$x> y<$y> z<$z> R<$REPLY>"
		x=5
		y=6
		z=7
		REPLY=8
		echo "end:	x<$x> y<$y> z<$z> R<$REPLY>"
	}
	echo "after:	x<$x> y<$y> z<$z> R<$REPLY>"
	# ensure trailing newlines are kept
	t=${|REPLY=$'foo\n\n';}
	typeset -p t
	echo -n this used to segfault
	echo ${|true;}$(true).
expected-stdout:
	before:	x<1> y<2> z<3> R<4>
	start:	x<1> y<> z<3> R<>
	end:	x<5> y<6> z<7> R<8>
	after:	x<8> y<2> z<7> R<4>
	typeset t=$'foo\n\n'
	this used to segfault.
---
name: event-subst-3
description:
	Check that '!' substitution in noninteractive mode is ignored
file-setup: file 755 "falsetto"
	#! /bin/sh
	echo molto bene
	exit 42
file-setup: file 755 "!false"
	#! /bin/sh
	echo si
stdin:
	export PATH=.$PATHSEP$PATH
	falsetto
	echo yeap
	!false
	echo meow
	! false
	echo = $?
	if
	! false; then echo foo; else echo bar; fi
expected-stdout:
	molto bene
	yeap
	si
	meow
	= 0
	foo
---
name: event-subst-0
description:
	Check that '!' substitution in interactive mode is ignored
need-ctty: yes
arguments: !-i!
file-setup: file 755 "falsetto"
	#! /bin/sh
	echo molto bene
	exit 42
file-setup: file 755 "!false"
	#! /bin/sh
	echo si
stdin:
	export PATH=.$PATHSEP$PATH
	falsetto
	echo yeap
	!false
	echo meow
	! false
	echo = $?
	if
	! false; then echo foo; else echo bar; fi
expected-stdout:
	molto bene
	yeap
	si
	meow
	= 0
	foo
expected-stderr-pattern:
	/.*/
---
name: nounset-1
description:
	Check that "set -u" matches (future) SUSv4 requirement
stdin:
	(set -u
	try() {
		local v
		eval v=\$$1
		if [[ -n $v ]]; then
			echo $1=nz
		else
			echo $1=zf
		fi
	}
	x=y
	(echo $x)
	echo =1
	(echo $y)
	echo =2
	(try x)
	echo =3
	(try y)
	echo =4
	(try 0)
	echo =5
	(try 2)
	echo =6
	(try)
	echo =7
	(echo at=$@)
	echo =8
	(echo asterisk=$*)
	echo =9
	(echo $?)
	echo =10
	(echo $!)
	echo =11
	(echo $-)
	echo =12
	#(echo $_)
	#echo =13
	(echo $#)
	echo =14
	(mypid=$$; try mypid)
	echo =15
	) 2>&1 | sed -e 's/^[A-Za-z]://' -e 's/^[^]]*]//' -e 's/^[^:]*: *//'
	exit ${PIPESTATUS[0]}
expected-stdout:
	y
	=1
	y: parameter not set
	=2
	x=nz
	=3
	y: parameter not set
	=4
	0=nz
	=5
	2: parameter not set
	=6
	1: parameter not set
	=7
	at=
	=8
	asterisk=
	=9
	0
	=10
	!: parameter not set
	=11
	ush
	=12
	0
	=14
	mypid=nz
	=15
---
name: nameref-1
description:
	Testsuite for nameref (bound variables)
stdin:
	bar=global
	typeset -n ir2=bar
	typeset -n ind=ir2
	echo !ind: ${!ind}
	echo ind: $ind
	echo !ir2: ${!ir2}
	echo ir2: $ir2
	typeset +n ind
	echo !ind: ${!ind}
	echo ind: $ind
	typeset -n ir2=ind
	echo !ir2: ${!ir2}
	echo ir2: $ir2
	set|grep ^ir2|sed 's/^/s1: /'
	typeset|grep ' ir2'|sed -e 's/^/s2: /' -e 's/nameref/typeset -n/'
	set -A blub -- e1 e2 e3
	typeset -n ind=blub
	typeset -n ir2=blub[2]
	echo !ind[1]: ${!ind[1]}
	echo !ir2: $!ir2
	echo ind[1]: ${ind[1]}
	echo ir2: $ir2
expected-stdout:
	!ind: bar
	ind: global
	!ir2: bar
	ir2: global
	!ind: ind
	ind: ir2
	!ir2: ind
	ir2: ir2
	s1: ir2=ind
	s2: typeset -n ir2
	!ind[1]: blub[1]
	!ir2: ir2
	ind[1]: e2
	ir2: e3
---
name: nameref-2da
description:
	Testsuite for nameref (bound variables)
	Functions, argument given directly, after local
stdin:
	function foo {
		typeset bar=lokal baz=auch
		typeset -n v=bar
		echo entering
		echo !v: ${!v}
		echo !bar: ${!bar}
		echo !baz: ${!baz}
		echo bar: $bar
		echo v: $v
		v=123
		echo bar: $bar
		echo v: $v
		echo exiting
	}
	bar=global
	echo bar: $bar
	foo bar
	echo bar: $bar
expected-stdout:
	bar: global
	entering
	!v: bar
	!bar: bar
	!baz: baz
	bar: lokal
	v: lokal
	bar: 123
	v: 123
	exiting
	bar: global
---
name: nameref-3
description:
	Advanced testsuite for bound variables (ksh93 fails this)
stdin:
	typeset -n foo=bar[i]
	set -A bar -- b c a
	for i in 0 1 2 3; do
		print $i $foo .
	done
expected-stdout:
	0 b .
	1 c .
	2 a .
	3 .
---
name: nameref-4
description:
	Ensure we don't run in an infinite loop
time-limit: 3
stdin:
	baz() {
		typeset -n foo=fnord fnord=foo
		foo[0]=bar
	}
	set -A foo bad
	echo sind $foo .
	baz
	echo blah $foo .
expected-stdout:
	sind bad .
	blah bad .
expected-stderr-pattern:
	/fnord: expression recurses on parameter/
---
name: better-parens-1a
description:
	Check support for ((‚Ä¶)) and $((‚Ä¶)) vs (‚Ä¶) and $(‚Ä¶)
stdin:
	if ( (echo fubar)|tr u x); then
		echo ja
	else
		echo nein
	fi
expected-stdout:
	fxbar
	ja
---
name: better-parens-1b
description:
	Check support for ((‚Ä¶)) and $((‚Ä¶)) vs (‚Ä¶) and $(‚Ä¶)
stdin:
	echo $( (echo fubar)|tr u x) $?
expected-stdout:
	fxbar 0
---
name: better-parens-1c
description:
	Check support for ((‚Ä¶)) and $((‚Ä¶)) vs (‚Ä¶) and $(‚Ä¶)
stdin:
	x=$( (echo fubar)|tr u x); echo $x $?
expected-stdout:
	fxbar 0
---
name: better-parens-2a
description:
	Check support for ((‚Ä¶)) and $((‚Ä¶)) vs (‚Ä¶) and $(‚Ä¶)
stdin:
	if ((echo fubar)|tr u x); then
		echo ja
	else
		echo nein
	fi
expected-stdout:
	fxbar
	ja
---
name: better-parens-2b
description:
	Check support for ((‚Ä¶)) and $((‚Ä¶)) vs (‚Ä¶) and $(‚Ä¶)
stdin:
	echo $((echo fubar)|tr u x) $?
expected-stdout:
	fxbar 0
---
name: better-parens-2c
description:
	Check support for ((‚Ä¶)) and $((‚Ä¶)) vs (‚Ä¶) and $(‚Ä¶)
stdin:
	x=$((echo fubar)|tr u x); echo $x $?
expected-stdout:
	fxbar 0
---
name: better-parens-3a
description:
	Check support for ((‚Ä¶)) and $((‚Ä¶)) vs (‚Ä¶) and $(‚Ä¶)
stdin:
	if ( (echo fubar)|(tr u x)); then
		echo ja
	else
		echo nein
	fi
expected-stdout:
	fxbar
	ja
---
name: better-parens-3b
description:
	Check support for ((‚Ä¶)) and $((‚Ä¶)) vs (‚Ä¶) and $(‚Ä¶)
stdin:
	echo $( (echo fubar)|(tr u x)) $?
expected-stdout:
	fxbar 0
---
name: better-parens-3c
description:
	Check support for ((‚Ä¶)) and $((‚Ä¶)) vs (‚Ä¶) and $(‚Ä¶)
stdin:
	x=$( (echo fubar)|(tr u x)); echo $x $?
expected-stdout:
	fxbar 0
---
name: better-parens-4a
description:
	Check support for ((‚Ä¶)) and $((‚Ä¶)) vs (‚Ä¶) and $(‚Ä¶)
stdin:
	if ((echo fubar)|(tr u x)); then
		echo ja
	else
		echo nein
	fi
expected-stdout:
	fxbar
	ja
---
name: better-parens-4b
description:
	Check support for ((‚Ä¶)) and $((‚Ä¶)) vs (‚Ä¶) and $(‚Ä¶)
stdin:
	echo $((echo fubar)|(tr u x)) $?
expected-stdout:
	fxbar 0
---
name: better-parens-4c
description:
	Check support for ((‚Ä¶)) and $((‚Ä¶)) vs (‚Ä¶) and $(‚Ä¶)
stdin:
	x=$((echo fubar)|(tr u x)); echo $x $?
expected-stdout:
	fxbar 0
---
name: better-parens-5
description:
	Another corner case
stdin:
	( (echo 'fo	o$bar' "baz\$bla\"" m\$eh) | tr a A)
	((echo 'fo	o$bar' "baz\$bla\"" m\$eh) | tr a A)
expected-stdout:
	fo	o$bAr bAz$blA" m$eh
	fo	o$bAr bAz$blA" m$eh
---
name: echo-test-1
description:
	Test what the echo builtin does (mksh)
category: !shell:ebcdic-yes
stdin:
	echo -n 'foo\x40bar'
	echo -e '\tbaz'
expected-stdout:
	foo@bar	baz
---
name: echo-test-1-ebcdic
description:
	Test what the echo builtin does (mksh)
category: !shell:ebcdic-no
stdin:
	echo -n 'foo\x7Cbar'
	echo -e '\tbaz'
expected-stdout:
	foo@bar	baz
---
name: echo-test-2
description:
	Test what the echo builtin does (POSIX)
	Note: this follows Debian Policy 10.4 which mandates
	that -n shall be treated as an option, not XSI which
	mandates it shall be treated as string but escapes
	shall be expanded.
stdin:
	test -n "$POSH_VERSION" || set -o posix
	echo -n 'foo\x40bar'
	echo -e '\tbaz'
expected-stdout:
	foo\x40bar-e \tbaz
---
name: echo-test-3-mnbsd
description:
	Test what the echo builtin does, and test a compatibility flag.
category: mnbsdash
stdin:
	"$__progname" -c 'echo -n 1=\\x40$1; echo -e \\x2E' -- foo bar
	"$__progname" -o posix -c 'echo -n 2=\\x40$1; echo -e \\x2E' -- foo bar
	"$__progname" -o sh -c 'echo -n 3=\\x40$1; echo -e \\x2E' -- foo bar
expected-stdout:
	1=@foo.
	2=\x40foo-e \x2E
	3=\x40bar.
---
name: echo-test-3-normal
description:
	Test what the echo builtin does, and test a compatibility flag.
category: !mnbsdash,!shell:ebcdic-yes
stdin:
	"$__progname" -c 'echo -n 1=\\x40$1; echo -e \\x2E' -- foo bar
	"$__progname" -o posix -c 'echo -n 2=\\x40$1; echo -e \\x2E' -- foo bar
	"$__progname" -o sh -c 'echo -n 3=\\x40$1; echo -e \\x2E' -- foo bar
expected-stdout:
	1=@foo.
	2=\x40foo-e \x2E
	3=\x40foo-e \x2E
---
name: echo-test-3-ebcdic
description:
	Test what the echo builtin does, and test a compatibility flag.
category: !mnbsdash,!shell:ebcdic-no
stdin:
	"$__progname" -c 'echo -n 1=\\x7C$1; echo -e \\x4B' -- foo bar
	"$__progname" -o posix -c 'echo -n 2=\\x7C$1; echo -e \\x4B' -- foo bar
	"$__progname" -o sh -c 'echo -n 3=\\x7C$1; echo -e \\x4B' -- foo bar
expected-stdout:
	1=@foo.
	2=\x7Cfoo-e \x4B
	3=\x7Cfoo-e \x4B
---
name: utilities-getopts-1
description:
	getopts sets OPTIND correctly for unparsed option
stdin:
	set -- -a -a -x
	while getopts :a optc; do
	    echo "OPTARG=$OPTARG, OPTIND=$OPTIND, optc=$optc."
	done
	echo done
expected-stdout:
	OPTARG=, OPTIND=2, optc=a.
	OPTARG=, OPTIND=3, optc=a.
	OPTARG=x, OPTIND=4, optc=?.
	done
---
name: utilities-getopts-2
description:
	Check OPTARG
stdin:
	set -- -a Mary -x
	while getopts a: optc; do
	    echo "OPTARG=$OPTARG, OPTIND=$OPTIND, optc=$optc."
	done
	echo done
expected-stdout:
	OPTARG=Mary, OPTIND=3, optc=a.
	OPTARG=, OPTIND=4, optc=?.
	done
expected-stderr-pattern: /.*-x.*option/
---
name: utilities-getopts-3
description:
	Check unsetting OPTARG
stdin:
	set -- -x arg -y
	getopts x:y opt && echo "${OPTARG-unset}"
	getopts x:y opt && echo "${OPTARG-unset}"
expected-stdout:
	arg
	unset
---
name: wcswidth-1
description:
	Check the new wcswidth feature
stdin:
	s=‰Ωï
	set +U
	print octets: ${#s} .
	print 8-bit width: ${%s} .
	set -U
	print characters: ${#s} .
	print columns: ${%s} .
	s=ÔøΩ
	set +U
	print octets: ${#s} .
	print 8-bit width: ${%s} .
	set -U
	print characters: ${#s} .
	print columns: ${%s} .
expected-stdout:
	octets: 3 .
	8-bit width: -1 .
	characters: 1 .
	columns: 2 .
	octets: 3 .
	8-bit width: 3 .
	characters: 1 .
	columns: 1 .
---
name: wcswidth-2
description:
	Check some corner cases
stdin:
	print % $% .
	set -U
	x='a	b'
	print c ${%x} .
	set +U
	x='a	b'
	print d ${%x} .
expected-stdout:
	% $% .
	c -1 .
	d -1 .
---
name: wcswidth-3
description:
	Check some corner cases
stdin:
	print ${%} .
expected-stderr-pattern:
	/bad substitution/
expected-exit: 1
---
name: wcswidth-4a
description:
	Check some corner cases
stdin:
	print ${%*} .
expected-stderr-pattern:
	/bad substitution/
expected-exit: 1
---
name: wcswidth-4b
description:
	Check some corner cases
stdin:
	print ${%@} .
expected-stderr-pattern:
	/bad substitution/
expected-exit: 1
---
name: wcswidth-4c
description:
	Check some corner cases
stdin:
	:
	print ${%?} .
expected-stdout:
	1 .
---
name: realpath-1
description:
	Check proper return values for realpath
category: os:mirbsd
stdin:
	wd=$(realpath .)
	mkdir dir
	:>file
	:>dir/file
	ln -s dir lndir
	ln -s file lnfile
	ln -s nix lnnix
	ln -s . lnself
	i=0
	chk() {
		typeset x y
		x=$(realpath "$wd/$1" 2>&1); y=$?
		print $((++i)) "?$1" =${x##*$wd/} !$y
	}
	chk dir
	chk dir/
	chk dir/file
	chk dir/nix
	chk file
	chk file/
	chk file/file
	chk file/nix
	chk nix
	chk nix/
	chk nix/file
	chk nix/nix
	chk lndir
	chk lndir/
	chk lndir/file
	chk lndir/nix
	chk lnfile
	chk lnfile/
	chk lnfile/file
	chk lnfile/nix
	chk lnnix
	chk lnnix/
	chk lnnix/file
	chk lnnix/nix
	chk lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself
	rm lnself
expected-stdout:
	1 ?dir =dir !0
	2 ?dir/ =dir !0
	3 ?dir/file =dir/file !0
	4 ?dir/nix =dir/nix !0
	5 ?file =file !0
	6 ?file/ =file/: Not a directory !20
	7 ?file/file =file/file: Not a directory !20
	8 ?file/nix =file/nix: Not a directory !20
	9 ?nix =nix !0
	10 ?nix/ =nix !0
	11 ?nix/file =nix/file: No such file or directory !2
	12 ?nix/nix =nix/nix: No such file or directory !2
	13 ?lndir =dir !0
	14 ?lndir/ =dir !0
	15 ?lndir/file =dir/file !0
	16 ?lndir/nix =dir/nix !0
	17 ?lnfile =file !0
	18 ?lnfile/ =lnfile/: Not a directory !20
	19 ?lnfile/file =lnfile/file: Not a directory !20
	20 ?lnfile/nix =lnfile/nix: Not a directory !20
	21 ?lnnix =nix !0
	22 ?lnnix/ =nix !0
	23 ?lnnix/file =lnnix/file: No such file or directory !2
	24 ?lnnix/nix =lnnix/nix: No such file or directory !2
	25 ?lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself =lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself/lnself: Too many levels of symbolic links !62
---
name: realpath-2
description:
	Ensure that exactly two leading slashes are not collapsed
	POSIX guarantees this exception, e.g. for UNC paths on Cygwin
category: os:mirbsd
stdin:
	ln -s /bin t1
	ln -s //bin t2
	ln -s ///bin t3
	realpath /bin
	realpath //bin
	realpath ///bin
	realpath /usr/bin
	realpath /usr//bin
	realpath /usr///bin
	realpath t1
	realpath t2
	realpath t3
	rm -f t1 t2 t3
	cd //usr/bin
	pwd
	cd ../lib
	pwd
	realpath //usr/include/../bin
expected-stdout:
	/bin
	//bin
	/bin
	/usr/bin
	/usr/bin
	/usr/bin
	/bin
	//bin
	/bin
	//usr/bin
	//usr/lib
	//usr/bin
---
name: crash-1
description:
	Crashed during March 2011, fixed on vernal equin≈çx ‚ò∫
category: os:mirbsd,os:openbsd
stdin:
	export MALLOC_OPTIONS=FGJRSX
	"$__progname" -c 'x=$(tr z r <<<baz); echo $x'
expected-stdout:
	bar
---
name: debian-117-1
description:
	Check test - bug#465250
stdin:
	test \( ! -e \) ; echo $?
expected-stdout:
	1
---
name: debian-117-2
description:
	Check test - bug#465250
stdin:
	test \(  -e \) ; echo $?
expected-stdout:
	0
---
name: debian-117-3
description:
	Check test - bug#465250
stdin:
	test ! -e  ; echo $?
expected-stdout:
	1
---
name: debian-117-4
description:
	Check test - bug#465250
stdin:
	test  -e  ; echo $?
expected-stdout:
	0
---
name: case-zsh
description:
	Check that zsh case variants work
stdin:
	case 'b' in
	  a) echo a ;;
	  b) echo b ;;
	  c) echo c ;;
	  *) echo x ;;
	esac
	echo =
	case 'b' in
	  a) echo a ;&
	  b) echo b ;&
	  c) echo c ;&
	  *) echo x ;&
	esac
	echo =
	case 'b' in
	  a) echo a ;|
	  b) echo b ;|
	  c) echo c ;|
	  *) echo x ;|
	esac
expected-stdout:
	b
	=
	b
	c
	x
	=
	b
	x
---
name: case-braces
description:
	Check that case end tokens are not mixed up (Debian #220272)
stdin:
	i=0
	for value in 'x' '}' 'esac'; do
		print -n "$((++i))($value)bourne "
		case $value in
		}) echo brace ;;
		*) echo no ;;
		esac
		print -n "$((++i))($value)korn "
		case $value {
		esac) echo esac ;;
		*) echo no ;;
		}
	done
expected-stdout:
	1(x)bourne no
	2(x)korn no
	3(})bourne brace
	4(})korn no
	5(esac)bourne no
	6(esac)korn esac
---
name: command-shift
description:
	Check that 'command shift' works
stdin:
	function snc {
		echo "before	0='$0' 1='$1' 2='$2'"
		shift
		echo "after	0='$0' 1='$1' 2='$2'"
	}
	function swc {
		echo "before	0='$0' 1='$1' 2='$2'"
		command shift
		echo "after	0='$0' 1='$1' 2='$2'"
	}
	echo = without command
	snc ‰∏Ä ‰∫å
	echo = with command
	swc ‰∏Ä ‰∫å
	echo = done
expected-stdout:
	= without command
	before	0='snc' 1='‰∏Ä' 2='‰∫å'
	after	0='snc' 1='‰∫å' 2=''
	= with command
	before	0='swc' 1='‰∏Ä' 2='‰∫å'
	after	0='swc' 1='‰∫å' 2=''
	= done
---
name: command-set
description:
	Same but with set
stdin:
	showargs() { for s_arg in "$@"; do echo -n "<$s_arg> "; done; echo .; }
	showargs 1 "$@"
	set -- foo bar baz
	showargs 2 "$@"
	command set -- miau 'meow nyao'
	showargs 3 "$@"
expected-stdout:
	<1> .
	<2> <foo> <bar> <baz> .
	<3> <miau> <meow nyao> .
---
name: command-readonly
description:
	These should not exit on error when prefixed
stdin:
	exec 2>/dev/null
	"$__progname" -c 'readonly v; export v=foo || echo ok'
	echo ef=$?
	"$__progname" -c 'readonly v; command export v=foo || echo ok'
	echo en=$?
	"$__progname" -c 'readonly v; readonly v=foo || echo ok'
	echo rf=$?
	"$__progname" -c 'readonly v; command readonly v=foo || echo ok'
	echo rn=$?
expected-stdout:
	ef=2
	ok
	en=0
	rf=2
	ok
	rn=0
---
name: command-dot-regression
description:
	Check a regression in fixing the above does not appear
stdin:
	cat >test.mksh <<\EOF
	set -- one two
	shift
	for s_arg in "$#" "$@"; do echo -n "<$s_arg> "; done; echo .
	EOF
	"$__progname" -c '. ./test.mksh' dummy oh dear this is not good
	echo =
	"$__progname" -c 'command . ./test.mksh' dummy oh dear this is not good
expected-stdout:
	<1> <two> .
	=
	<1> <two> .
---
name: command-pvV-posix-priorities
description:
	For POSIX compatibility, command -v should find aliases and reserved
	words, and command -p[vV] should find aliases, reserved words, and
	builtins over external commands.
stdin:
	PATH=/bin:/usr/bin
	alias foo="bar baz"
	alias '[ab]=:'
	bar() { :; }
	for word in 'if' 'foo' 'bar' 'set' 'true' '[ab]'; do
		command -v "$word"
		command -pv "$word"
		command -V "$word"
		command -pV "$word"
	done
	# extra checks
	alias '[ab]'
	whence '[ab]'
expected-stdout:
	if
	if
	if is a reserved word
	if is a reserved word
	alias foo='bar baz'
	alias foo='bar baz'
	foo is an alias for 'bar baz'
	foo is an alias for 'bar baz'
	bar
	bar
	bar is a function
	bar is a function
	set
	set
	set is a special shell builtin
	set is a special shell builtin
	true
	true
	true is a shell builtin
	true is a shell builtin
	alias '[ab]'=:
	alias '[ab]'=:
	'[ab]' is an alias for :
	'[ab]' is an alias for :
	'[ab]'=:
	:
---
name: whence-preserve-tradition
description:
	This regression test is to ensure that the POSIX compatibility
	changes for 'command' (see previous test) do not affect traditional
	'whence' behaviour.
category: os:mirbsd
stdin:
	PATH=/bin:/usr/bin
	alias foo="bar baz"
	bar() { :; }
	for word in 'if' 'foo' 'bar' 'set' 'true'; do
		whence "$word"
		whence -p "$word"
		whence -v "$word"
		whence -pv "$word"
	done
expected-stdout:
	if
	if is a reserved word
	if not found
	'bar baz'
	foo is an alias for 'bar baz'
	foo not found
	bar
	bar is a function
	bar not found
	set
	set is a special shell builtin
	set not found
	true
	/bin/true
	true is a shell builtin
	true is a tracked alias for /bin/true
---
name: duffs-device
description:
	Check that the compiler did not optimise-break them
	(lex.c has got a similar one in SHEREDELIM)
category: !shell:faux-ebcdic,!shell:ebcdic-yes
stdin:
	set +U
	s=
	typeset -i1 i=0
	while (( ++i < 256 )); do
		s+=${i#1#}
	done
	s+=$'\xC2\xA0\xE2\x82\xAC\xEF\xBF\xBD\xEF\xBF\xBE\xEF\xBF\xBF\xF0\x90\x80\x80.'
	typeset -p s
expected-stdout:
	typeset s=$'\001\002\003\004\005\006\a\b\t\n\v\f\r\016\017\020\021\022\023\024\025\026\027\030\031\032\E\034\035\036\037 !"#$%&\047()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\177\200\201\202\203\204\205\206\207\210\211\212\213\214\215\216\217\220\221\222\223\224\225\226\227\230\231\232\233\234\235\236\237\240\241\242\243\244\245\246\247\250\251\252\253\254\255\256\257\260\261\262\263\264\265\266\267\270\271\272\273\274\275\276\277\300\301\302\303\304\305\306\307\310\311\312\313\314\315\316\317\320\321\322\323\324\325\326\327\330\331\332\333\334\335\336\337\340\341\342\343\344\345\346\347\350\351\352\353\354\355\356\357\360\361\362\363\364\365\366\367\370\371\372\373\374\375\376\377\u00A0\u20AC\uFFFD\357\277\276\357\277\277\360\220\200\200.'
---
name: duffs-device-ebcdic
description:
	Check that the compiler did not optimise-break them
category: !shell:ebcdic-no
stdin:
	set +U
	s=
	typeset -i1 i=0
	while (( ++i < 256 )); do
		s+=${i#1#}
	done
	#s+=$'\xC2\xA0\xE2\x82\xAC\xEF\xBF\xBD\xEF\xBF\xBE\xEF\xBF\xBF\xF0\x90\x80\x80.' #XXX
	typeset -p s
expected-stdout:
	typeset s=$'\001\002\003\004\t\006\007\010\011\012\v\f\r\016\017\020\021\022\023\024\n\b\027\030\031\032\033\034\035\036\037\040\041\042\043\044\045\046\E\050\051\052\053\054\055\056\a\060\061\062\063\064\065\066\067\070\071\072\073\074\075\076\077 †‚‰‡·„ÂÁÒ¢.<(+|&ÈÍÎËÌÓÔÏﬂ!$*);^-/¬ƒ¿¡√≈«—¶,%_>?¯… À»ÕŒœÃ`:#@\175="ÿabcdefghi´ª˝˛±∞jklmnopqr™∫Ê∏∆§µ~stuvwxyz°ø–[ﬁÆ¨£•∑©ß∂ºΩæ›®Ø]¥◊{ABCDEFGHI≠ÙˆÚÛı}JKLMNOPQRπ˚¸˘˙ˇ\\˜STUVWXYZ≤‘÷“”’0123456789≥€‹Ÿ⁄\377'
---
name: duffs-device-faux-EBCDIC
description:
	Check that the compiler did not optimise-break them
category: shell:faux-ebcdic
stdin:
	set +U
	s=
	typeset -i1 i=0
	while (( ++i < 256 )); do
		s+=${i#1#}
	done
	s+=$'\xC2\xA0\xE2\x82\xAC\xEF\xBF\xBD\xEF\xBF\xBE\xEF\xBF\xBF\xF0\x90\x80\x80.'
	typeset -p s
expected-stdout:
	typeset s=$'\001\002\003\004\005\006\a\b\t\n\v\f\r\016\017\020\021\022\023\024\025\026\027\030\031\032\E\034\035\036\037 !"#$%&\047()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\177\200\201\202\203\204\205\206\207\210\211\212\213\214\215\216\217\220\221\222\223\224\225\226\227\230\231\232\233\234\235\236\237†°¢£§•¶ß®©™´¨≠ÆØ∞±≤≥¥µ∂∑∏π∫ªºΩæø¿¡¬√ƒ≈∆«»… ÀÃÕŒœ–—“”‘’÷◊ÿŸ⁄€‹›ﬁﬂ‡·‚„‰ÂÊÁËÈÍÎÏÌÓÔÒÚÛÙıˆ˜¯˘˙˚¸˝˛ˇ\u00A0\u20AC\uFFFDÔøæÔøø\220\200\200.'
---
name: stateptr-underflow
description:
	This check overflows an Xrestpos stored in a short in R40
category: fastbox
stdin:
	function Lb64decode {
		[[ -o utf8-mode ]]; local u=$?
		set +U
		local c s="$*" t=
		[[ -n $s ]] || { s=$(cat;print x); s=${s%x}; }
		local -i i=0 n=${#s} p=0 v x
		local -i16 o
	
		while (( i < n )); do
			c=${s:(i++):1}
			case $c {
			(=)	break ;;
			([A-Z])	(( v = 1#$c - 65 )) ;;
			([a-z])	(( v = 1#$c - 71 )) ;;
			([0-9])	(( v = 1#$c + 4 )) ;;
			(+)	v=62 ;;
			(/)	v=63 ;;
			(*)	continue ;;
			}
			(( x = (x << 6) | v ))
			case $((p++)) {
			(0)	continue ;;
			(1)	(( o = (x >> 4) & 255 )) ;;
			(2)	(( o = (x >> 2) & 255 )) ;;
			(3)	(( o = x & 255 ))
				p=0
				;;
			}
			t=$t\\x${o#16#}
		done
		print -n $t
		(( u )) || set -U
	}
	
	i=-1
	s=
	while (( ++i < 12120 )); do
		s+=a
	done
	Lb64decode $s >/dev/null
---
name: xtrace-1
description:
	Check that "set -x" doesn't redirect too quickly
stdin:
	print '#!'"$__progname" >bash
	cat >>bash <<'EOF'
	echo 'GNU bash, version 2.05b.0(1)-release (i386-ecce-mirbsd10)
	Copyright (C) 2002 Free Software Foundation, Inc.'
	EOF
	chmod +x bash
	"$__progname" -xc 'foo=$(./bash --version 2>&1 | sed q); echo "=$foo="'
expected-stdout:
	=GNU bash, version 2.05b.0(1)-release (i386-ecce-mirbsd10)=
expected-stderr-pattern:
	/.*/
---
name: xtrace-2
description:
	Check that "set -x" is off during PS4 expansion
stdin:
	f() {
		print -n "(f1:$-)"
		set -x
		print -n "(f2:$-)"
	}
	PS4='[(p:$-)$(f)] '
	print "(o0:$-)"
	set -x -o inherit-xtrace
	print "(o1:$-)"
	set +x
	print "(o2:$-)"
expected-stdout:
	(o0:sh)
	(o1:shx)
	(o2:sh)
expected-stderr:
	[(p:sh)(f1:sh)(f2:sh)] print '(o1:shx)'
	[(p:sh)(f1:sh)(f2:sh)] set +x
---
name: fksh-flags
description:
	Check that FKSH functions have their own shell flags
category: shell:legacy-no
stdin:
	[[ $KSH_VERSION = Version* ]] && set +B
	function foo {
		set +f
		set -e
		echo 2 "${-/s}" .
	}
	set -fh
	echo 1 "${-/s}" .
	foo
	echo 3 "${-/s}" .
expected-stdout:
	1 fh .
	2 eh .
	3 fh .
---
name: fksh-flags-legacy
description:
	Check that even FKSH functions share the shell flags
category: shell:legacy-yes
stdin:
	[[ $KSH_VERSION = Version* ]] && set +B
	foo() {
		set +f
		set -e
		echo 2 "${-/s}" .
	}
	set -fh
	echo 1 "${-/s}" .
	foo
	echo 3 "${-/s}" .
expected-stdout:
	1 fh .
	2 eh .
	3 eh .
---
name: fsh-flags
description:
	Check that !FKSH functions share the shell flags
stdin:
	[[ $KSH_VERSION = Version* ]] && set +B
	foo() {
		set +f
		set -e
		echo 2 "${-/s}" .
	}
	set -fh
	echo 1 "${-/s}" .
	foo
	echo 3 "${-/s}" .
expected-stdout:
	1 fh .
	2 eh .
	3 eh .
---
