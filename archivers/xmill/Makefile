# $NetBSD: Makefile,v 1.1.1.1 2003/02/17 09:20:25 grant Exp $

DISTNAME=		xmill-0-7
PKGNAME=		xmill-0.7
CATEGORIES=		archivers
MASTER_SITES=		# empty
EXTRACT_SUFX=		.zip

MAINTAINER=		collver1@attbi.com
HOMEPAGE=		http://www.research.att.com/sw/tools/xmill/
COMMENT=		Specialized compressor for XML

BUILD_DEPENDS=		unzip-[0-9]*:../../archivers/unzip

EXTRACT_CMD=		unzip -aq ${DOWNLOADED_DISTFILE}

MAKEFILE=		makefile

WRKSRC=			${WRKDIR}

RESTRICTED=		"Redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

DOWNLOAD=		http://www.research.att.com/sw/tools/xmill/download.html
#DOWNLOAD=		http://www.research.att.com/~mff/XMILL/xmill-0-7.zip

_FETCH_MESSAGE= \
	    ${ECHO} "==============================================================="; \
	    ${ECHO} "  XMILL distribution package must be fetched"; \
	    ${ECHO} "  into ${DISTDIR} from"; \
	    ${ECHO} "  ${DOWNLOAD}"; \
	    ${ECHO} "==============================================================="

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xmill
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT.txt ${PREFIX}/share/doc/xmill
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${PREFIX}/share/doc/xmill
	${INSTALL_DATA} ${WRKSRC}/MANUAL.txt ${PREFIX}/share/doc/xmill
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/xmill
	${INSTALL_DATA} ${WRKSRC}/paper/xmill.ps.gz ${PREFIX}/share/doc/xmill
	${INSTALL_PROGRAM} ${WRKSRC}/unix/xmill ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unix/xdemill ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unix/xbmill ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/unix/xbdemill ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
