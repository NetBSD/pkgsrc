# $NetBSD: Makefile,v 1.14 2020/06/02 08:23:46 adam Exp $

DISTNAME=	mgba-0.8.1
PKGREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=mgba-emu/}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://mgba.io/
COMMENT=	Emulator for running Game Boy Advance games
LICENSE=	mpl-2.0

EXTRACT_USING=	bsdtar
USE_TOOLS+=	pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

# using libzip
CMAKE_ARGS+=	-DUSE_MINIZIP=OFF

.include "options.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libelf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
