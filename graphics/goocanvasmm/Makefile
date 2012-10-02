# $NetBSD: Makefile,v 1.22 2012/10/02 17:11:12 tron Exp $
#

DISTNAME=	goocanvasmm-0.15.4
PKGREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/goocanvasmm/0.15/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/GooCanvas
COMMENT=	C++ wrappers for goocanvas
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config perl
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	goocanvas/goocanvasmm.pc.in

CONFIGURE_ARGS+=	MMDOCTOOLDIR=${PREFIX}/share/glibmm-2.4/doctool

BUILDLINK_API_DEPENDS.glibmm+=	glibmm>=2.14.2
.include "../../devel/glibmm/buildlink3.mk"
BUILDLINK_API_DEPENDS.goocanvas+=	goocanvas>=0.15
.include "../../graphics/goocanvas/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtkmm+=	gtkmm>=2.22.0
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
