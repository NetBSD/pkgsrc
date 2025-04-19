# $NetBSD: Makefile,v 1.4 2025/04/19 12:54:00 rhialto Exp $

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

pre-configure:
	${MKDIR} ${BLDDIR}

post-install:
	cd ${DESTDIR}${PREFIX}/lib/hercules4sdl/lib && ${MV} libSoftFloat64.a libSoftFloat_pic.a

.include "../../mk/bsd.pkg.mk"
