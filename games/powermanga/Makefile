# $NetBSD: Makefile,v 1.7 2005/01/30 23:48:32 salo Exp $
#

DISTNAME=	powermanga-0.79
CATEGORIES=	games
MASTER_SITES=	http://linux.tlk.fr/games/Powermanga/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://linux.tlk.fr/games/Powermanga/
COMMENT=	Arcade 2D shoot-em-up game

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_X11=	yes

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
MAKE_ENV+=	TOUCH=${TOUCH}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
