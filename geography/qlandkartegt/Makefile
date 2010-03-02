# $NetBSD: Makefile,v 1.1 2010/03/02 21:51:06 jkunz Exp $
#

DISTNAME=	qlandkartegt-0.17.1
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qlandkartegt/}

MAINTAINER=	jkunz@NetBSD.org
HOMEPAGE=	http://www.qlandkarte.org/
COMMENT=	GPS visualisation and mapping tool, supports Garmin devices
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/qlandkartegt-0.17.1
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

DEPENDS+=	qlandkartegt-garmindev>=0.3:../../geography/qlandkartegt-garmindev

.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
