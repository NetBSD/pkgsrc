# $NetBSD: Makefile,v 1.6 2015/04/25 14:20:48 tnn Exp $

DISTNAME=	SDL2_ttf-2.0.12
PKGREVISION=	2
CATEGORIES=	fonts
MASTER_SITES=	http://www.libsdl.org/projects/SDL_ttf/release/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_ttf/
COMMENT=	Sample library allowing for using TrueType fonts in SDL applications
LICENSE=	zlib

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	SDL2_ttf.pc.in

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
