# $NetBSD: Makefile,v 1.1.1.1 2002/04/17 21:51:35 thorpej Exp $

DISTNAME=	nttcp-1.47
CATEGORIES=	benchmarks net
MASTER_SITES=	http://www.leo.org/~elmar/nttcp/

MAINTAINER=	thorpej@netbsd.org
HOMEPAGE=	http://www.leo.org/~elmar/nttcp/
COMMENT=	New TCP testing and performance measuring tool

do-install:
	cd ${WRKSRC} ; \
	${INSTALL_PROGRAM} nttcp ${PREFIX}/bin/nttcp ; \
	${INSTALL_MAN} nttcp.1 ${PREFIX}/man/man1/nttcp.1

.include "../../mk/bsd.pkg.mk"
