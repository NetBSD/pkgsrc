# $NetBSD: Makefile,v 1.6 2026/04/25 19:35:46 vins Exp $

DISTNAME=	libgudev-238
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/libgudev
COMMENT=	GObject bindings to libudev
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	gudev-1.0.pc.in

UDEV_REQUIRED=	yes

# tests require umockdev, still unavailable on pkgsrc
MESON_ARGS+=	-Dtests=disabled

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/udev.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
