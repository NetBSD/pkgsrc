# $NetBSD: Makefile,v 1.2 1998/09/01 16:42:33 mrg Exp $

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

.include "../../mk/bsd.pkg.mk"
