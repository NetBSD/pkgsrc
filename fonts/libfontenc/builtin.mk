# $NetBSD: builtin.mk,v 1.3 2014/03/10 11:05:51 jperkin Exp $

BUILTIN_PKG:=	libfontenc
PKGCONFIG_FILE.libfontenc=	${X11BASE}/lib/pkgconfig/fontenc.pc
PKGCONFIG_FILE.libfontenc+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/fontenc.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
