# $NetBSD: Makefile,v 1.3 2020/05/26 09:45:14 nia Exp $

DISTNAME=	libretro-fuse-20180419
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	fuse-libretro
GITHUB_TAG=	fa6ecc43754be89ec5a156877f04adb8f9cc7a09

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/fuse/
COMMENT=	Libretro core based on the FUSE ZX Spectrum emulator
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
MAKE_FILE=	Makefile.libretro

OPSYSVARS+=	SOEXT
SOEXT.Darwin=	dylib
SOEXT.*=	so
PLIST_SUBST+=	SOEXT=${SOEXT}

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DWORDS_BIGENDIAN -DMSB_FIRST
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-version-script=build/link.T
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-no-undefined

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/fuse_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/fuse_libretro.so

.include "../../mk/bsd.pkg.mk"
