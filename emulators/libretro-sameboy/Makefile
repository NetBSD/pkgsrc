# $NetBSD: Makefile,v 1.3 2018/11/18 11:54:10 nia Exp $

DISTNAME=	libretro-sameboy-0.11.2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=LIJI32/}
GITHUB_PROJECT=	SameBoy
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/sameboy/
COMMENT=	Libretro core based on the SameBoy Game Boy/Game Boy Color emulator
LICENSE=	mit

EXTRACT_USING=	bsdtar
BUILD_DIRS=	libretro
USE_TOOLS+=	gmake

BUILD_DEPENDS+=	rgbds-[0-9]*:../../devel/rgbds

MAKE_FLAGS+=	GIT_VERSION="${PKGVERSION}-pkgsrc"

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/bin/sameboy_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro

.include "../../mk/bsd.pkg.mk"
