# $NetBSD: Makefile,v 1.3 1998/09/23 16:09:05 agc Exp $

DISTNAME=		iozone
PKGNAME=		iozone-1.14b
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.bme.hu/pub/OS/Linux/tsx-11/sources/test_suites/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		root@garbled.net

NO_WRKSUBDIR=		yes

do-build:
	(cd ${WRKDIR} && cc -O2 -o iozone iozone.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iozone ${PREFIX}/bin

benchmark:
	@${WRKSRC}/iozone

.include "../../mk/bsd.pkg.mk"
