# $NetBSD: Makefile,v 1.3 2024/08/25 06:19:06 wiz Exp $

DISTNAME=	hercules4sdl-telnet-1.0.0
PKGREVISION=	20220201
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=SDL-Hercules-390/}
GITHUB_PROJECT=	telnet
GITHUB_TAG=	e0e2a9150cb0c7cea8b27ea126e1367b3f03b17e # 1 Feb 2022

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
CMAKE_CONFIGURE_ARGS+=	-D INSTALL_PREFIX=${PREFIX}/lib/hercules4sdl

pre-configure:
	${MKDIR} ${BLDDIR}

post-install:
	cd ${DESTDIR}${PREFIX}/lib/hercules4sdl/lib && ${MV} libtelnet64.a libtelnet_pic.a

.include "../../mk/bsd.pkg.mk"
