# $NetBSD: Makefile,v 1.3 2002/02/26 21:28:48 fredb Exp $
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

_FETCH_MESSAGE= \
	${ECHO} '======================================================='; \
	${ECHO} '  To build this package, please request a password on'; \
	${ECHO} '    ${HOMEPAGE},'; \
	${ECHO} '  with which to fetch "${DISTNAME}${EXTRACT_SUFX}" manually.'; \
	${ECHO} '======================================================='

do-fetch:
	@if ${TEST} \! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}; then \
		${_FETCH_MESSAGE}; \
		exit 1; \
	fi

fetch-list-one-pkg:
	@${ECHO} ${_FETCH_MESSAGE:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/simian ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/simian
	${INSTALL_DATA} ${WRKSRC}/../examples/* ${PREFIX}/share/examples/simian

.include "../../mk/bsd.pkg.mk"
