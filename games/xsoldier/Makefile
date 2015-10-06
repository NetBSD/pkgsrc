# $NetBSD: Makefile,v 1.23 2015/10/06 22:10:02 leot Exp $

DISTNAME=		xsoldier-1.8
CATEGORIES=		games x11
MASTER_SITES=		http://www.interq.or.jp/libra/oohara/xsoldier/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.interq.or.jp/libra/oohara/xsoldier/
COMMENT=		Updated xgalaga type game with awesome graphics
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_GAMESGROUP=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

BUILD_DEFS+=		VARBASE

OWN_DIRS_PERMS+=	${VARBASE}/games/xsoldier ${GAMEDIR_PERMS}
REQD_FILES_PERMS+=	${WRKSRC}/scorefile.txt \
			${VARBASE}/games/xsoldier/xsoldier.scores ${GAMEDATA_PERMS}
SPECIAL_PERMS+=		${PREFIX}/bin/xsoldier ${SETGID_GAMES_PERMS}

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
