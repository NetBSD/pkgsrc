# $NetBSD: Makefile,v 1.6 2003/07/21 17:10:27 martti Exp $

DISTNAME=	cia-20000716
CATEGORIES=	net
MASTER_SITES=	http://core.de/~tron/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@NetBSD.org
COMMENT=	Simple IP accounting software

DOC_DIR=	${PREFIX}/share/doc/cia
EXAMPLES_DIR=	${PREFIX}/share/examples/cia
MAKE_ENV+=	BINDIR="${PREFIX}/bin"

post-install:
	${INSTALL_DATA_DIR} ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DOC_DIR}
	${INSTALL_DATA_DIR} ${EXAMPLES_DIR}
	${INSTALL_DATA} ${WRKSRC}/ipstat/examples/*.cfg ${EXAMPLES_DIR}

.include "../../mk/bsd.pkg.mk"
