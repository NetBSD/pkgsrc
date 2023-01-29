# $NetBSD: Makefile,v 1.12 2023/01/29 21:14:22 ryoon Exp $

DISTNAME=	gnome-autoar-0.4.1
PKGREVISION=	6
CATEGORIES=	archivers gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/gnome-autoar
COMMENT=	GLib wrapper around libarchive
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes

MESON_ARGS+=	-Dintrospection=enabled

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
