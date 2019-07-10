# $NetBSD: builtin.mk,v 1.1 2019/07/10 22:36:49 rjs Exp $

BUILTIN_PKG:=	libepoxy
PKGCONFIG_FILE.libepoxy=	${X11BASE}/lib/pkgconfig/epoxy.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
