# $NetBSD: Makefile,v 1.1 1998/08/30 19:38:57 garbled Exp $

DISTNAME=		paranoia
PKGNAME=		paranoia-960101
CATEGORIES=		benchmarks
MASTER_SITES=		http://www.netlib.org/paranoia/
EXTRACT_SUFX=		.c

MAINTAINER=		root@garbled.net

NO_WRKSUBDIR=		yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/paranoia.c ${WRKSRC}/paranoia.c

do-build:
	(cd ${WRKSRC} ; cc -o paranoia paranoia.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/paranoia ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
