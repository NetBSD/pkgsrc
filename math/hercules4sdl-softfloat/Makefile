# $NetBSD: Makefile,v 1.5 2025/08/20 11:35:05 wiz Exp $

DISTNAME=	hercules4sdl-softfloat-3.5.0
PKGREVISION=	20250325
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=SDL-Hercules-390/}
GITHUB_PROJECT=	SoftFloat
GITHUB_TAG=	e053494d988ec0648c92f683abce52597bfae745 # 25 Mar 2025

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/SDL-Hercules-390/SoftFloat
COMMENT=	The SoftDevLabs version of SoftFloat for Hercules 4.x
LICENSE=	modified-bsd

USE_TOOLS+=	cmake
USE_LANGUAGES+=	c

USE_CMAKE=	yes
BLDDIR=		${WRKDIR}/SoftFloat64.Release
CONFIGURE_DIRS=	${BLDDIR}
CMAKE_ARG_PATH=	${WRKSRC}
CMAKE_CONFIGURE_ARGS+=	-D INSTALL_PREFIX=${PREFIX}/lib/hercules4sdl
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

pre-configure:
	${MKDIR} ${BLDDIR}

post-install:
	cd ${DESTDIR}${PREFIX}/lib/hercules4sdl/lib && ${MV} libSoftFloat64.a libSoftFloat_pic.a

.include "../../mk/bsd.pkg.mk"
