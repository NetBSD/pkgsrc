# $NetBSD: Makefile,v 1.10 2011/11/01 06:01:24 sbd Exp $
#

DISTNAME=	QLandkarteM.0.2.0
PKGNAME=	qlandkartem-0.2.0
PKGREVISION=	7
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

INSTALLATION_DIRS+=	bin

do-configure:
	cd ${WRKSRC} && ${QMAKE} ${CONFIGURE_ARGS}

do-install:
	cp ${WRKSRC}/bin/qlm ${DESTDIR}${PREFIX}/bin

DEPENDS+=		qt4-sqlite3>=4.4:../../x11/qt4-sqlite3

.include "../../devel/cmake/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
