# $NetBSD: Makefile,v 1.24 2005/11/05 17:15:52 rillig Exp $

DISTNAME=		xgalaga-2.0.34
PKGREVISION=		2
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		root@garbled.net
COMMENT=		Very fast true-to-the-original port of galaga for X11

NO_SRC_ON_FTP=		"already in MASTER_SITE_LOCAL"

GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${PREFIX}/share/xgalaga
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/bin
SETGIDGAME=		yes
MAKE_ENV+=		GAMEOWN=${GAMEOWN} GAMEGRP=${GAMEGRP} \
			GAMEMODE=${GAMEMODE} GAMEDATAMODE=${GAMEDATAMODE}

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/xgalaga/README

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
