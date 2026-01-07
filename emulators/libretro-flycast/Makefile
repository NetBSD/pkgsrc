# $NetBSD: Makefile,v 1.21 2026/01/07 08:46:52 wiz Exp $

PKGREVISION= 1
.include "../../emulators/flycast/Makefile.common"

PKGNAME=	libretro-${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Libretro core based on the Flycast Sega Dreamcast emulator

CMAKE_CONFIGURE_ARGS+=	-DLIBRETRO=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_BINDIR=lib/libretro

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
