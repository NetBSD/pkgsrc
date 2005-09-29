# $NetBSD: Makefile,v 1.13 2005/09/29 15:04:21 wiz Exp $
#

DISTNAME=	simian_12_98
PKGNAME=	simian-2.1
CATEGORIES=	cad
MASTER_SITES=	http://weewave.mer.utexas.edu/MED_files/CODE_RQST/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://weewave.mer.utexas.edu/MED_files/MED_research/Intrcncts/SIMIAN_stuff/simian_links.html
COMMENT=	2-dimensional interconnect and transmission line simulator

LICENSE=		simian-license
RESTRICTED=		Redistribution for personal use only.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

USE_LANGUAGES=		c++
GCC_REQD=		3.0

WRKSRC=		${WRKDIR}/Simian/src

BUILD_TARGET=	simian

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/simian ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/simian
	${INSTALL_DATA} ${WRKSRC}/../examples/* ${PREFIX}/share/examples/simian

.include "../../mk/bsd.pkg.mk"
