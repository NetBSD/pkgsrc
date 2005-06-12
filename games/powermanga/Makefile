# $NetBSD: Makefile,v 1.11 2005/06/12 08:41:56 hira Exp $
#

DISTNAME=	powermanga-0.79
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://linux.tlk.fr/games/Powermanga/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://linux.tlk.fr/games/Powermanga/
COMMENT=	Arcade 2D shoot-em-up game

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
MAKE_ENV+=	TOUCH=${TOUCH} WRKSRC=${WRKSRC}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
