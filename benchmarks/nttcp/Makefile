# $NetBSD: Makefile,v 1.2 2003/07/17 21:24:33 grant Exp $

DISTNAME=	nttcp-1.47
CATEGORIES=	benchmarks net
MASTER_SITES=	http://www.leo.org/~elmar/nttcp/

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	http://www.leo.org/~elmar/nttcp/
COMMENT=	New TCP testing and performance measuring tool

do-install:
	cd ${WRKSRC} ; \
	${INSTALL_PROGRAM} nttcp ${PREFIX}/bin/nttcp ; \
	${INSTALL_MAN} nttcp.1 ${PREFIX}/man/man1/nttcp.1

.include "../../mk/bsd.pkg.mk"
