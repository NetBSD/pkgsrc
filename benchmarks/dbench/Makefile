# $NetBSD: Makefile,v 1.5 2004/07/30 15:50:37 minskim Exp $
#

DISTNAME=	dbench-1.3
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://dnuc.polyn.kiae.su/pub/dbench/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://samba.org/ftp/tridge/dbench/README
COMMENT=	Simulation of the Ziff-Davis netbench benchmark

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/dbench

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
	${INSTALL_DATA} ${WRKSRC}/client.txt ${PREFIX}/share/dbench/client.txt

.include "../../mk/bsd.pkg.mk"
