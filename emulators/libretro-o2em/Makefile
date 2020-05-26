# $NetBSD: Makefile,v 1.4 2020/05/26 09:45:15 nia Exp $

DISTNAME=	libretro-o2em-20180812
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_TAG=	925fc14d818abcbb9665cae4dd995f8b751db46c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/o2em/
COMMENT=	Libretro core for Magnavox Odyssey 2 and VideoPac emulation
LICENSE=	artistic

USE_TOOLS+=	gmake

OPSYSVARS+=	SOEXT
SOEXT.Darwin=	dylib
SOEXT.*=	so
PLIST_SUBST+=	SOEXT=${SOEXT}

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--no-undefined
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=link.T

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/o2em_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/o2em_libretro.so

.include "../../mk/bsd.pkg.mk"
