# $NetBSD: Makefile,v 1.34 2010/01/29 23:10:53 joerg Exp $

DISTNAME=	gtkballs-3.1.5
PKGREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://gtkballs.antex.ru/dist/

MAINTAINER=	shattered@NetBSD.org
HOMEPAGE=	http://gtkballs.antex.ru/
COMMENT=	GTK+ clone of "Color Lines"

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/games
USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes

BUILD_DEFS+=		GAMEDATAMODE
BUILD_DEFS+=		VARBASE

PLIST_SUBST+=	VARBASE=${VARBASE}

CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/gtkballs-scores \
			${GAMEOWN} ${GAMEGRP} ${GAMEDATAMODE}

post-install:
	mv ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/gtkballs.6x ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/gtkballs.6

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
