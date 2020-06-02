# $NetBSD: Makefile,v 1.60 2020/06/02 08:23:58 adam Exp $

DISTNAME=	QLandkarteM.0.2.0
PKGNAME=	qlandkartem-0.2.0
PKGREVISION=	53
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qlandkartegt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qlandkarte.org/
COMMENT=	QLandkarteM is a moving map application for mobile devices
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/QLandkarteM
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
QMAKE=		${QTDIR}/bin/qmake

SUBST_CLASSES+=		proj
SUBST_STAGE.proj=	pre-configure
SUBST_FILES.proj=	src/*.cpp
SUBST_FILES.proj+=	src/CMapRaster.h
SUBST_SED.proj=		-e '/^.include .projects.h./s/projects/proj_api/'
SUBST_MESSAGE.proj=	Fixing geography/proj interface

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
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
