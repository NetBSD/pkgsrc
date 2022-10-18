# $NetBSD: builtin.mk,v 1.4 2022/10/18 07:48:48 wiz Exp $

BUILTIN_PKG:=			libpciaccess
PKGCONFIG_FILE.libpciaccess=	${X11BASE}/lib/pkgconfig/pciaccess.pc
PKGCONFIG_FILE.libpciaccess+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/pciaccess.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
