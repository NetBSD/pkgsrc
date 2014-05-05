# $NetBSD: Makefile,v 1.58 2014/05/05 00:47:52 ryoon Exp $

DISTNAME=	gtkballs-3.1.5
PKGREVISION=	28
CATEGORIES=	games
MASTER_SITES=	http://gtkballs.antex.ru/dist/

MAINTAINER=	shattered@NetBSD.org
HOMEPAGE=	http://gtkballs.antex.ru/
COMMENT=	GTK+ clone of "Color Lines"
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/games
USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes

BUILD_DEFS+=		GAMEDATAMODE
BUILD_DEFS+=		VARBASE

PLIST_SUBST+=		VARBASE=${VARBASE}

USE_GAMESGROUP=		yes
SPECIAL_PERMS+=		bin/gtkballs ${SETGID_GAMES_PERMS}

CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/gtkballs-scores \
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}

post-install:
	mv ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/gtkballs.6x ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/gtkballs.6

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
