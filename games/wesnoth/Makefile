# $NetBSD: Makefile,v 1.11 2005/04/19 01:50:59 wiz Exp $
#

DISTNAME=	wesnoth-0.9.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wesnoth/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.wesnoth.org/
COMMENT=	Fantasy turn-based strategy game

HAS_CONFIGURE=	YES
UNLIMIT_RESOURCES+=	datasize

CONFIGURE_ARGS+=	--prefix=${PREFIX}

BUILDLINK_DEPENDS.SDL=	SDL>=1.2.7
BUILDLINK_DEPENDS.SDL_mixer=	SDL_mixer>=1.2.5nb3

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
# configure script in 0.9.0 requests explicitly to
# use included SDL_ttf library
#.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
