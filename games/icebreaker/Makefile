# $NetBSD: Makefile,v 1.11 2003/12/08 14:41:39 wiz Exp $
#

DISTNAME=	icebreaker-1.9.7
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.mattdm.org/icebreaker/1.9.x/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.mattdm.org/icebreaker/
COMMENT=	Penguin capturing simulation

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_X11=	yes
MAKE_ENV+=	mandir="${PREFIX}/man" highscoredir="/var/games"
MAKE_ENV+=	prefix="${PREFIX}"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/icebreaker
	${INSTALL_DATA_DIR} ${PREFIX}/share/icebreaker
	cd ${WRKSRC} && ${INSTALL_DATA} *.ibt *.wav *.bmp \
		${PREFIX}/share/icebreaker
	${INSTALL_PROGRAM} -g games -m 2755 ${WRKSRC}/icebreaker ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/icebreaker.6 ${PREFIX}/man/man6
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/icebreaker

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../devel/smpeg/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
