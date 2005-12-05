# $NetBSD: hacks.mk,v 1.4 2005/12/05 20:49:57 rillig Exp $

### [Sun Mar 14 19:32:40 UTC 2004 : jlam]
### GCC 3.3.x and older versions have an optimization bug on powerpc that's
### tickled by the db4 source code, so remove optimization flags in that
### case. This fixes PR pkg/30647 by Ian Spray.
###
.if ${MACHINE_ARCH} == "powerpc"
.  include "../../mk/compiler.mk"
.  if !empty(CC_VERSION:Mgcc*)
.    if !defined(_GCC_IS_TOO_OLD)
_GCC_IS_TOO_OLD!=	\
	if ${PKG_ADMIN} pmatch 'gcc<3.4' ${CC_VERSION}; then		\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
MAKEFLAGS+=	_GCC_IS_TOO_OLD=${_GCC_IS_TOO_OLD:Q}
.    endif
.    if !empty(_GCC_IS_TOO_OLD:M[yY][eE][sS])
PKG_HACKS+=		powerpc-codegen
BUILDLINK_TRANSFORM+=	rm:-O[0-9]*
.    endif
.  endif
.endif
