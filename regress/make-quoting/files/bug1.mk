# $NetBSD: bug1.mk,v 1.2 2005/05/15 23:37:13 rillig Exp $
#
# This file demonstrates a parsing bug in make(1) from NetBSD-1.6.2 and
# the current pkgsrc bmake. The make from NetBSD-2.99.15 has been fixed.
#
# The bug is that one of the closing braces is parsed twice -- once as
# terminator for a variable and once as literal character, which is
# appended to PKG_OPTIONS.

OPTIONS=	a b c d
MYOPTIONS=	-b -c

OPTIONS_1:=	${OPTIONS}
.for _o_ in ${MYOPTIONS}
_opt_:=		${_o_}
.  if !empty(_opt_:M-*)
OPTIONS_1:=	${OPTIONS_1:N${_opt_:C/-//}}	# <-- the bug
.  endif
.endfor

# This is a possible workaround for this bug. It defines an intermediate
# variable that reduces the complexity of the modifier expression.

OPTIONS_2:=	${OPTIONS}
.for _o_ in ${MYOPTIONS}
_opt_:=		${_o_}
_popt_:=	${_o_:C/-//}			# <-- workaround, part 1
.  if !empty(_opt_:M-*)
OPTIONS_2:=	${OPTIONS_2:N${_popt_}}		# <-- workaround, part 2
.  endif
.endfor

PASSED?=	no

# /usr/bin/make from NetBSD 2.99.15 or similar
.if !empty(MAKE_VERSION:Mnetbsd-2005*) && ${OPTIONS_1} == "a"
PASSED=		yes

# /usr/bin/make from NetBSD 1.6.2
.elif !empty(MAKE_VERSION:Mnetbsd-20040210) && ${OPTIONS_1} == "a b c d}}"
PASSED=		yes

# bmake from pkgsrc
.elif !empty(MAKE_VERSION:Mbmake-3.1.12*) && ${OPTIONS_1} == "a b c d}}"
PASSED=		yes

.endif

.PHONY: all
all:
	@echo "PASSED="${PASSED:Q}""
.if ${PASSED} != "yes"
	@echo "OPTIONS_1="${OPTIONS_1:Q}""
.endif
	@echo "OPTIONS_2="${OPTIONS_2:Q}""
