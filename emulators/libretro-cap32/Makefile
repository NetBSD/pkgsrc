# $NetBSD: Makefile,v 1.1 2018/10/13 17:58:08 nia Exp $

DISTNAME=	libretro-cap32-20180827
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_TAG=	ac8608b149e96b5b48ad07909edfb423481f365a

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/caprice32/
COMMENT=	Libretro core based on the Caprice32 Amstrad CPC emulator
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-version-script=link.T
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-no-undefined

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/cap32_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/cap32_libretro.so

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
