# $NetBSD: hacks.mk,v 1.3 2008/03/09 20:56:57 bjs Exp $

### [Tue Nov 21 19:32:00 UTC 2006 : tvierling]
### iconv(..., NULL, 0, NULL, 0) crashes in libc version of iconv(3)
###
.if ${OPSYS} == "Interix"
PKG_HACKS+=	pkgsrc-iconv
USE_GNU_ICONV=	yes
.endif
