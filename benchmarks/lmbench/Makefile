# $NetBSD: Makefile,v 1.1 1998/08/30 17:46:25 garbled Exp $

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
	@${MV} ${WRKSRC}/scripts/os foo
	${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' < foo > ${WRKSRC}/scripts/os
	@${MV} ${WRKSRC}/scripts/results foo
	${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' < foo > ${WRKSRC}/scripts/results
	@${MV} ${WRKSRC}/scripts/config-run foo
	${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' < foo > ${WRKSRC}/scripts/config-run
	@${MV} ${WRKSRC}/scripts/lmbench foo
	${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' < foo > ${WRKSRC}/scripts/lmbench
	@${MV} ${WRKSRC}/results/Makefile foo
	${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' < foo > ${WRKSRC}/results/Makefile
	@${RM} -f foo
	@chmod 0755 ${WRKSRC}/scripts/config-run
	@chmod 0755 ${WRKSRC}/scripts/os
	@chmod 0755 ${WRKSRC}/scripts/results
	@chmod 0755 ${WRKSRC}/scripts/lmbench

do-install:
	@${SETENV} PREFIX=${PREFIX} WRKSRC=${WRKSRC} ${SCRIPTDIR}/do-install

.include "../../mk/bsd.pkg.mk"
