# $NetBSD: Makefile,v 1.3 2001/02/17 18:18:40 wiz Exp $

DISTNAME=	cia-20000716
CATEGORIES=	net
MASTER_SITES=	http://core.de/~tron/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
COMMENT=	simple IP accounting software

DOC_DIR=	${PREFIX}/share/doc/cia
EXAMPLES_DIR=	${PREFIX}/share/examples/cia
MAKE_ENV+=	BINDIR="${PREFIX}/bin"

post-install:
	${MKDIR} ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DOC_DIR}
	${MKDIR} ${EXAMPLES_DIR}
	${INSTALL_DATA} ${WRKSRC}/ipstat/examples/*.cfg ${EXAMPLES_DIR}

.include "../../mk/bsd.pkg.mk"
