# $NetBSD: Makefile,v 1.2 1998/09/24 08:45:00 agc Exp $

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

benchmark:
	@cd ${WRKSRC}/src; ${GMAKE} results

.include "../../mk/bsd.pkg.mk"
