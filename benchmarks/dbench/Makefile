# $NetBSD: Makefile,v 1.1.1.1 2003/07/17 15:11:44 agc Exp $
#

DISTNAME=	dbench-1.3
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://dnuc.polyn.kiae.su/pub/dbench/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://samba.org/ftp/tridge/dbench/README
COMMENT=	Simulation of the Ziff-Davis netbench benchmark

WRKSRC=		${WRKDIR}/dbench

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dbench ${PREFIX}/bin/dbench
	${INSTALL_PROGRAM} ${WRKSRC}/tbench ${PREFIX}/bin/tbench
	${INSTALL_PROGRAM} ${WRKSRC}/tbench_srv ${PREFIX}/bin/tbench_srv
	${INSTALL_DATA_DIR} ${PREFIX}/share/dbench
	${INSTALL_DATA} ${WRKSRC}/client.txt ${PREFIX}/share/dbench/client.txt

.include "../../mk/bsd.pkg.mk"
