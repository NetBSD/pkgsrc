# $NetBSD: Makefile,v 1.9 2026/01/05 21:32:30 ktnb Exp $

DISTNAME=	flatzebra-0.2.0
CATEGORIES=	devel
MASTER_SITES=	http://gvlsywt.cluster051.hosting.ovh.net/dev/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gvlsywt.cluster051.hosting.ovh.net/dev/burgerspace.html
COMMENT=	Generic game engine for 2D double-buffering animation
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

# Fails with C++14 default language
FORCE_CXX_STD=	c++03

CONFIGURE_ARGS+=	--disable-sdltest

PKGCONFIG_OVERRIDE+=	flatzebra-0.2.pc.in

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/SDL2_gfx/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
