# $NetBSD: Makefile,v 1.11 2000/05/04 10:38:27 pooka Exp $

DISTNAME=		iozone3_9
PKGNAME=		iozone-3.09
CATEGORIES=		benchmarks
MASTER_SITES=		http://www.iozone.org/src/stable/
EXTRACT_SUFX=		.tar

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.iozone.org/

WRKSRC=			${WRKDIR}/src
MAKEFILE=		makefile

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD")
  ALL_TARGET=		NetBSD
.elif (${OPSYS} == "SunOS")
  ALL_TARGET=		Solaris
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iozone ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/iozone.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/IOzone
	${INSTALL_DATA} ${WRKDIR}/docs/IOzone_ps.gz ${PREFIX}/share/doc/IOzone

benchmark:
	@(cd ${WRKSRC}; ./iozone 100 | tee iozone.out)

results:
	-@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/iozone.out /tmp/benches/`domainname`/iozone.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
