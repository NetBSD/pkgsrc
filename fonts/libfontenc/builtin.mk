# $NetBSD: builtin.mk,v 1.1.2.1 2008/09/18 17:33:27 cube Exp $

BUILTIN_PKG:=	libfontenc
PKGCONFIG_FILE.libfontenc=	${X11BASE}/lib/pkgconfig/fontenc.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
