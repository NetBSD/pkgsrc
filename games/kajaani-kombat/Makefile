# $NetBSD: Makefile,v 1.1.1.1 2005/01/14 22:17:28 wiz Exp $
#

DISTNAME=		kajaani-kombat-0.6
CATEGORIES=		games
MASTER_SITES=		http://kombat.kajaani.net/dl/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://kombat.kajaani.net/
COMMENT=		Rampart-like multiplayer game set in space

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kajaani-kombat ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/kajaani-kombat.6 ${PREFIX}/man/man6
	${INSTALL_DATA_DIR} ${PREFIX}/share/kajaani-kombat
	${INSTALL_DATA} ${WRKSRC}/*.ogg ${PREFIX}/share/kajaani-kombat
	${INSTALL_DATA} ${WRKSRC}/*.png ${PREFIX}/share/kajaani-kombat
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${PREFIX}/share/kajaani-kombat

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
