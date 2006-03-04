# $NetBSD: Makefile,v 1.16 2006/03/04 21:29:43 jlam Exp $
#

DISTNAME=	powermanga-0.79
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://linux.tlk.fr/games/Powermanga/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linux.tlk.fr/games/Powermanga/
COMMENT=	Arcade 2D shoot-em-up game

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
MAKE_ENV+=	TOUCH=${TOUCH:Q} WRKSRC=${WRKSRC:Q}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
