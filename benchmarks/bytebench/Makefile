# $NetBSD: Makefile,v 1.1 1998/08/30 17:35:57 garbled Exp $

DISTNAME=		byte
PKGNAME=		bytebench-3.6
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.cdrom.com/pub/unix-c/benchmarks/

MAINTAINER=		root@garbled.net

post-patch:
	${SED} -e 's@XXXPREFIXXXX@${PREFIX}@' <${WRKSRC}/Run>${WRKSRC}/run-byte

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pgms/* ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/bytebench
	${MKDIR} ${PREFIX}/share/doc/bytebench
	${INSTALL_DATA} ${WRKSRC}/testdir/* ${PREFIX}/share/bytebench
	${INSTALL_MAN} ${WRKSRC}/doc/* ${PREFIX}/share/doc/bytebench
	${INSTALL_SCRIPT} ${WRKSRC}/run-byte ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
