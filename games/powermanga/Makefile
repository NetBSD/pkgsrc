# $NetBSD: Makefile,v 1.6 2004/10/03 00:14:46 tv Exp $
#

DISTNAME=	powermanga
PKGNAME=	${DISTNAME}-0.78
PKGREVISION=	1
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
