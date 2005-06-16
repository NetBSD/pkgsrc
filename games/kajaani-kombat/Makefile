# $NetBSD: Makefile,v 1.5 2005/06/16 06:57:54 jlam Exp $
#

DISTNAME=		kajaani-kombat-0.6
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://kombat.kajaani.net/dl/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://kombat.kajaani.net/
COMMENT=		Rampart-like multiplayer game set in space

USE_TOOLS+=		gmake
INSTALLATION_DIRS=	bin man/man6

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
