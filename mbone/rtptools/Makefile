# $NetBSD: Makefile,v 1.4 2004/04/11 09:09:30 snj Exp $
#

DISTNAME=		rtptools-1.18
CATEGORIES=		mbone
MASTER_SITES=		http://www.cs.columbia.edu/IRT/software/rtptools/download/

MAINTAINER=		seb@NetBSD.org
HOMEPAGE=		http://www.cs.columbia.edu/IRT/software/rtptools/
COMMENT=		Tools for processing RTP data

USE_BUILDLINK3=		yes
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
