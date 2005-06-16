# $NetBSD: Makefile,v 1.20 2005/06/16 06:57:54 jlam Exp $
#

DISTNAME=	icebreaker-1.9.7
PKGREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://www.mattdm.org/icebreaker/1.9.x/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.mattdm.org/icebreaker/
COMMENT=	Penguin capturing simulation

USE_TOOLS+=	gmake
MAKE_ENV+=	mandir="${PREFIX}/man" highscoredir="/var/games"
MAKE_ENV+=	prefix="${PREFIX}"

INSTALLATION_DIRS=	bin man/man6

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/icebreaker
	${INSTALL_DATA_DIR} ${PREFIX}/share/icebreaker
	cd ${WRKSRC} && ${INSTALL_DATA} *.ibt *.wav *.bmp \
		${PREFIX}/share/icebreaker
	${INSTALL_PROGRAM} -g games -m 2755 ${WRKSRC}/icebreaker ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/icebreaker.6 ${PREFIX}/man/man6
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/icebreaker

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
