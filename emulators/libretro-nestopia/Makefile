# $NetBSD: Makefile,v 1.6 2020/01/04 12:29:45 nia Exp $

.include "../../emulators/nestopia/Makefile.common"

PKGNAME=	libretro-${DISTNAME}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/nestopia_ue/
COMMENT=	Libretro core based on the Nestopia UE emulator

BUILD_DIRS=	libretro

USE_TOOLS+=	gmake

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-version-script=link.T
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-no-undefined

INSTALLATION_DIRS+=	lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/libretro/nestopia_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/nestopia_libretro.so

.include "../../mk/bsd.pkg.mk"
