# $NetBSD: builtin.mk,v 1.1 2019/07/10 22:36:49 rjs Exp $

BUILTIN_PKG:=	libvdpau
PKGCONFIG_FILE.libvdpau=	${X11BASE}/lib/pkgconfig/vdpau.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
