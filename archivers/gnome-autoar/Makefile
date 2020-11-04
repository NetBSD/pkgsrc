# $NetBSD: Makefile,v 1.1 2020/11/04 12:27:58 nia Exp $

DISTNAME=	gnome-autoar-0.2.4
CATEGORIES=	archivers gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	dan@alt.md
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
