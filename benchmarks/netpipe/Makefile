# $NetBSD: Makefile,v 1.1.1.1 2001/07/27 23:33:35 thorpej Exp $

DISTNAME=	netpipe-2.4
CATEGORIES=	benchmarks net
MASTER_SITES=	ftp://ftp.scl.ameslab.gov/pub/netpipe/

MAINTAINER=	thorpej@netbsd.org
HOMEPAGE=	http://www.scl.ameslab.gov/netpipe/
COMMENT=	TCP/PVM/MPI testing and performance measuring tool

do-install:
	cd ${WRKSRC} ; \
	${INSTALL_PROGRAM} NPtcp ${PREFIX}/bin/NPtcp ; \
	${INSTALL_MAN} netpipe.1 ${PREFIX}/man/man1/netpipe.1

.include "../../mk/bsd.pkg.mk"
