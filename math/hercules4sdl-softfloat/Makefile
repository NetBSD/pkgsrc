# $NetBSD: Makefile,v 1.3 2024/08/25 06:19:00 wiz Exp $

DISTNAME=	hercules4sdl-softfloat-3.5.0
PKGREVISION=	20220201
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=SDL-Hercules-390/}
GITHUB_PROJECT=	SoftFloat
GITHUB_TAG=	4b0c326008e174610969c92e69178939ed80653d # 1 Feb 2022

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
