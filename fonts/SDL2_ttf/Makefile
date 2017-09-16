# $NetBSD: Makefile,v 1.9 2017/09/16 19:26:56 wiz Exp $

DISTNAME=	SDL2_ttf-2.0.14
CATEGORIES=	devel
MASTER_SITES=	https://www.libsdl.org/projects/SDL_ttf/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_ttf/
COMMENT=	Use TrueType fonts in your SDL2 applications
LICENSE=	zlib

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	SDL2_ttf.pc.in

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
