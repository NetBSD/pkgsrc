# $NetBSD: hacks.mk,v 1.1 2004/11/16 23:45:25 jlam Exp $

### [Sun Mar 14 19:32:40 UTC 2004 : jlam]
### Pre-3.3 GCC has an optimization bug on powerpc that's tickled by
### the db4 source code, so remove optimization flags in that case.
### This fixes PR 23737 by John Klos.
###
.if ${MACHINE_ARCH} == "powerpc"
.  include "../../mk/compiler.mk"
.  if !empty(CC_VERSION:Mgcc*)
.    if !defined(_GCC_IS_TOO_OLD)
_GCC_IS_TOO_OLD!=	\
	if ${PKG_ADMIN} pmatch 'gcc<3.3' ${CC_VERSION}; then		\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
MAKEFLAGS+=	_GCC_IS_TOO_OLD=${_GCC_IS_TOO_OLD}
.    endif
.    if !empty(_GCC_IS_TOO_OLD:M[yY][eE][sS])
#
# Pre-3.3 GCC has an optimization bug tickled by the db4 code, so remove
# optimization.
#
PKG_HACKS+=		powerpc-codegen
BUILDLINK_TRANSFORM+=	rm:-O[0-9]*
.    endif
.  endif
.endif
