# $NetBSD: Makefile,v 1.7 2018/07/26 08:02:24 adam Exp $

DISTNAME=	SDL2_mixer-2.0.2
CATEGORIES=	audio devel
MASTER_SITES=	http://www.libsdl.org/projects/SDL_mixer/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_mixer/
COMMENT=	Sample multi-channel audio mixer library
LICENSE=	zlib

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	SDL2_mixer.pc.in

.include "options.mk"

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
