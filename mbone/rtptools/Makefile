# $NetBSD: Makefile,v 1.1.1.1 2003/05/07 20:52:44 seb Exp $
#

DISTNAME=		rtptools-1.18
CATEGORIES=		mbone
MASTER_SITES=		http://www.cs.columbia.edu/IRT/software/rtptools/download/

MAINTAINER=		seb@netbsd.org
HOMEPAGE=		http://www.cs.columbia.edu/IRT/software/rtptools/
COMMENT=		tools for processing RTP data

USE_BUILDLINK2=		yes
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
