# $NetBSD: Makefile,v 1.6 1999/03/16 09:02:27 agc Exp $

DISTNAME=		iozone
PKGNAME=		iozone-1.14b
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.bme.hu/pub/OS/Linux/tsx-11/sources/test_suites/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		root@garbled.net

NO_WRKSUBDIR=		yes

do-build:
	(cd ${WRKDIR} && ${CC} -O2 -o iozone iozone.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iozone ${PREFIX}/bin

benchmark:
	@(cd ${WRKSRC}; ./iozone 100 | tee iozone.out)

results:
	-@${MKDIR} /tmp/benches/`domainname`
	-@cp ${WRKSRC}/iozone.out /tmp/benches/`domainname`/iozone.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
