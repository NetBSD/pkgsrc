# $NetBSD: Makefile,v 1.5 1998/11/16 11:27:54 agc Exp $

DISTNAME=		hbench-OS-1.0
PKGNAME=		hbench-1.0
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.eecs.harvard.edu/pub/hbench-OS/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.eecs.harvard.edu/vino/perf/hbench/

DEPENDS+=		gnuplot-3.5:../../graphics/gnuplot

ALL_TARGET=		build
USE_PERL5=		yes
WRKSRC=			${WRKDIR}/hbench-OS

PLIST_SRC=		${WRKDIR}/PLIST-src

post-patch:
	@machfiles="";							\
	if [ ${MACHINE} = i386 ]; then					\
		machfiles="$$machfiles ${PKGDIR}/PLIST.i386";		\
	fi ;								\
	${CAT} ${PKGDIR}/PLIST.md $$machfiles ${PKGDIR}/PLIST.common |	\
		${SED} -e 's|@OPSYS@|'`${ECHO} ${OPSYS} | ${TR} '[A-Z]' '[a-z]'`'|g' > ${PLIST_SRC}

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
	@cd ${WRKSRC};							\
	${SED} -e 's|@pwd@|'`/bin/pwd`'|g' 				\
		-e 's|@hostname@|'`/bin/hostname -s`'|g'		\
		${FILESDIR}/setup.answers | ${MAKE} setup;		\
	${MAKE} run

.include "../../mk/bsd.pkg.mk"
