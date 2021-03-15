# $NetBSD: Makefile,v 1.2 2021/03/15 14:52:10 cirnatdan Exp $

DISTNAME=	gnome-autoar-0.3.1
CATEGORIES=	archivers gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/gnome-autoar
COMMENT=	GLib wrapper around libarchive
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-schemas-compile
CONFIGURE_ARGS+=	--enable-introspection

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
