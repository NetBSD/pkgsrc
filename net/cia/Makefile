# $NetBSD: Makefile,v 1.10 2006/11/09 09:14:05 rillig Exp $

DISTNAME=	cia-20030922
CATEGORIES=	net
MASTER_SITES=	http://scheler.de/~matthias/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@NetBSD.org
COMMENT=	Simple IP accounting software

DOC_DIR=	${PREFIX}/share/doc/cia
EXAMPLES_DIR=	${PREFIX}/share/examples/cia
MAKE_ENV+=	${BSD_MAKE_ENV}

post-install:
	${INSTALL_DATA_DIR} ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DOC_DIR}
	${INSTALL_DATA_DIR} ${EXAMPLES_DIR}
	${INSTALL_DATA} ${WRKSRC}/ipstat/examples/*.cfg ${EXAMPLES_DIR}

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
