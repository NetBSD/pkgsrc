# $NetBSD: Makefile,v 1.4 1998/12/26 15:59:56 garbled Exp $

DISTNAME=		lmbench-2alpha11
PKGNAME=		lmbench-2.11a
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.bitmover.com/lmbench/
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.bitmover.com/lm/lmbench/

ALL_TARGET=		build
USE_GMAKE=		yes
USE_PERL5=		yes

post-configure:
	@cd ${WRKSRC};						\
	for f in scripts/os scripts/results scripts/config-run	\
		 scripts/lmbench results/Makefile; do		\
		${MV} $$f $$f.in;				\
		${SED} -e 's|@PREFIX@|${PREFIX}|g' $$f.in > $$f; \
	done
	@chmod 0755 ${WRKSRC}/scripts/config-run
	@chmod 0755 ${WRKSRC}/scripts/os
	@chmod 0755 ${WRKSRC}/scripts/results
	@chmod 0755 ${WRKSRC}/scripts/lmbench

do-install:
	@${SETENV} PREFIX=${PREFIX} WRKSRC=${WRKSRC} ${SCRIPTDIR}/do-install

.include "../../mk/bsd.prefs.mk"

benchmark:
.if exists(${PREFIX}/bin/lmbench/hello)
.if defined(BATCH)
	@${ECHO} "*** This benchmark should only be run in non-batch mode" ; \
	if [ `id -u` != 0 ]; then echo "This benchmark must be run as root!" ; exit 1 ; fi ; \
	@${SED} -e 's|@wrksrc@|${WRKSRC}|' < ${FILESDIR}/setup.answers | \
	(cd ${WRKSRC}/src; ${GMAKE} results)
.else
	@if [ `id -u` != 0 ]; then echo "This benchmark must be run as root!" ; exit 1 ; fi
	@cd ${WRKSRC}/src; ${GMAKE} results
.endif
.else
	@${ECHO} "*** This benchmark must be installed to run" ; \
	exit 1
.endif

results:
	-@${MKDIR} /tmp/benches/`domainname`
	-@cd ${PREFIX}/share/lmbench ; \
	tar -cf /tmp/benches/`domainname`/lmbench.`uname`-`uname -m`-`uname -r`.`hostname`.tar results

.include "../../mk/bsd.pkg.mk"
