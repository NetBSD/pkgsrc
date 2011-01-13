# $NetBSD: Makefile,v 1.7 2011/01/13 13:37:55 wiz Exp $
#

DISTNAME=	qlandkartegt-0.18.0
PKGREVISION=	4
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qlandkartegt/}

MAINTAINER=	jkunz@NetBSD.org
HOMEPAGE=	http://www.qlandkarte.org/
COMMENT=	GPS visualisation and mapping tool, supports Garmin devices
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/qlandkartegt-0.18.0
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

DEPENDS+=	qlandkartegt-garmindev>=0.3:../../geography/qlandkartegt-garmindev

.include "../../devel/cmake/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
