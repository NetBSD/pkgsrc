# $NetBSD: Makefile,v 1.13 2004/01/20 12:08:12 agc Exp $

DISTNAME=		paranoia
PKGNAME=		paranoia-960101
CATEGORIES=		benchmarks
MASTER_SITES=		http://www.netlib.org/paranoia/
EXTRACT_SUFX=		.c

MAINTAINER=		root@garbled.net
COMMENT=		Highly paranoid test of IEEE 754 conformancy

EXTRACT_CMD=		${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}

WRKSRC=			${WRKDIR}

do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -ffloat-store -o paranoia paranoia.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/paranoia ${PREFIX}/bin

benchmark:
	@(cd ${WRKSRC}; ./paranoia < ${FILESDIR}/paranoia.run | tee paranoia.out)

results:
	@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/paranoia.out /tmp/benches/`domainname`/paranoia.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
