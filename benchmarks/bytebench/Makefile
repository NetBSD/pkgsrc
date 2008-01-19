# $NetBSD: Makefile,v 1.20 2008/01/19 09:16:17 wiz Exp $

DISTNAME=		unixbench-4.1.0
PKGNAME=		${DISTNAME:S/unix/byte/}
PKGREVISION=		3
CATEGORIES=		benchmarks
MASTER_SITES=		http://www.tux.org/pub/tux/benchmarks/System/unixbench/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		BYTE Magazine's Public Domain benchmark for UNIX

PKG_INSTALLATION_TYPES=	overwrite pkgviews


BENCHMARK_ENV+=		BINDIR=${WRKSRC}/pgms
BENCHMARK_ENV+=		SCRPDIR=${WRKSRC}/pgms
BENCHMARK_ENV+=		RESULTDIR=${WRKSRC}/results
BENCHMARK_ENV+=		BENCHDIR=${WRKSRC}/testdir
BENCHMARK_ENV+=		TESTDIR=${WRKSRC}/tmp

OWN_DIRS=		/var/bytebench

INSTALLATION_DIRS=	bin

REPLACE_PERL+=		pgms/perlbench
USE_TOOLS+=		perl:run

post-extract:
	${RM} -f ${WRKSRC}/pgms/select

post-patch:
	cd ${WRKSRC}; ${SED} -e "s|@PREFIX@|${PREFIX}|g" Run > run-byte
	${CHMOD} +x ${WRKSRC}/run-byte

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/bytebench
	${INSTALL_SCRIPT} ${WRKSRC}/pgms/* ${PREFIX}/libexec/bytebench
	${INSTALL_DATA_DIR} ${PREFIX}/share/bytebench
	${INSTALL_DATA} ${WRKSRC}/testdir/* ${PREFIX}/share/bytebench
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bytebench
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/bytebench
	${INSTALL_SCRIPT} ${WRKSRC}/run-byte ${PREFIX}/bin

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
