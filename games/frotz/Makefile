# $NetBSD: Makefile,v 1.4 2001/05/23 13:35:10 dillo Exp $
#

DISTNAME=	frotz-2.41
CATEGORIES=	games
MASTER_SITES=	http://www.cs.csubak.edu/~dgriffi/frotz/files/
# 2.41 isn't on if-archive yet.
#MASTER_SITES=	ftp://ftp.gmd.de/if-archive/infocom/interpreters/frotz/

MAINTAINER=	seebs@plethora.net
HOMEPAGE=	ftp://ftp.gmd.de/if-archive/infocom/interpreters/frotz/
COMMENT=	Curses-based interpreter for Infocom-compatible games

# uses setscrreg, which is missing from our curses
DEPENDS+=	ncurses>=4.2:../../devel/ncurses

SAMPLEDIR=	${PREFIX}/share/examples/frotz
DOCDIR=		${PREFIX}/share/doc/frotz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/frotz ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/frotz.6 ${PREFIX}/man/man6
	${INSTALL_DATA_DIR} ${SAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/frotz.conf-big ${SAMPLEDIR}/frotz.conf
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README INSTALL HOW_TO_PLAY ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
