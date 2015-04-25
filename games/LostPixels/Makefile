# $NetBSD: Makefile,v 1.13 2015/04/25 14:22:51 tnn Exp $
#

DISTNAME=	LostPixels-0.5.3-source
PKGNAME=	${DISTNAME:S/-source//}
PKGREVISION=	9
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blinkensisters/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.blinkensisters.org/wiki/index.php/Main_Page
COMMENT=	Blinken Sisters - Hunt for the Lost Pixels (80s-style Jump'n'Run)

WRKSRC=		${WRKDIR}/blinkensisters/lostpixels/game/software
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

ALL_ENV+=	SDLDIR=${BUILDLINK_PREFIX.SDL}/include/SDL

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
