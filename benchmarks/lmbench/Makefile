# $NetBSD: Makefile,v 1.20 2004/12/03 15:14:51 wiz Exp $

DISTNAME=		lmbench-2alpha11
PKGNAME=		lmbench-2.11a
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.bitmover.com/lmbench/
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.bitmover.com/lm/lmbench/
COMMENT=		Complete benchmark that gives a large amount of information

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
BUILD_TARGET=		build
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

INSTALLATION_DIRS=	man/man1 man/man3 man/man8

post-configure:
	@cd ${WRKSRC};						\
	for f in src/Makefile; do				\
		${SED} -e "s|^\(CC.*\)|#\1|g" $$f > $$f.new;	\
		${MV} -f $$f.new $$f;				\
	done
	@cd ${WRKSRC};						\
	for f in scripts/os scripts/results scripts/config-run	\
		 scripts/lmbench results/Makefile; do		\
		${SED} -e 's|@PREFIX@|${PREFIX}|g' $$f > $$f.new; \
		${MV} -f $$f.new $$f;				\
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

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
