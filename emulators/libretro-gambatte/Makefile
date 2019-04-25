# $NetBSD: Makefile,v 1.7 2019/04/25 13:50:19 nia Exp $

DISTNAME=	libretro-gambatte-20190412
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	gambatte-libretro
GITHUB_TAG=	7d4beec1ff69098a602c12d38a76465510cb8ebc

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
