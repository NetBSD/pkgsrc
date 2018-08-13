# $NetBSD: Makefile,v 1.1 2018/08/13 18:04:15 nia Exp $

DISTNAME=	libretro-prosystem-20180812
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	prosystem-libretro
GITHUB_TAG=	463dfff97f2e7d707ee5ae238cb2e8e70beb585a

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/prosystem/
COMMENT=	Libretro core based on the ProSystem Atari 7800 emulator
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake
MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/prosystem_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/prosystem_libretro.so

.include "../../mk/bsd.pkg.mk"
