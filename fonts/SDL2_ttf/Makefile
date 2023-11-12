# $NetBSD: Makefile,v 1.25 2023/11/12 13:21:25 wiz Exp $

DISTNAME=	SDL2_ttf-2.20.2
PKGREVISION=	2
CATEGORIES=	fonts devel
MASTER_SITES=	https://www.libsdl.org/projects/SDL_ttf/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libsdl.org/projects/SDL_ttf/
COMMENT=	Use TrueType fonts in your SDL2 applications
LICENSE=	zlib

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	SDL2_ttf.pc.in

CONFIGURE_ARGS+=	--enable-harfbuzz
CONFIGURE_ARGS+=	--disable-harfbuzz-builtin
CONFIGURE_ARGS+=	--disable-freetype-builtin

CHECK_PORTABILITY_SKIP+=	Xcode/iOS/build-scripts/iosbuild.sh
CHECK_PORTABILITY_SKIP+=	Xcode/tvOS/build-scripts/tvosbuild.sh

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
