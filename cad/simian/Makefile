# $NetBSD: Makefile,v 1.2 2001/12/07 21:02:18 jmc Exp $
#

DISTNAME=	simian_12_98
PKGNAME=	simian-2.1
CATEGORIES=	cad
MASTER_SITES=	http://weewave.mer.utexas.edu/MED_files/CODE_RQST/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://weewave.mer.utexas.edu/MED_files/MED_research/Intrcncts/SIMIAN_stuff/simian_links.html
COMMENT=	2-dimensional interconnect and transmission line simulator

LICENSE=		no-redistribution
RESTRICTED=		"Personal use only"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

WRKSRC=		${WRKDIR}/Simian/src
ALL_TARGET=	simian

do-fetch:
	@if ${TEST} \! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}; then \
		${ECHO} "===> You need to request a password on ${HOMEPAGE}"; \
		${ECHO} "     and fetch on your own source file."; \
		exit 1; \
	fi

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/simian ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/simian
	${INSTALL_DATA} ${WRKSRC}/../examples/* ${PREFIX}/share/examples/simian

.include "../../mk/bsd.pkg.mk"
