# $NetBSD: Makefile,v 1.22 2012/10/06 11:55:03 asau Exp $
#

DISTNAME=		xsoldier-0.96
PKGREVISION=		2
CATEGORIES=		games x11
MASTER_SITES=		http://www.interq.or.jp/libra/oohara/xsoldier/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.interq.or.jp/libra/oohara/xsoldier/
COMMENT=		Updated xgalaga type game with awesome graphics

SETGIDGAME=		yes
SPECIAL_PERMS+=		bin/xsoldier ${SETGID_GAMES_PERMS}

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

MAKE_ENV+=		BINOWN=${BINOWN:Q}

CONF_FILES_PERMS=	${PREFIX}/share/xsoldier/xsoldier.score.dist	\
			/var/games/xsoldier				\
			games games 0664

post-patch:
	${TOUCH} ${WRKSRC}/xsoldier.man

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
