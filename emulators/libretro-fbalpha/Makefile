# $NetBSD: Makefile,v 1.5 2018/11/13 17:16:25 nia Exp $

DISTNAME=	libretro-fbalpha-0.2.97.43.20181022
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	fbalpha2018
GITHUB_TAG=	20daa807957d7fce64371620271b502811318163

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

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-no-undefined
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=src/burner/libretro/link.T

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/fbalpha_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/fbalpha_libretro.so

.include "../../mk/bsd.pkg.mk"
