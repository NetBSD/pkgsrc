# $NetBSD: Makefile,v 1.1.1.1 2001/11/15 02:58:50 dmcmahill Exp $
#

DISTNAME=	gnucap-0.30
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GNU:=gnucap/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.geda.seul.org/tools/acs/index.html
COMMENT=	general purpose circuit simulator

USE_GMAKE=	YES

do-build:
	cd ${WRKSRC}/modelgen && ${MAKE_PROGRAM} ${LOWER_OPSYS}
	cd ${WRKSRC}/src && ${MAKE_PROGRAM} ${LOWER_OPSYS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/*/gnucap ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gnucap
	${INSTALL_DATA} ${WRKSRC}/doc/acs-tutorial ${PREFIX}/share/doc/gnucap
	${INSTALL_DATA} ${WRKSRC}/man/man.pdf ${PREFIX}/share/doc/gnucap
	${INSTALL_DATA} ${WRKSRC}/doc/whatisit ${PREFIX}/share/doc/gnucap
	${INSTALL_DATA} ${WRKSRC}/man/man/* ${PREFIX}/share/doc/gnucap
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gnucap
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/gnucap

test: build
	cd ${WRKSRC}/test && ./test ../src/*/gnucap "" 0001 == 2>&1 | \
		tee ${WRKDIR}/test.log

.include "../../mk/bsd.pkg.mk"
