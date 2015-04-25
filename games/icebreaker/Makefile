# $NetBSD: Makefile,v 1.31 2015/04/25 14:22:56 tnn Exp $
#

DISTNAME=	icebreaker-1.9.7
PKGREVISION=	12
CATEGORIES=	games
MASTER_SITES=	http://mattdm.org/icebreaker/1.9.x/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mattdm.org/icebreaker/
COMMENT=	Penguin capturing simulation

USE_TOOLS+=	gmake
MAKE_ENV+=	mandir="${PREFIX}/man" highscoredir="/var/games"
MAKE_ENV+=	prefix=${PREFIX:Q}

SETGIDGAME=	yes
SPECIAL_PERMS=	bin/icebreaker ${SETGID_GAMES_PERMS}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/icebreaker
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icebreaker
	cd ${WRKSRC} && ${INSTALL_DATA} *.ibt *.wav *.bmp \
		${DESTDIR}${PREFIX}/share/icebreaker
	${INSTALL_PROGRAM} ${WRKSRC}/icebreaker ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/icebreaker.6 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/icebreaker

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
