# $NetBSD: Makefile,v 1.2 2004/10/03 00:14:47 tv Exp $
#

DISTNAME=	wesnoth-0.8
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wesnoth/}

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://www.wesnoth.org/
COMMENT=	Fantasy turn-based strategy game

HAS_CONFIGURE=	YES
USE_BUILDLINK3=	YES
UNLIMIT_RESOURCES+=	datasize

CONFIGURE_ARGS+=	--prefix=${LOCALBASE}

BUILDLINK_DEPENDS.SDL=	SDL>=1.2.7
BUILDLINK_DEPENDS.SDL_mixer=	SDL_mixer>=1.2.5nb3

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
