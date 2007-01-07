# $NetBSD: Makefile,v 1.26 2007/01/07 09:13:54 rillig Exp $
#

DISTNAME=	icebreaker-1.9.7
PKGREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://mattdm.org/icebreaker/1.9.x/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://mattdm.org/icebreaker/
COMMENT=	Penguin capturing simulation

USE_TOOLS+=	gmake
MAKE_ENV+=	mandir="${PREFIX}/man" highscoredir="/var/games"
MAKE_ENV+=	prefix=${PREFIX:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/icebreaker
	${INSTALL_DATA_DIR} ${PREFIX}/share/icebreaker
	cd ${WRKSRC} && ${INSTALL_DATA} *.ibt *.wav *.bmp \
		${PREFIX}/share/icebreaker
	${INSTALL_PROGRAM} -g games -m 2755 ${WRKSRC}/icebreaker ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/icebreaker.6 ${PREFIX}/${PKGMANDIR}/man6
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/icebreaker

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
