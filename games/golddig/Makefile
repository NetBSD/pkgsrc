# $NetBSD: Makefile,v 1.18 2020/05/20 06:09:04 rillig Exp $
#

DISTNAME=	golddigC3.1
PKGNAME=	golddig-3.1
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	http://www.NetBSD.org/~chuck/gz/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fast action game designed for use with X

# badguy.c: In function 'move_badguys':
# badguy.c:321:51: error: array subscript has type 'char' [-Werror=char-subscripts]
#      if((x & 1) == 0 && (y & 1) == 0 && fast_lookup[below].code & STOPBAD) {
#                                                    ^
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			MAN=${DESTDIR}${PREFIX}/${PKGMANDIR}/man6

SCORE_GROUP=	${GAMES_GROUP}
PKG_GROUPS=	${SCORE_GROUP}

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
