# $NetBSD: Makefile,v 1.7 2001/12/25 17:30:39 wiz Exp $
#

DISTNAME=	frotz-2.41
CATEGORIES=	games
# The maintainer has asked us to use the mirrors instead of www.cs.csubak.edu.
#MASTER_SITES=	http://www.cs.csubak.edu/~dgriffi/frotz/files/
MASTER_SITES=	ftp://ftp.ifarchive.org/if-archive/infocom/interpreters/frotz/ \
		ftp://ftp.nodomainname.net/pub/mirrors/if-archive/infocom/interpreters/frotz/ \
		ftp://wuarchive.wustl.edu/doc/misc/if-archive/infocom/interpreters/frotz/ \
		ftp://ftp.ifarchive.org/if-archive/unprocessed/

MAINTAINER=	seebs@plethora.net
HOMEPAGE=	http://www.cs.csubak.edu/~dgriffi/proj/frotz/
COMMENT=	Curses-based interpreter for Infocom-compatible games

USE_BUILDLINK_ONLY=	yes

# setscrreg()
INCOMPAT_CURSES=	1.5 1.5.* 1.5[A-V]

SAMPLEDIR=	${PREFIX}/share/examples/frotz
DOCDIR=		${PREFIX}/share/doc/frotz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/frotz ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/frotz.6 ${PREFIX}/man/man6
	${INSTALL_DATA_DIR} ${SAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/frotz.conf-big ${SAMPLEDIR}/frotz.conf
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README INSTALL HOW_TO_PLAY ${DOCDIR}

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
