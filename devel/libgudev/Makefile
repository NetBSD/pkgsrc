# $NetBSD: Makefile,v 1.5 2026/04/20 19:30:37 vins Exp $

DISTNAME=	libgudev-238
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/libgudev
COMMENT=	GObject bindings to libudev
LICENSE=	gnu-lgpl-v2

# Other platforms currently lack libudev support.
#
BROKEN_EXCEPT_ON_PLATFORM=	Linux-*-* FreeBSD-*-* NetBSD-*-* OpenBSD-*-*

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	gudev-1.0.pc.in

# tests require umockdev, still unavailable on pkgsrc
MESON_ARGS+=	-Dintrospection=enabled \
		-Dtests=disabled \
		-Dvapi=disabled

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:M*BSD}
.  include "../../devel/libudev-bsd/buildlink3.mk"
.elif ${OPSYS} == "Linux"
# udev_device_get_current_tags()
BUILDLINK_API_DEPENDS.libudev+=   libudev>=3.2.14
.  include "../../sysutils/libudev/buildlink3.mk"
.endif

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
