# $NetBSD: Makefile,v 1.7 2004/11/10 15:32:33 adam Exp $

DISTNAME=	dbench-2.1
CATEGORIES=	benchmarks
MASTER_SITES=	http://samba.org/ftp/tridge/dbench/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://samba.org/ftp/tridge/dbench/README
COMMENT=	Simulation of the Ziff-Davis netbench benchmark

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	DB_LDFLAGS="-lrt" TB_LDFLAGS="-lsocket -lnsl"
.endif

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dbench ${PREFIX}/bin/dbench
	${INSTALL_PROGRAM} ${WRKSRC}/tbench ${PREFIX}/bin/tbench
	${INSTALL_PROGRAM} ${WRKSRC}/tbench_srv ${PREFIX}/bin/tbench_srv
	${INSTALL_DATA_DIR} ${PREFIX}/share/dbench
	${INSTALL_DATA} ${WRKSRC}/client_*.txt ${PREFIX}/share/dbench/

.include "../../mk/bsd.pkg.mk"
