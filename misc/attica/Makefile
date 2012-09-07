# $NetBSD: Makefile,v 1.15 2012/09/07 19:17:06 adam Exp $

DISTNAME=	attica-0.2.0
PKGREVISION=	8
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_KDE:=attica/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://projects.kde.org/projects/kdesupport/attica
COMMENT=	Qt library that implements the Open Collaboration Services API
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

# BUILD_MAKE_FLAGS+= VERBOSE=1

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_build

PKGCONFIG_OVERRIDE+=	lib/cmake/libattica.pc.cmake

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/
	${MKDIR} ${WRKSRC}/_build

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
