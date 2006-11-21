# $NetBSD: hacks.mk,v 1.1 2006/11/21 19:36:16 tv Exp $

### [Tue Nov 21 19:32:00 UTC 2006 : tvierling]
### iconv(..., NULL, 0, NULL, 0) crashes in libc version of iconv(3)
###
.if !empty(LOWER_OPSYS:Minterix*)
PKG_HACKS+=	pkgsrc-iconv
.include "../../converters/libiconv/buildlink3.mk"
.endif
