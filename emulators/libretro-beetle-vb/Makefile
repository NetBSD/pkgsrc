# $NetBSD: Makefile,v 1.2 2018/10/02 21:09:29 nia Exp $

DISTNAME=	libretro-beetle-vb-20180620
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	beetle-vb-libretro
GITHUB_TAG=	cc11960675aaef4bb9c8e50b8ada6c81d9044d96

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/beetle_vb/
COMMENT=	Libretro core based on the Mednafen VirtualBoy emulator
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=link.T
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--no-undefined

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_vb_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_vb_libretro.so

.include "../../mk/bsd.pkg.mk"
