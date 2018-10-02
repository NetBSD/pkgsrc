# $NetBSD: Makefile,v 1.2 2018/10/02 21:09:30 nia Exp $

DISTNAME=	libretro-snes9x2010-20180626
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	snes9x2010
GITHUB_TAG=	21e176e8f0595c5577e6c2fb5164f92b8855396e

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/snes9x_2010/
COMMENT=	Libretro core based on the snes9x Super Nintendo emulator
LICENSE=	snes9x-license

MAKE_FILE=	Makefile.libretro
USE_TOOLS+=	gmake

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=libretro/link.T

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/snes9x2010_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/snes9x2010_libretro.so

.include "../../mk/bsd.pkg.mk"
