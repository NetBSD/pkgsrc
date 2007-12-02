# $NetBSD: Makefile,v 1.22 2007/12/02 00:00:20 wiz Exp $

DISTNAME=	frotz-2.43
PKGREVISION=	2
CATEGORIES=	games
# The maintainer has asked us to use the mirrors instead of www.cs.csubak.edu.
#MASTER_SITES=	http://www.cs.csubak.edu/~dgriffi/frotz/files/
MASTER_SITES=	ftp://ftp.ifarchive.org/if-archive/infocom/interpreters/frotz/

MAINTAINER=	seebs@plethora.net
HOMEPAGE=	http://www.cs.csubak.edu/~dgriffi/proj/frotz/
COMMENT=	Curses-based interpreter for Infocom-compatible games


# setscrreg()
INCOMPAT_CURSES=	NetBSD-1.5-* NetBSD-1.5.*-* NetBSD-1.5[A-V]-*

SAMPLEDIR=	${PREFIX}/share/examples/frotz
DOCDIR=		${PREFIX}/share/doc/frotz

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/frotz ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/frotz.6 ${PREFIX}/${PKGMANDIR}/man6
	${INSTALL_DATA_DIR} ${SAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/frotz.conf-big ${SAMPLEDIR}/frotz.conf
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README INSTALL HOW_TO_PLAY ${DOCDIR}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
