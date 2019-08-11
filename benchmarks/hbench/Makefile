# $NetBSD: Makefile,v 1.60 2019/08/11 13:17:58 wiz Exp $

DISTNAME=		hbench-OS-1.1
PKGNAME=		hbench-1.1
PKGREVISION=		8
CATEGORIES=		benchmarks
#MASTER_SITES=		http://www.eecs.harvard.edu/vino/perf/hbench/

PATCHFILES=		hbench-OS-1.1-provisional-patch1.diff
PATCH_SITES=		http://www.eecs.harvard.edu/~dholland/netbsd/
PATCH_DIST_STRIP=	-p1

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.eecs.harvard.edu/vino/perf/hbench/
COMMENT=		Suite of portable benchmarks to measure the OS and the hardware

DEPENDS+=		gnuplot>=3.7:../../graphics/gnuplot

WRKSRC=			${WRKDIR}/HBenchOS
OSVERSION_SPECIFIC=	YES
BUILD_TARGET=		build
USE_TOOLS+=		perl:run
OVERRIDE_GNU_CONFIG_SCRIPTS=	yes
MAKE_JOBS_SAFE=		no

GET_ARCH_CMD=		${PKGSRCDIR:Q}/mk/gnu-config/config.guess | ${SED} -e 's/-.*-.*$$//'
GET_OS_CMD=		${PKGSRCDIR:Q}/mk/gnu-config/config.guess | ${SED} -e 's/^[^-]*-[^-]*-//;s/-.*$$//'
PLIST_SUBST+=		PLATFORM=${GET_OS_CMD:sh:Q}-${GET_ARCH_CMD:sh:Q}

.include "../../mk/bsd.prefs.mk"

BUILDLINK_TRANSFORM.SunOS+=	rm:-static

HB_HOSTNAME!=		${UNAME} -n
HB_SHORTNAME=		${HB_HOSTNAME:C/\..*//}

post-extract:
	${CP} ${FILESDIR}/do-install ${WRKSRC}

SUBST_CLASSES+=		hb
SUBST_STAGE.hb=		pre-configure
SUBST_MESSAGE.hb=	Replacing bin with libexec.
SUBST_FILES.hb=		do-install
SUBST_FILES.hb+=	scripts/*
SUBST_FILES.hb+=	Results/Makefile
SUBST_VARS.hb=		PREFIX
SUBST_SED.hb=		-e 's,/bin/hbench,/libexec/hbench,g'

INSTALLATION_DIRS=	bin

do-install:
	${SETENV} ${MAKE_ENV} WRKSRC=${WRKSRC} BINOWN=${BINOWN} \
		REAL_PREFIX=${PREFIX} BINGRP=${BINGRP} \
		PREFIX=${DESTDIR}${PREFIX} ${WRKSRC}/do-install

benchmark:
	@if [ `id -u` != 0 ]; then ${ECHO} "This benchmark must be run as root!" ; exit 1 ; fi
	cd ${WRKSRC};							\
	${MKDIR} conf;							\
	${MKDIR} results;						\
	${SED} -e 's|@pwd@|'`/bin/pwd`'|g' 				\
		-e 's|@hostname@|${HB_SHORTNAME}|g'			\
		-e 's|@wrksrc@|'`/bin/pwd`'|g'				\
		${FILESDIR}/setup.answers | ${MAKE} setup;		\
	${MV} conf/${HB_SHORTNAME}.run conf/foo ;			\
	${SED} -e 's|#PLAINBINDIR=${HBENCHROOT}|PLAINBINDIR='`/bin/pwd`'|' \
		< conf/foo > conf/${HB_SHORTNAME}.run ;			\
	${MAKE} run

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@cd ${WRKSRC} ; \
	tar -cf /tmp/benches/`domainname`/hbench.`uname`-`uname -m`-`uname -r`.`hostname`.tar results conf

.include "../../mk/bsd.pkg.mk"
