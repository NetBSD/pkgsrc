# $NetBSD: Makefile,v 1.9 1999/09/06 04:48:53 sakamoto Exp $

DISTNAME=		hbench-OS-1.0
PKGNAME=		hbench-1.0
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.eecs.harvard.edu/pub/hbench-OS/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.eecs.harvard.edu/vino/perf/hbench/

DEPENDS+=		gnuplot-3.7:../../graphics/gnuplot

ALL_TARGET=		build
USE_PERL5=		yes
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
	@/bin/chmod 0755 ${WRKSRC}/scripts/*

do-install:
	@${SETENV} PREFIX=${PREFIX} WRKSRC=${WRKSRC} ${SCRIPTDIR}/do-install

benchmark:
	@if [ `id -u` != 0 ]; then echo "This benchmark must be run as root!" ; exit 1 ; fi
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
	-@${MKDIR} /tmp/benches/`domainname`
	-@cd ${WRKSRC} ; \
	tar -cf /tmp/benches/`domainname`/hbench.`uname`-`uname -m`-`uname -r`.`hostname`.tar results conf

.include "../../mk/bsd.pkg.mk"
