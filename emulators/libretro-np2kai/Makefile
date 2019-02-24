# $NetBSD: Makefile,v 1.2 2019/02/24 15:26:50 nia Exp $

NP2KAI_REV=	18
DISTNAME=	libretro-np2kai-0.86.${NP2KAI_REV}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=AZO234/}
GITHUB_PROJECT=	NP2kai
GITHUB_TAG=	rev.${NP2KAI_REV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/neko_project_ii_kai/
COMMENT=	Libretro core based on the Neko Project II PC-9801 emulator
LICENSE=	mit

EXTRACT_USING=	bsdtar
BUILD_DIRS=	sdl2
MAKE_FILE=	Makefile.libretro

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.include "../../mk/bsd.prefs.mk"

# The networking code currently uses non-portable Linux-specific calls.
.if ${OPSYS} != "Linux"
MAKE_FLAGS=	SUPPORT_NET=0
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/sdl2/np2kai_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/np2kai_libretro.so

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
