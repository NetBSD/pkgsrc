# $NetBSD: Makefile,v 1.2 1998/09/24 09:23:32 agc Exp $

DISTNAME=		dhry2.1
PKGNAME=		dhrystone-2.1
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://gatekeeper.dec.com/pub/misc/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		root@garbled.net

NO_WRKSUBDIR=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dry2 ${PREFIX}/bin/dry2
	${INSTALL_PROGRAM} ${WRKSRC}/dry2reg ${PREFIX}/bin/dry2reg
	${MKDIR} ${PREFIX}/share/doc/dhrystone
	${INSTALL_MAN} ${WRKSRC}/clarify.doc ${PREFIX}/share/doc/dhrystone
	${INSTALL_MAN} ${WRKSRC}/Rationale ${PREFIX}/share/doc/dhrystone

benchmark:
	-${ECHO} 1000000 | ${WRKSRC}/dry2
	-${ECHO} 1000000 | ${WRKSRC}/dry2reg

.include "../../mk/bsd.pkg.mk"
