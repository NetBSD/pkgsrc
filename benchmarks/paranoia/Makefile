# $NetBSD: Makefile,v 1.5 1999/03/16 08:53:43 agc Exp $

DISTNAME=		paranoia
PKGNAME=		paranoia-960101
CATEGORIES=		benchmarks
MASTER_SITES=		http://www.netlib.org/paranoia/
EXTRACT_SUFX=		.c

MAINTAINER=		root@garbled.net

NO_WRKSUBDIR=		yes
EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	#empty
EXTRACT_AFTER_ARGS=	${WRKSRC}

do-build:
	(cd ${WRKSRC} ; ${CC} -ffloat-store -o paranoia paranoia.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/paranoia ${PREFIX}/bin

benchmark:
	@(cd ${WRKSRC}; ./paranoia < ${FILESDIR}/paranoia.run | tee paranoia.out)

results:
	-@${MKDIR} /tmp/benches/`domainname`
	-@cp ${WRKSRC}/paranoia.out /tmp/benches/`domainname`/paranoia.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
