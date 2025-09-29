# $NetBSD: Makefile,v 1.1 2025/09/29 14:06:04 nia Exp $

DISTNAME=	amoebax-0.2.1
CATEGORIES=	games
MASTER_SITES=	https://www.emma-soft.com/games/amoebax/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.emma-soft.com/games/amoebax/
COMMENT=	Action puzzle game like Puyo Puyoo
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

CXXFLAGS+=	-std=gnu++98 -fpermissive

CONFIGURE_ARGS+=	--with-sdl-prefix=${BUILDLINK_PREFIX.SDL}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
