# $NetBSD: Makefile,v 1.8 2023/10/24 22:09:04 wiz Exp $

PKGREVISION= 1
.include "../../emulators/flycast/Makefile.common"

PKGNAME=	libretro-${DISTNAME}

MAINTAINER=	nia@NetBSD.org
COMMENT=	Libretro core based on the Flycast Sega Dreamcast emulator

CMAKE_ARGS+=	-DLIBRETRO=ON

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
