# $NetBSD: Makefile,v 1.1 2025/05/04 10:11:28 vins Exp $

DISTNAME=	libgudev-238
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/libgudev
COMMENT=	GObject bindings to libudev
LICENSE=	gnu-gpl-v2

ONLY_FOR_PLATFORM=	Linux-*-*	# sysutils/libudev

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	gudev-1.0.pc.in

# tests require umockdev, still unavailable on pkgsrc
MESON_ARGS+=	-Dintrospection=enabled \
		-Dtests=disabled \
		-Dvapi=disabled

# udev_device_get_current_tags()
BUILDLINK_API_DEPENDS.libudev+=   libudev>=3.2.14
.include "../../sysutils/libudev/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
