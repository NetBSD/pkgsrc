# $NetBSD: Makefile,v 1.7 2023/07/02 17:32:30 nia Exp $

.include "../../emulators/flycast/Makefile.common"

PKGNAME=	libretro-${DISTNAME}

MAINTAINER=	nia@NetBSD.org
COMMENT=	Libretro core based on the Flycast Sega Dreamcast emulator

CMAKE_ARGS+=	-DLIBRETRO=ON

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
