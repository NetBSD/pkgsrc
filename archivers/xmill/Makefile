# $NetBSD: Makefile,v 1.11 2004/03/29 05:14:27 ben Exp $

DISTNAME=		xmill-0.9.1
CATEGORIES=		archivers
MASTER_SITES=		http://www.cs.washington.edu/homes/suciu/XMILL/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Specialized compressor for XML

USE_GNU_TOOLS+=		make
MAKEFILE=		makefile

RESTRICTED=		"Redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xmill
	${INSTALL_DATA} ${WRKSRC}/documentation/COPYRIGHT.txt \
		${WRKSRC}/documentation/LICENSE.txt \
		${WRKSRC}/documentation/MANUAL.txt \
		${WRKSRC}/documentation/README.txt \
		${WRKSRC}/documentation/xmill.ps.gz \
		${WRKSRC}/documentation/xmill-09-doc.txt \
		${PREFIX}/share/doc/xmill
	${INSTALL_PROGRAM} ${WRKSRC}/unix/xcmill \
		${WRKSRC}/unix/xdemill \
		${WRKSRC}/unix/xmillexample \
		${WRKSRC}/unix/xmillinspect \
		${WRKSRC}/unix/xmilltest \
		${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
