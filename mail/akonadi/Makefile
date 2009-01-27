# $NetBSD: Makefile,v 1.5 2009/01/27 10:47:19 markd Exp $

DISTNAME=	akonadi-1.1.1
CATEGORIES=	mail
MASTER_SITES=	http://download.akonadi-project.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://pim.kde.org/akonadi/
COMMENT=	The KDE PIM Storage Service

PKG_DESTDIR_SUPPORT=	user-destdir

# BUILD_MAKE_FLAGS+= VERBOSE=1

BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4
BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

USE_DIRS+=	kde4-1.0
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_build

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/
	${MKDIR} ${WRKSRC}/_build

PKGCONFIG_OVERRIDE+=	akonadi.pc.cmake

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
