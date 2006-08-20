# $NetBSD: hacks.mk,v 1.1 2006/08/20 16:01:34 schwarz Exp $

.if !defined(YORICK_HACKS_MK)
YORICK_HACKS_MK=	# defined

### [Sun Aug 20 17:40:24 CEST 2006 : schwarz]
### when compiling with -ffast-math on Darwin the system thinks that
### libmath contains exp10.
###
.if ${OPSYS} == "Darwin"
PKG_HACKS+=		no_exp10
CPPFLAGS+=		-DNO_EXP10
.endif

.endif
