# $NetBSD: Makefile,v 1.3 2017/06/24 06:57:36 kamil Exp $
#

DISTNAME=		xlennart-1.1.1
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_GITHUB:=Xylemon/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/Xylemon/xlennart
COMMENT=		Stop the dreaded systend virus from infecting computers
LICENSE=		gnu-gpl-v2

USE_GAMESGROUP=		yes

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
BUILD_DEFS+=		VARBASE

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--disable-motif
CONFIGURE_ARGS+=	--disable-gtk # GTK refuses to start in setuid mode for games
CONFIGURE_ARGS+=	--enable-athena

SPECIAL_PERMS=		bin/xlennart ${SETGID_GAMES_PERMS}
REQD_FILES_PERMS+=	/dev/null ${VARBASE}/games/xlennart.scores ${GAMEDATA_PERMS}

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
