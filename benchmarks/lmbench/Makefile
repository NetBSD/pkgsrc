# $NetBSD: Makefile,v 1.36 2012/09/11 22:37:13 asau Exp $

DISTNAME=		lmbench-2alpha11
PKGNAME=		lmbench-2.11a
PKGREVISION=		3
CATEGORIES=		benchmarks
MASTER_SITES=		# ftp://ftp.kreonet.re.kr/tools/benchmark/lmbench/old/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://lmbench.sourceforge.net/
COMMENT=		Complete benchmark that gives a large amount of information

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake perl:run
BUILD_TARGET=		build
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man3 ${PKGMANDIR}/man8

post-extract:
	${INSTALL_SCRIPT} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}/scripts/gnu-os

post-configure:
	cd ${WRKSRC};						\
	for f in src/Makefile; do				\
		${SED} -e "s|^\\(CC.*\\)|#\\1|g" $$f > $$f.new;	\
		${MV} -f $$f.new $$f;				\
	done
	cd ${WRKSRC};						\
	for f in scripts/os scripts/results scripts/config-run	\
		 scripts/lmbench results/Makefile; do		\
		${SED} -e 's|@PREFIX@|${PREFIX}|g' $$f > $$f.new; \
		${MV} -f $$f.new $$f;				\
	done
	${CHMOD} 0755 ${WRKSRC}/scripts/config-run
	${CHMOD} 0755 ${WRKSRC}/scripts/os
	${CHMOD} 0755 ${WRKSRC}/scripts/results
	${CHMOD} 0755 ${WRKSRC}/scripts/lmbench

do-install:
	${SETENV} ${MAKE_ENV} DESTDIR=${DESTDIR} PREFIX=${PREFIX} WRKSRC=${WRKSRC} \
		INSTALL_PROGRAM=${INSTALL:Q} ${FILESDIR}/do-install

.include "../../mk/bsd.prefs.mk"
benchmark:
	if [ ! -f ${PREFIX}/libexec/lmbench/hello ]; then		\
		${ECHO} "*** This benchmark must be installed to run";	\
		exit 1;							\
	fi
.if defined(BATCH)
	@${ECHO} "*** This benchmark should only be run in non-batch mode" ; \
	if [ `id -u` != 0 ]; then ${ECHO} "This benchmark must be run as root!" ; exit 1 ; fi ; \
	${SED} -e 's|@wrksrc@|${WRKSRC}|' < ${FILESDIR}/setup.answers | \
	(cd ${WRKSRC}/src; ${GMAKE} results)
.else
	@if [ `id -u` != 0 ]; then ${ECHO} "This benchmark must be run as root!" ; exit 1 ; fi
	@cd ${WRKSRC}/src; ${GMAKE} results
.endif

results:
	@${MKDIR} /tmp/benches/`domainname`
	cd ${PREFIX}/share/lmbench					\
	&& ${TAR} -cf /tmp/benches/`domainname`/lmbench.`uname`-`uname -m`-`uname -r`.`hostname`.tar results

.include "../../mk/bsd.pkg.mk"
