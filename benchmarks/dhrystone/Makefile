# $NetBSD: Makefile,v 1.3 1998/12/26 15:59:55 garbled Exp $

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
	-@${ECHO} 5000000 | ${WRKSRC}/dry2 | tee ${WRKSRC}/dry.out
	-@${ECHO} 5000000 | ${WRKSRC}/dry2reg | tee -a ${WRKSRC}/dry.out

results:
	-@${MKDIR} /tmp/benches/`domainname`
	-@cp ${WRKSRC}/dry.out /tmp/benches/`domainname`/dhrystone.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
