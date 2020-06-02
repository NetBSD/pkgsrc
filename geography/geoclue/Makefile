# $NetBSD: Makefile,v 1.28 2020/06/02 08:22:41 adam Exp $
#

DISTNAME=	geoclue-0.12.0
PKGREVISION=	21
CATEGORIES=	geography
MASTER_SITES=	http://folks.o-hand.com/jku/geoclue-releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/GeoClue
COMMENT=	Geoinformation service API and base providers
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	geoclue.pc.in

BUILDLINK_TRANSFORM+=	rm:-Werror

# for documentation build
BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

#for test
#.include "../../x11/gtk2/buildlink3.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
