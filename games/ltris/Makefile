# $NetBSD: Makefile,v 1.9 2004/03/07 07:19:57 snj Exp $
#

DISTNAME=	ltris-1.0.1
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	SDL tetris clone

USE_BUILDLINK3=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-highscore-path=${LOCALBASE}/share/games/

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
