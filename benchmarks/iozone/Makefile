# $NetBSD: Makefile,v 1.10 2000/05/03 09:13:15 pooka Exp $

DISTNAME=		iozone3_9
PKGNAME=		iozone-3.09
CATEGORIES=		benchmarks
MASTER_SITES=		http://www.iozone.org/src/stable/
EXTRACT_SUFX=		.tar

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.iozone.org/

WRKSRC=			${WRKDIR}/src
MAKEFILE=		makefile

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD")
  ALL_TARGET=		NetBSD
.elif (${OPSYS} == "SunOS")
  ALL_TARGET=		Solaris
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/iozone ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/iozone.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/IOzone
	${INSTALL_DATA} ${WRKDIR}/docs/IOzone_ps.gz ${PREFIX}/share/doc/IOzone

.include "../../mk/bsd.pkg.mk"
