# $NetBSD: Makefile,v 1.16 2022/08/07 23:35:28 tnn Exp $

DISTNAME=	wayland-1.21.0
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.freedesktop.org/wayland/wayland/-/releases/${PKGVERSION_NOREV}/downloads/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://wayland.freedesktop.org/
COMMENT=	Display server protocol - development libraries
LICENSE=	mit

USE_TOOLS+=	pkg-config

USE_LANGUAGES=	c c++

MESON_ARGS+=	-Ddocumentation=false
MESON_ARGS+=	-Dtests=false

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/wayland-client.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/wayland-cursor.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/wayland-egl-backend.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/wayland-egl.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/wayland-scanner.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/wayland-server.pc

.include "platform.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "Linux"
.  include "../../devel/libepoll-shim/buildlink3.mk"
CPPFLAGS+=	-I${BUILDLINK_PREFIX.libepoll-shim}/include/libepoll-shim
.endif
.include "../../devel/libffi/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
