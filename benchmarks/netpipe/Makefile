# $NetBSD: Makefile,v 1.3 2003/09/19 18:14:02 wiz Exp $

DISTNAME=	netpipe-2.4
CATEGORIES=	benchmarks net
MASTER_SITES=	ftp://ftp.scl.ameslab.gov/pub/netpipe/

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	http://www.scl.ameslab.gov/netpipe/
COMMENT=	TCP/PVM/MPI testing and performance measuring tool

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-DHAVE_GETRUSAGE

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	EXTRA_LIBS="-lsocket -lnsl"
.endif

do-install:
	cd ${WRKSRC} ; \
	${INSTALL_PROGRAM} NPtcp ${PREFIX}/bin/NPtcp ; \
	${INSTALL_MAN} netpipe.1 ${PREFIX}/man/man1/netpipe.1

.include "../../mk/bsd.pkg.mk"
