# $NetBSD: Makefile,v 1.2 2000/09/13 08:44:30 tron Exp $

DISTNAME=	cia-20000716
CATEGORIES=	net
MASTER_SITES=	http://core.de/~tron/
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
