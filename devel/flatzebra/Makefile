# $NetBSD: Makefile,v 1.6 2023/08/02 19:30:56 nia Exp $

DISTNAME=	flatzebra-0.1.7
CATEGORIES=	devel
MASTER_SITES=	http://perso.b2b2c.ca/~sarrazip/dev/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://perso.b2b2c.ca/~sarrazip/dev/burgerspace.html
COMMENT=	Generic game engine for 2D double-buffering animation
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

# Fails with C++14 default language
FORCE_CXX_STD=	c++03

CONFIGURE_ARGS+=	--disable-sdltest

PKGCONFIG_OVERRIDE+=	flatzebra-0.1.pc.in

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
