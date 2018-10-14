# $NetBSD: Makefile,v 1.5 2018/10/14 16:44:21 nia Exp $

DISTNAME=	libretro-gambatte-20181013
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	gambatte-libretro
GITHUB_TAG=	dca7f55d4f50036e9e37ab3c8f6957d0c68db918

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/gambatte/
COMMENT=	Libretro core based on the Gambatte Game Boy Color emulator
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
USE_LANGUAGES=	c c++03
MAKE_FILE=	Makefile.libretro
USE_TOOLS+=	gmake

CFLAGS.SunOS+=	-DBSD_COMP

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-version-script=libgambatte/libretro/link.T

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/gambatte_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/gambatte_libretro.so

.include "../../mk/bsd.pkg.mk"
