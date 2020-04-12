# $NetBSD: Makefile,v 1.27 2020/04/12 08:28:46 adam Exp $

DISTNAME=	osm-gps-map-1.0.2
PKGREVISION=	24
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=nzjrs/}
GITHUB_RELEASE=	1.0.2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nzjrs/osm-gps-map/
COMMENT=	Gtk+ Widget for Displaying OpenStreetMap tiles
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	osmgpsmap-1.0.pc.in

CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
