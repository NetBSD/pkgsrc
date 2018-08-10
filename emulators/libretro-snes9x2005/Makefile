# $NetBSD: Makefile,v 1.2 2018/08/10 20:34:01 nia Exp $

DISTNAME=	libretro-snes9x2005-20180626
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	snes9x2005
GITHUB_TAG=	4423de5973de2e1a243031ee59d997f5e6220a6c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/snes9x_2005/
COMMENT=	Libretro core based on the snes9x Super Nintendo emulator
LICENSE=	snes9x-license

USE_TOOLS+=	gmake

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/snes9x2005_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/snes9x2005_libretro.so

.include "../../mk/bsd.pkg.mk"
