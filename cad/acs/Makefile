# $NetBSD: Makefile,v 1.2 2000/03/26 15:50:21 dmcmahill Exp $
#

DISTNAME=	acs-0.26
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/dist/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.geda.seul.org/tools/acs/index.html

do-build:
	cd ${WRKSRC}/src && ${MAKE} ${LOWER_OPSYS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/*/acs ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/acs
	${INSTALL_DATA} ${WRKSRC}/doc/acs-tutorial ${PREFIX}/share/doc/acs
	${INSTALL_DATA} ${WRKSRC}/doc/man.pdf ${PREFIX}/share/doc/acs
	${INSTALL_DATA} ${WRKSRC}/doc/whatisit ${PREFIX}/share/doc/acs
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/acs
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/acs

.include "../../mk/bsd.pkg.mk"
