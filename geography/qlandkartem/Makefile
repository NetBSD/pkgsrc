# $NetBSD: Makefile,v 1.2 2010/03/14 16:32:16 wiz Exp $
#

DISTNAME=	QLandkarteM.0.2.0
PKGNAME=	qlandkartem-0.2.0
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qlandkartegt/}

MAINTAINER=	jkunz@NetBSD.org
HOMEPAGE=	http://www.qlandkarte.org/
COMMENT=	QLandkarteM is a moving map application for mobile devices
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/QLandkarteM
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
QMAKE=		${QTDIR}/bin/qmake

do-configure:
	cd ${WRKSRC} && ${QMAKE} ${CONFIGURE_ARGS}

do-install:
	cp ${WRKSRC}/bin/qlm ${PREFIX}/bin

DEPENDS+=		qt4-sqlite3>=4.4:../../x11/qt4-sqlite3

.include "../../devel/cmake/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
