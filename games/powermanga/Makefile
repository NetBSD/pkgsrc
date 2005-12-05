# $NetBSD: Makefile,v 1.13 2005/12/05 23:55:07 rillig Exp $
#

DISTNAME=	powermanga-0.79
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://linux.tlk.fr/games/Powermanga/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://linux.tlk.fr/games/Powermanga/
COMMENT=	Arcade 2D shoot-em-up game

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
MAKE_ENV+=	TOUCH=${TOUCH:Q} WRKSRC=${WRKSRC:Q}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
