# $NetBSD: Makefile,v 1.3 1998/09/24 09:08:16 agc Exp $

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

benchmark:
	@(cd ${WRKSRC}; ./paranoia < ${FILESDIR}/paranoia.run)

.include "../../mk/bsd.pkg.mk"
