# $NetBSD: Makefile,v 1.1.1.1 2000/07/16 17:14:38 tron Exp $

DISTNAME=	cia-20000716
CATEGORIES=	net
MASTER_SITES=	http://www.pader.net/~mscheler/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org

DOC_DIR=	${PREFIX}/share/doc/cia
EXAMPLES_DIR=	${PREFIX}/share/examples/cia
MAKE_ENV+=	BINDIR="${PREFIX}/bin"

post-install:
	${MKDIR} ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DOC_DIR}
	${MKDIR} ${EXAMPLES_DIR}
	${INSTALL_DATA} ${WRKSRC}/ipstat/examples/*.cfg ${EXAMPLES_DIR}

.include "../../mk/bsd.pkg.mk"
