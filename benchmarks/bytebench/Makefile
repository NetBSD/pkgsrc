# $NetBSD: Makefile,v 1.35 2023/12/21 13:10:01 zafer Exp $

DISTNAME=		unixbench-4.1.0
PKGNAME=		${DISTNAME:S/unix/byte/}
PKGREVISION=		13
CATEGORIES=		benchmarks
MASTER_SITES=		https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/byte-unixbench/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		BYTE Magazine's Public Domain benchmark for UNIX

BENCHMARK_ENV+=		BINDIR=${WRKSRC}/pgms
BENCHMARK_ENV+=		SCRPDIR=${WRKSRC}/pgms
BENCHMARK_ENV+=		RESULTDIR=${WRKSRC}/results
BENCHMARK_ENV+=		BENCHDIR=${WRKSRC}/testdir
BENCHMARK_ENV+=		TESTDIR=${WRKSRC}/tmp

OWN_DIRS=		/var/bytebench

INSTALLATION_DIRS=	bin

REPLACE_PERL+=		pgms/perlbench
USE_TOOLS+=		perl:run

MAKE_JOBS_SAFE=		no

post-extract:
	${RM} -f ${WRKSRC}/pgms/select

post-patch:
	cd ${WRKSRC}; ${SED} -e "s|@PREFIX@|${PREFIX}|g" Run > run-byte
	${CHMOD} +x ${WRKSRC}/run-byte

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/libexec/bytebench
	${INSTALL_SCRIPT} ${WRKSRC}/pgms/* ${DESTDIR}${PREFIX}/libexec/bytebench
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/bytebench
	${INSTALL_DATA} ${WRKSRC}/testdir/* ${DESTDIR}${PREFIX}/share/bytebench
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/bytebench
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/bytebench
	${INSTALL_SCRIPT} ${WRKSRC}/run-byte ${DESTDIR}${PREFIX}/bin

benchmark:
	@if [ `${ID} -u` != 0 ]; then					\
		${ECHO} "This benchmark must be run as root!";		\
		exit 1;							\
	fi
	@( cd ${WRKSRC}; ${SETENV} ${BENCHMARK_ENV} ./run-byte		\
		| tee bytebench.out )

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/bytebench.out /tmp/benches/`domainname`/bytebench.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
