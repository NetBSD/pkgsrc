# $NetBSD: Makefile,v 1.18 2001/11/29 01:12:26 hubertf Exp $

DISTNAME=		hbench-OS-1.0
PKGNAME=		hbench-1.0
PKGREVISION=		1
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.eecs.harvard.edu/pub/hbench-OS/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.eecs.harvard.edu/vino/perf/hbench/
COMMENT=		Suite of portable benchmarks to measure the OS and the hardware

DEPENDS+=		gnuplot>=3.7:../../graphics/gnuplot

USE_BUILDLINK_ONLY=	YES
OSVERSION_SPECIFIC=	YES
ALL_TARGET=		build
WRKSRC=			${WRKDIR}/hbench-OS

PLIST_SRC=		${WRKDIR}/PLIST-src

post-patch:
	@machfiles="";							\
	if [ ${MACHINE} = i386 ]; then					\
		machfiles="$$machfiles ${PKGDIR}/PLIST.${MACHINE}";	\
	fi ;								\
	${CAT} ${PKGDIR}/PLIST.md $$machfiles ${PKGDIR}/PLIST.common	\
		> ${PLIST_SRC}

post-configure:
	@cd ${WRKSRC};							\
	for f in scripts/create-all-analyses				\
		scripts/create-all-latgraphs				\
		scripts/create-all-summaries scripts/gen-analysis	\
		scripts/gen-latgraph scripts/gen-summary 		\
		scripts/interactive-setup scripts/maindriver		\
		Results/Makefile; do					\
		${MV} $$f $$f.in;					\
		${SED} -e 's|@PREFIX@|${PREFIX}|g' $$f.in > $$f;	\
	done
	@ ${CHMOD} 0755 ${WRKSRC}/scripts/*

do-install:
	@${SETENV} PREFIX=${PREFIX} WRKSRC=${WRKSRC} ${FILESDIR}/do-install

benchmark:
	@if [ `id -u` != 0 ]; then ${ECHO} "This benchmark must be run as root!" ; exit 1 ; fi
	cd ${WRKSRC};							\
	${MKDIR} conf;							\
	${MKDIR} results;						\
	${SED} -e 's|@pwd@|'`/bin/pwd`'|g' 				\
		-e 's|@hostname@|'`/bin/hostname -s`'|g'		\
		-e 's|@wrksrc@|'`/bin/pwd`'|g'				\
		${FILESDIR}/setup.answers | ${MAKE} setup;		\
	${MV} conf/`/bin/hostname -s`.run conf/foo ;			\
	${SED} -e 's|#PLAINBINDIR=${HBENCHROOT}|PLAINBINDIR='`/bin/pwd`'|' \
		< conf/foo > conf/`/bin/hostname -s`.run ;		\
	${MAKE} run

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@cd ${WRKSRC} ; \
	tar -cf /tmp/benches/`domainname`/hbench.`uname`-`uname -m`-`uname -r`.`hostname`.tar results conf

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
