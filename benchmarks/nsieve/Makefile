# $NetBSD: Makefile,v 1.1.1.1 1998/10/22 06:23:09 garbled Exp $

DISTNAME=		nsieve.c
PKGNAME=		nsieve-1.2b
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.nosc.mil/pub/aburto/nsieve/
EXTRACT_SUFX=		#empty

MAINTAINER=		root@garbled.net

NO_WRKSUBDIR=		yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/nsieve.c ${WRKSRC}/nsieve.c

do-build:
	(cd ${WRKSRC} ; cc -O2 -DUNIX -o nsieve nsieve.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nsieve ${PREFIX}/bin

benchmark:
	-@${WRKSRC}/nsieve

.include "../../mk/bsd.pkg.mk"
