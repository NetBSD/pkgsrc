# $NetBSD: Makefile,v 1.9 2004/01/22 07:21:54 grant Exp $
#

DISTNAME=	acs-0.29
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/dist/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.geda.seul.org/tools/acs/index.html
COMMENT=	General purpose circuit simulator

USE_GNU_TOOLS+=	make

do-build:
	cd ${WRKSRC}/src && ${MAKE_PROGRAM} ${LOWER_OPSYS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/*/acs ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/acs
	${INSTALL_DATA} ${WRKSRC}/doc/acs-tutorial ${PREFIX}/share/doc/acs
	${INSTALL_DATA} ${WRKSRC}/man/man.pdf ${PREFIX}/share/doc/acs
	${INSTALL_DATA} ${WRKSRC}/doc/whatisit ${PREFIX}/share/doc/acs
	${INSTALL_DATA} ${WRKSRC}/man/man/* ${PREFIX}/share/doc/acs
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/acs
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/acs

.include "../../mk/bsd.pkg.mk"
