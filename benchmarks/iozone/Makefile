# $NetBSD: Makefile,v 1.23 2004/01/21 22:31:56 wiz Exp $

DISTNAME=		iozone3_217
PKGNAME=		iozone-3.217
CATEGORIES=		benchmarks
MASTER_SITES=		http://www.iozone.org/src/current/
EXTRACT_SUFX=		.tar

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.iozone.org/
COMMENT=		Benchmark for file read and write speed

RESTRICTED=		"Publication of derivative works not allowed"

WRKSRC=			${WRKDIR}/src/current
MAKEFILE=		makefile

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD")
  ALL_TARGET=		netbsd
.elif (${OPSYS} == "SunOS")
  ALL_TARGET=		Solaris
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iozone ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/docs/iozone.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/IOzone
	${INSTALL_DATA} ${WRKDIR}/docs/Iozone_ps.gz ${PREFIX}/share/doc/IOzone

benchmark:
	@(cd ${WRKSRC}; ./iozone -Ea | tee iozone.out)

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/iozone.out /tmp/benches/`domainname`/iozone.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
