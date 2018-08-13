# $NetBSD: Makefile,v 1.2 2018/08/13 00:58:12 nia Exp $

DISTNAME=	libretro-freeintv-20180729
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	FreeIntv
GITHUB_TAG=	f20a0a5da15479dc4f223750a616812958597417

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/freeintv/
COMMENT=	Libretro core for Mattel Intellivision emulation
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DWORDS_BIGENDIAN -DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/freeintv_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/freeintv_libretro.so

.include "../../mk/bsd.pkg.mk"
