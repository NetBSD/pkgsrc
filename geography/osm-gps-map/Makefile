# $NetBSD: Makefile,v 1.49 2024/05/29 16:32:47 adam Exp $

DISTNAME=	osm-gps-map-1.2.0
PKGREVISION=	15
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=nzjrs/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nzjrs/osm-gps-map/
COMMENT=	Gtk+ Widget for Displaying OpenStreetMap tiles
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	osmgpsmap-1.0.pc.in

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
