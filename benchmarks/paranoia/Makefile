# $NetBSD: Makefile,v 1.2 1998/09/06 21:12:41 garbled Exp $

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
	(cd ${WRKSRC} ; cc -o paranoia paranoia.c -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/paranoia ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
