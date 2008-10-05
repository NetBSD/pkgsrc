# $NetBSD: builtin.mk,v 1.2 2008/10/05 21:36:35 cube Exp $

BUILTIN_PKG:=	libfontenc
PKGCONFIG_FILE.libfontenc=	${X11BASE}/lib/pkgconfig/fontenc.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
