# $NetBSD: Makefile,v 1.3 2024/08/25 06:19:11 wiz Exp $

DISTNAME=	hercules4sdl-crypto-1.0.0
PKGREVISION=	20220201
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=SDL-Hercules-390/}
GITHUB_PROJECT=	crypto
GITHUB_TAG=	a5096e5dd79f46b568806240c0824cd8cb2fcda2 # 1 Feb 2022

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/SDL-Hercules-390/crypto
COMMENT=	The SoftDevLabs version of crypto for Hercules 4.x
LICENSE=	modified-bsd # some parts are less restricted

USE_TOOLS+=	cmake
USE_LANGUAGES+=	c

USE_CMAKE=	yes
BLDDIR=		${WRKDIR}/crypto64.Release
CONFIGURE_DIRS=	${BLDDIR}
CMAKE_ARG_PATH=	${WRKSRC}
CMAKE_CONFIGURE_ARGS+=	-D INSTALL_PREFIX=${PREFIX}/lib/hercules4sdl

pre-configure:
	${MKDIR} ${BLDDIR}

post-install:
	cd ${DESTDIR}${PREFIX}/lib/hercules4sdl/lib && ${MV} libcrypto64.a libcrypto_pic.a

.include "../../mk/bsd.pkg.mk"
