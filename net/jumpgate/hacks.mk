# $NetBSD: hacks.mk,v 1.1 2005/11/03 17:11:34 tv Exp $

###
### Define socklen_t on platforms without it, until maintainer adds
### this check to autoconf tests
###
.if ${OPSYS} == "Interix"
PKG_HACKS+=	socklen-int
CPPFLAGS+=	-Dsocklen_t=int
.endif
