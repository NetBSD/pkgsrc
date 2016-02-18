# $NetBSD: Makefile,v 1.50 2016/02/18 20:53:38 jperkin Exp $

DISTNAME=	phonon-4.8.3
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_KDE:=phonon/4.8.3/src/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://phonon.kde.org/
COMMENT=	Multimedia API for KDE and QT
LICENSE=	gnu-lgpl-v2.1

# BUILD_MAKE_FLAGS+= VERBOSE=1

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_build
CMAKE_ARGS+=	-DPHONON_INSTALL_QT_EXTENSIONS_INTO_SYSTEM_QT:BOOL=TRUE

.include "options.mk"

PKGCONFIG_OVERRIDE+=	phonon.pc.cmake

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/
	${MKDIR} ${WRKSRC}/_build

.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
