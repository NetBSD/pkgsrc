# $NetBSD: Makefile,v 1.14 2001/11/28 05:20:38 jlam Exp $

DISTNAME=		lmbench-2alpha11
PKGNAME=		lmbench-2.11a
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.bitmover.com/lmbench/
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.bitmover.com/lm/lmbench/
COMMENT=		Complete benchmark that gives a large amount of information

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES
ALL_TARGET=		build
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

post-configure:
	@cd ${WRKSRC};						\
	for f in scripts/os scripts/results scripts/config-run	\
		 scripts/lmbench results/Makefile; do		\
		${MV} $$f $$f.in;				\
		${SED} -e 's|@PREFIX@|${PREFIX}|g' $$f.in > $$f; \
	done
	@${CHMOD} 0755 ${WRKSRC}/scripts/config-run
	@${CHMOD} 0755 ${WRKSRC}/scripts/os
	@${CHMOD} 0755 ${WRKSRC}/scripts/results
	@${CHMOD} 0755 ${WRKSRC}/scripts/lmbench

do-install:
	@${SETENV} PREFIX=${PREFIX} WRKSRC=${WRKSRC} \
		INSTALL_PROGRAM=${INSTALL} ${FILESDIR}/do-install

.include "../../mk/bsd.prefs.mk"

benchmark:
	if [ ! -f ${PREFIX}/bin/lmbench/hello ]; then \
		@${ECHO} "*** This benchmark must be installed to run" ; \
		exit 1 ; \
	fi
.if defined(BATCH)
	@${ECHO} "*** This benchmark should only be run in non-batch mode" ; \
	if [ `id -u` != 0 ]; then ${ECHO} "This benchmark must be run as root!" ; exit 1 ; fi ; \
	@${SED} -e 's|@wrksrc@|${WRKSRC}|' < ${FILESDIR}/setup.answers | \
	(cd ${WRKSRC}/src; ${GMAKE} results)
.else
	@if [ `id -u` != 0 ]; then ${ECHO} "This benchmark must be run as root!" ; exit 1 ; fi
	@cd ${WRKSRC}/src; ${GMAKE} results
.endif

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@cd ${PREFIX}/share/lmbench ; \
	tar -cf /tmp/benches/`domainname`/lmbench.`uname`-`uname -m`-`uname -r`.`hostname`.tar results

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
