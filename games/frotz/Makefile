# $NetBSD: Makefile,v 1.5 2001/11/16 21:19:58 jlam Exp $
#

DISTNAME=	frotz-2.41
CATEGORIES=	games
MASTER_SITES=	http://www.cs.csubak.edu/~dgriffi/frotz/files/
MASTER_SITES=	ftp://ftp.ifarchive.org/if-archive/infocom/interpreters/frotz/ \
		ftp://ftp.nodomainname.net/pub/mirrors/if-archive/infocom/interpreters/frotz/ \
		ftp://wuarchive.wustl.edu/doc/misc/if-archive/infocom/interpreters/frotz/ \
		ftp://ftp.ifarchive.org/if-archive/unprocessed/
# 2.41 isn't on if-archive yet.

MAINTAINER=	seebs@plethora.net
HOMEPAGE=	http://www.cs.csubak.edu/~dgriffi/proj/frotz/
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
