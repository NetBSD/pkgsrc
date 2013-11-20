# $NetBSD: Makefile,v 1.60 2013/11/20 20:04:39 adam Exp $

DISTNAME=	akonadi-1.10.2
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	ftp://kde.mirror.anlx.net/stable/akonadi/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://pim.kde.org/akonadi/
COMMENT=	The KDE PIM Storage Service
LICENSE=	gnu-lgpl-v2.1

# BUILD_MAKE_FLAGS+= VERBOSE=1

BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4
BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

.include "options.mk"

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_build

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/
	${MKDIR} ${WRKSRC}/_build

PKGCONFIG_OVERRIDE+=	akonadi.pc.cmake

LDFLAGS.SunOS+=		-lsocket

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/soprano/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
