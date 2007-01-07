# $NetBSD: Makefile,v 1.13 2007/01/07 09:13:54 rillig Exp $
#

DISTNAME=		kajaani-kombat-0.7
CATEGORIES=		games
MASTER_SITES=		http://kombat.kajaani.net/dl/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kombat.kajaani.net/
COMMENT=		Rampart-like multiplayer game set in space

USE_LANGUAGES=		c++
USE_TOOLS+=		gmake
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kajaani-kombat ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/kajaani-kombat.6 ${PREFIX}/${PKGMANDIR}/man6
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
