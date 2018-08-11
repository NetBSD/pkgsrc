# $NetBSD: Makefile,v 1.1 2018/08/11 15:42:09 nia Exp $

DISTNAME=	libretro-fuse-20180419
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	fuse-libretro
GITHUB_TAG=	fa6ecc43754be89ec5a156877f04adb8f9cc7a09

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/fuse/
COMMENT=	Libretro core based on the FUSE ZX Spectrum emulator
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake
MAKE_FILE=	Makefile.libretro

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DWORDS_BIGENDIAN -DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/fuse_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/fuse_libretro.so

.include "../../mk/bsd.pkg.mk"
