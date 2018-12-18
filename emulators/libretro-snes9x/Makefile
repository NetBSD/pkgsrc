# $NetBSD: Makefile,v 1.3 2018/12/18 00:56:54 nia Exp $

DISTNAME=	libretro-snes9x-1.58
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=snes9xgit/}
GITHUB_PROJECT=	snes9x

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/snes9x/
COMMENT=	Libretro core based on the snes9x Super Nintendo emulator
LICENSE=	snes9x-license

EXTRACT_USING=	bsdtar

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}
BUILD_DIRS=	libretro

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++11

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"
MAKE_FLAGS+=	LTO=

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/libretro/snes9x_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/snes9x_libretro.so

.include "../../mk/bsd.pkg.mk"
