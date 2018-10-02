# $NetBSD: Makefile,v 1.3 2018/10/02 21:09:29 nia Exp $

DISTNAME=	libretro-fbalpha-0.2.97.43.20180721
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	fbalpha
GITHUB_TAG=	6f85b5d19085f91c8f3df5c53dd235c037782fee

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
