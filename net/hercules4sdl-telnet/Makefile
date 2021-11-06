# $NetBSD: Makefile,v 1.1 2021/11/06 16:42:10 rhialto Exp $

DISTNAME=	hercules4sdl-telnet-1.0.0
PKGREVISION=	20210105
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=SDL-Hercules-390/}
GITHUB_PROJECT=	telnet
GITHUB_TAG=	2aca101e06ca84526c1a63c0f65e05fe11522c3b # 5 Jan 2021

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/SDL-Hercules-390/telnet
COMMENT=	The SoftDevLabs version of telnet library for Hercules 4.x
LICENSE=	public-domain

USE_TOOLS+=	cmake
USE_LANGUAGES+=	c

USE_CMAKE=	yes
BLDDIR=		${WRKDIR}/telnet64.Release
CONFIGURE_DIRS=	${BLDDIR}
CMAKE_ARG_PATH=	${WRKSRC}
CMAKE_ARGS+=	-D INSTALL_PREFIX=${PREFIX}/lib/hercules4sdl

pre-configure:
	${MKDIR} ${BLDDIR}

post-install:
	cd ${DESTDIR}${PREFIX}/lib/hercules4sdl/lib && ${MV} libtelnet64.a libtelnet_pic.a

.include "../../mk/bsd.pkg.mk"
