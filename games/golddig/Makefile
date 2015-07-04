# $NetBSD: Makefile,v 1.16 2015/07/04 16:18:34 joerg Exp $
#

DISTNAME=	golddigC3.1
PKGNAME=	golddig-3.1
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	http://www.NetBSD.org/~chuck/gz/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fast action game designed for use with X

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			MAN=${DESTDIR}${PREFIX}/${PKGMANDIR}/man6

SCORE_GROUP=    ${GAMES_GROUP}
PKG_GROUPS=     ${SCORE_GROUP}

SETGIDGAME=	yes

SPECIAL_PERMS+=	bin/goldgid ${SETGID_GAMES_PERMS}

CONF_FILES_PERMS+=	/dev/null /var/games/golddig.scores \
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}

post-build:
	for f in ${WRKSRC}/golddig.6 ${WRKSRC}/gdedit.6; do \
		${SED} "s|@PREFIX@|${PREFIX}|g" $$f > $$f.new && \
		${MV} $$f.new $$f; \
	done

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
