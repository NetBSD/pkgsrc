# $NetBSD: Makefile,v 1.1 1998/09/05 22:02:19 garbled Exp $

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
NETBSDVER!=		echo `uname -s|tr '[A-Z]' '[a-z]'``uname -r`-`uname -m`
ARCH!=			echo `uname -m`

post-patch:
	@if [ ${ARCH} = i386 ];then \
		${CAT} ${PKGDIR}/PLIST.md ${PKGDIR}/PLIST.i386 ${PKGDIR}/PLIST.common >foo ;\
	else \
		${CAT} ${PKGDIR}/PLIST.md ${PKGDIR}/PLIST.common >foo ;\
	fi 
	@sed -e 's@XXXNETBSDVERXXX@${NETBSDVER}@' <foo> ${PKGDIR}/PLIST
	@${RM} -f foo

post-configure:
	@${MV} ${WRKSRC}/scripts/create-all-analyses foo
	${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' < foo > ${WRKSRC}/scripts/create-all-analyses
	@${MV} ${WRKSRC}/scripts/create-all-latgraphs foo
	${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' < foo > ${WRKSRC}/scripts/create-all-latgraphs
	@${MV} ${WRKSRC}/scripts/create-all-summaries foo
	${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' < foo > ${WRKSRC}/scripts/create-all-summaries
	@${MV} ${WRKSRC}/scripts/gen-analysis foo
	${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' < foo > ${WRKSRC}/scripts/gen-analysis
	@${MV} ${WRKSRC}/scripts/gen-latgraph foo
	${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' < foo > ${WRKSRC}/scripts/gen-latgraph
	@${MV} ${WRKSRC}/scripts/gen-summary foo
	${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' < foo > ${WRKSRC}/scripts/gen-summary
	@${MV} ${WRKSRC}/scripts/interactive-setup foo
	${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' < foo > ${WRKSRC}/scripts/interactive-setup
	@${MV} ${WRKSRC}/scripts/maindriver foo
	${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' < foo > ${WRKSRC}/scripts/maindriver
	@${MV} ${WRKSRC}/Results/Makefile foo
	${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' < foo > ${WRKSRC}/Results/Makefile
	@${RM} -f foo
	@chmod 0755 ${WRKSRC}/scripts/*

do-install:
	@${SETENV} PREFIX=${PREFIX} WRKSRC=${WRKSRC} ${SCRIPTDIR}/do-install

.include "../../mk/bsd.pkg.mk"
