# $NetBSD: Makefile,v 1.3 2018/10/02 21:09:29 nia Exp $

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

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=./link.T
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--no-undefined

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/freeintv_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/freeintv_libretro.so

.include "../../mk/bsd.pkg.mk"
