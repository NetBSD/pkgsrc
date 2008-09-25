# $NetBSD: Makefile,v 1.30 2008/09/25 14:02:09 wiz Exp $

DISTNAME=	gtkballs-3.1.5
PKGREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://gtkballs.antex.ru/dist/

MAINTAINER=	shattered@users.sourceforge.net
HOMEPAGE=	http://gtkballs.antex.ru/
COMMENT=	GTK+ clone of "Color Lines"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/games
USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes

BUILD_DEFS+=		GAMEDATAMODE
BUILD_DEFS+=		VARBASE

PLIST_SUBST+=	VARBASE=${VARBASE:Q}

CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/gtkballs-scores \
			${GAMEOWN} ${GAMEGRP} ${GAMEDATAMODE}

post-install:
	mv ${PREFIX}/${PKGMANDIR}/man6/gtkballs.6x ${PREFIX}/${PKGMANDIR}/man6/gtkballs.6

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
