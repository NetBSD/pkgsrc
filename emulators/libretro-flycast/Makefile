# $NetBSD: Makefile,v 1.9 2023/11/08 13:19:06 wiz Exp $

PKGREVISION= 2
.include "../../emulators/flycast/Makefile.common"

PKGNAME=	libretro-${DISTNAME}

MAINTAINER=	nia@NetBSD.org
COMMENT=	Libretro core based on the Flycast Sega Dreamcast emulator

CMAKE_ARGS+=	-DLIBRETRO=ON

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
