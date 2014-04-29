# $NetBSD: builtin.mk,v 1.1 2014/04/29 06:18:42 obache Exp $

BUILTIN_PKG:=	libpciaccess
PKGCONFIG_FILE.libpciaccess=	${X11BASE}/lib/pkgconfig/pciaccess.pc
PKGCONFIG_FILE.libpciaccess+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/pciaccess.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
