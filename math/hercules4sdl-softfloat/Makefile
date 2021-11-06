# $NetBSD: Makefile,v 1.1 2021/11/06 16:40:06 rhialto Exp $

DISTNAME=	hercules4sdl-softfloat-3.5.0
PKGREVISION=	20210105
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=SDL-Hercules-390/}
GITHUB_PROJECT=	SoftFloat
GITHUB_TAG=	42f2f99a479a724de5b601a0551e46678a5e3c57 # 5 Jan 2021

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
CMAKE_ARGS+=	-D INSTALL_PREFIX=${PREFIX}/lib/hercules4sdl

pre-configure:
	${MKDIR} ${BLDDIR}

post-install:
	cd ${DESTDIR}${PREFIX}/lib/hercules4sdl/lib && ${MV} libSoftFloat64.a libSoftFloat_pic.a

.include "../../mk/bsd.pkg.mk"
