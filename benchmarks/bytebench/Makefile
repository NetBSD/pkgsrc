# $NetBSD: Makefile,v 1.7 2000/03/16 12:16:50 wiz Exp $

DISTNAME=		byte
PKGNAME=		bytebench-3.6
CATEGORIES=		benchmarks
MASTER_SITES=		ftp://ftp.cdrom.com/pub/unix-c/benchmarks/

MAINTAINER=		root@garbled.net

post-patch:
	${SED} -e 's|@PREFIX@|${PREFIX}|' ${WRKSRC}/Run >${WRKSRC}/run-byte

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pgms/* ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/bytebench
	${MKDIR} ${PREFIX}/share/doc/bytebench
	${INSTALL_DATA} ${WRKSRC}/testdir/* ${PREFIX}/share/bytebench
	${INSTALL_MAN} ${WRKSRC}/doc/* ${PREFIX}/share/doc/bytebench
	${INSTALL_SCRIPT} ${WRKSRC}/run-byte ${PREFIX}/bin

benchmark:
	@if [ `${ID} -u` != 0 ]; then ${ECHO} "This benchmark must be run as root!" ; exit 1 ; fi
	@${WRKSRC}/run-byte | tee ${WRKSRC}/bytebench.out

results:
	-@${MKDIR} /tmp/benches/`domainname`
	-@${CP} ${WRKSRC}/bytebench.out /tmp/benches/`domainname`/bytebench.`uname`-`uname -m`-`uname -r`.`hostname`

.include "../../mk/bsd.pkg.mk"
