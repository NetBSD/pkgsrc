# $NetBSD: Makefile,v 1.2 2001/09/09 20:36:16 agc Exp $
#

DISTNAME=	simian_man_12_98
PKGNAME=	simian-docs-2.1
CATEGORIES=	cad
MASTER_SITES=	http://weewave.mer.utexas.edu/MED_files/MED_research/Intrcncts/SIMIAN_stuff/simian_mnl_ps_pdf/
EXTRACT_SUFX=	.pdf

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://weewave.mer.utexas.edu/MED_files/MED_research/Intrcncts/SIMIAN_stuff/simian_links.html
COMMENT=	PDF manual for SIMIAN

RESTRICTED=		"Personal use only"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/simian
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${PREFIX}/share/doc/simian

.include "../../mk/bsd.pkg.mk"
