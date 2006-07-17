# $NetBSD: Makefile,v 1.25 2006/07/17 18:37:45 wiz Exp $

DISTNAME=	gtkballs-3.1.5
PKGREVISION=	4
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

PLIST_SUBST+=	VARBASE=${VARBASE:Q}

CONF_FILES_PERMS+=	/dev/null ${PREFIX}/${GAMES_DIR}/gtkballs-scores \
			${ROOT_USER} games 664

post-install:
	${MV} ${PREFIX}/${PKGMANDIR}/man6/gtkballs.6x ${PREFIX}/${PKGMANDIR}/man6/gtkballs.6

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
