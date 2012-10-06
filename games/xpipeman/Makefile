# $NetBSD: Makefile,v 1.20 2012/10/06 11:55:02 asau Exp $
#

DISTNAME=	xpipeman-1.5
PKGREVISION=	4
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SUNSITE:=games/strategy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
# HOMEPAGE=	http://www.spinne.com/x/games/xpipeman/
# domain squatted, page last updated 1999
COMMENT=	Connect the pipes to contain the water flow game for X11

WRKSRC=		${WRKDIR}/xpipeman
USE_IMAKE=	yes

SETGIDGAME=		yes
CONF_FILES_PERMS=	share/xpipeman/xpipescores /var/games/xpipescores \
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
SPECIAL_PERMS=		bin/xpipeman ${SETGID_GAMES_PERMS}
REQD_DIRS_PERMS=	share/xpipeman ${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6 share/xpipeman

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xpipeman ${DESTDIR}${PREFIX}/bin/xpipeman
	${INSTALL_MAN} ${WRKSRC}/xpipeman.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/xpipeman.6
	${INSTALL_DATA} ${WRKSRC}/xpipescores ${DESTDIR}${PREFIX}/share/xpipeman

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
