# $NetBSD: Makefile,v 1.5 2004/07/25 22:01:15 salo Exp $
#

DISTNAME=	powermanga
PKGNAME=	${DISTNAME}-0.78
CATEGORIES=	games
MASTER_SITES=	http://www.tlk.fr/lesjeux/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://linux.tlk.fr/games/Powermanga/
COMMENT=	Arcade 2D shoot-em-up game

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_X11=	yes
WRKSRC=		${WRKDIR}/powermanga-0.78

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
