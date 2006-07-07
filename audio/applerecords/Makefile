# $NetBSD: Makefile,v 1.6 2006/07/07 04:06:15 minskim Exp $
#

DISTNAME=		applerecords-0.5
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://www.cdavies.org/code/
EXTRACT_SUFX=		.jar

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cdavies.org/applerecords.html
COMMENT=		Java DAAP client

NO_BUILD=		yes
WRKSRC=			${WRKDIR}
USE_JAVA=		run

INSTALLATION_DIRS=	bin

.include "../../mk/java-vm.mk"

do-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}.jar ${WRKSRC}
	${SED} -e 's|@SH@|${SH}|g' -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/applerecords > ${WRKSRC}/applerecords

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/applerecords
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${PREFIX}/lib/applerecords/applerecords.jar
	${INSTALL_SCRIPT} ${WRKSRC}/applerecords ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
