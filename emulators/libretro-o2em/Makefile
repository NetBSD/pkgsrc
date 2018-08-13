# $NetBSD: Makefile,v 1.2 2018/08/13 19:48:55 nia Exp $

DISTNAME=	libretro-o2em-20180812
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_TAG=	925fc14d818abcbb9665cae4dd995f8b751db46c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/o2em/
COMMENT=	Libretro core for Magnavox Odyssey 2 and VideoPac emulation
LICENSE=	artistic

EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/o2em_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/o2em_libretro.so

.include "../../mk/bsd.pkg.mk"
