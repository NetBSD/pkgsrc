# $NetBSD: Makefile,v 1.8 2005/03/27 15:43:36 wiz Exp $
#

DISTNAME=	powermanga-0.79
PKGREVISION=	1
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
