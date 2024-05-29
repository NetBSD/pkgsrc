# $NetBSD: Makefile,v 1.26 2024/05/29 16:31:26 adam Exp $

DISTNAME=	Molsketch-0.8.1-src
PKGNAME=	${DISTNAME:S/-src//:tl}
PKGREVISION=	3
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=molsketch/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	http://molsketch.sourceforge.net/
COMMENT=	Program for drawing molecular structures
LICENSE=	gnu-gpl-v2

USE_TOOLS=	pkg-config

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
USE_LANGUAGES=	c c++

# std::transform_reduce
USE_CXX_FEATURES+=	parallelism_ts

CMAKE_ARGS+=	-DMSK_QT6=true
CMAKE_ARGS+=	-DMSK_PREFIX=${PREFIX:Q}
CMAKE_ARGS+=	-DMSK_INSTALL_PREFIX=${PREFIX:Q}
CMAKE_ARGS+=	-DMSK_INSTALL_DOCS=/share/doc/molsketch
CMAKE_ARGS+=	-DMSK_INSTALL_LIBS64=/lib
CMAKE_ARGS+=	-DMSK_INSTALL_LIBS=/lib
CMAKE_ARGS+=	-DMSK_INSTALL_INCLUDES=/include

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/include/libmolsketch/molsketch_LIB_autogen
	${RM} -rf ${DESTDIR}${PREFIX}/include/libmolsketch/CMakeFiles

TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../biology/openbabel/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
