# $NetBSD: Makefile,v 1.1 2018/08/12 15:32:10 nia Exp $

DISTNAME=	libretro-snes9x-1.56.2
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
USE_LANGUAGES=	c c++

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/libretro/snes9x_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/snes9x_libretro.so

.include "../../mk/bsd.pkg.mk"
