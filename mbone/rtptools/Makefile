# $NetBSD: Makefile,v 1.5 2005/04/11 21:46:32 tv Exp $
#

DISTNAME=		rtptools-1.18
CATEGORIES=		mbone
MASTER_SITES=		http://www.cs.columbia.edu/IRT/software/rtptools/download/

MAINTAINER=		seb@NetBSD.org
HOMEPAGE=		http://www.cs.columbia.edu/IRT/software/rtptools/
COMMENT=		Tools for processing RTP data

GNU_CONFIGURE=		yes
CPPFLAGS+=		-Dunix

HTMLDIR=	${PREFIX}/share/doc/html/rtptools
EGDIR=		${PREFIX}/share/examples/rtptools

post-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/rtptools.html ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog.html ${HTMLDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/multidump ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/multiplay ${EGDIR}

.include "../../mk/bsd.pkg.mk"
