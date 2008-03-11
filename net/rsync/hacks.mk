# $NetBSD: hacks.mk,v 1.4 2008/03/11 10:16:43 tron Exp $

### [Tue Nov 21 19:32:00 UTC 2006 : tvierling]
### iconv(..., NULL, 0, NULL, 0) crashes in libc version of iconv(3)
###
.if ${OPSYS} == "Interix"
PKG_HACKS+=	pkgsrc-iconv
.include "../../converters/libiconv/buildlink3.mk"
.endif
