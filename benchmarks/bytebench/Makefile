# $NetBSD: Makefile,v 1.10 2001/02/16 13:37:46 wiz Exp $

DISTNAME=		byte
PKGNAME=		bytebench-3.6
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.cdrom.com/pub/unix-c/benchmarks/

MAINTAINER=		root@garbled.net
COMMENT=		BYTE Magazine's Public Domain benchmark for UNIX

BENCHMARK_ENV+=		BINDIR=${WRKSRC}/pgms
BENCHMARK_ENV+=		SCRPDIR=${WRKSRC}/pgms
BENCHMARK_ENV+=		RESULTDIR=${WRKSRC}/results
BENCHMARK_ENV+=		TESTDIR=${WRKSRC}/testdir

post-patch:
	${SED} -e 's|@PREFIX@|${PREFIX}|' ${WRKSRC}/Run >${WRKSRC}/run-byte

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} {} \;

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/bytebench
	${INSTALL_SCRIPT} ${WRKSRC}/pgms/* ${PREFIX}/libexec/bytebench
	${INSTALL_DATA_DIR} ${PREFIX}/share/bytebench
	${INSTALL_DATA} ${WRKSRC}/testdir/* ${PREFIX}/share/bytebench
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bytebench
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/bytebench
	${INSTALL_SCRIPT} ${WRKSRC}/run-byte ${PREFIX}/bin

benchmark:
	@if [ `${ID} -u` != 0 ]; then ${ECHO} "This benchmark must be run as root!" ; exit 1 ; fi
	@${SETENV} ${BENCHMARK_ENV} ${WRKSRC}/run-byte \
		| tee ${WRKSRC}/bytebench.out

results:
	-@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/bytebench.out /tmp/benches/`domainname`/bytebench.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
