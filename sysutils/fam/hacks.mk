# $NetBSD: hacks.mk,v 1.1 2005/11/04 18:25:33 tv Exp $

###
### Interix doesn't have this constant.  There's no clear place to insert
### it into the source headers, so keep it here for now.
###
.if ${OPSYS} == "Interix"
PKG_HACKS+=	inaddr-loopback-constant
CPPFLAGS+=	-DINADDR_LOOPBACK=0x7F000001UL
.endif
