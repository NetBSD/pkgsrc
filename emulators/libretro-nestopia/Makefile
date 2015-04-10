# $NetBSD: Makefile,v 1.1 2015/04/10 03:16:17 snj Exp $

DISTNAME=	2c586b592597751f015ac30e05d2a180a1ffd723
PKGNAME=	libretro-nestopia-20150319
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/nestopia/archive/}
EXTRACT_SUFX=	.zip

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	https://github.com/libretro/nestopia
COMMENT=	Libretro core based on the Nestopia UE emulator
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/nestopia-${DISTNAME}
BUILD_DIRS=	libretro
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro
INSTALLATION_DIRS+=	share/libretro-nestopia

CFLAGS+=	-DPREFIX=\"${PREFIX}\"

do-install:
	${INSTALL_LIB} ${WRKSRC}/libretro/nestopia_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/nestopia_libretro.so
	${INSTALL_DATA} ${WRKSRC}/NstDatabase.xml \
	    ${DESTDIR}${PREFIX}/share/libretro-nestopia

.include "../../mk/bsd.pkg.mk"
