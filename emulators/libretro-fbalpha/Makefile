# $NetBSD: Makefile,v 1.1 2018/08/17 12:54:48 nia Exp $

DISTNAME=	libretro-fbalpha-0.2.97.42.20180408
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	fbalpha
GITHUB_TAG=	08cf5c6abbda2512d5ef73ef8483b849a34a7603

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/libretro/fbalpha
COMMENT=	Libretro core based on the FB Alpha arcade game emulator
LICENSE=	fbalpha-license AND mame-license

EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake
MAKE_FILE=	makefile.libretro
USE_LANGUAGES=	c c++

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
MAKE_FLAGS+=	ENDIANNESS_DEFINES=-DWORDS_BIGENDIAN
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/fbalpha_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/fbalpha_libretro.so

.include "../../mk/bsd.pkg.mk"
