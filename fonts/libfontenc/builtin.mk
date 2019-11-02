# $NetBSD: builtin.mk,v 1.4 2019/11/02 22:24:41 rillig Exp $

BUILTIN_PKG:=			libfontenc
PKGCONFIG_FILE.libfontenc=	${X11BASE}/lib/pkgconfig/fontenc.pc
PKGCONFIG_FILE.libfontenc+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/fontenc.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
