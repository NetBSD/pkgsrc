# $NetBSD: Makefile,v 1.6 2005/01/31 00:26:50 wiz Exp $
#

DISTNAME=	wesnoth-0.8.9
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wesnoth/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.wesnoth.org/
COMMENT=	Fantasy turn-based strategy game

HAS_CONFIGURE=	YES
USE_BUILDLINK3=	YES
UNLIMIT_RESOURCES+=	datasize

CONFIGURE_ARGS+=	--prefix=${PREFIX}

BUILDLINK_DEPENDS.SDL=	SDL>=1.2.7
BUILDLINK_DEPENDS.SDL_mixer=	SDL_mixer>=1.2.5nb3

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
