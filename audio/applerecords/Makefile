# $NetBSD: Makefile,v 1.4 2005/06/16 06:57:38 jlam Exp $
#

DISTNAME=		applerecords-0.5
CATEGORIES=		audio
MASTER_SITES=		http://www.cdavies.org/code/
EXTRACT_SUFX=		.jar

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.cdavies.org/applerecords.html
COMMENT=		Java DAAP client

NO_BUILD=		yes
WRKSRC=			${WRKDIR}
USE_JAVA=		run

INSTALLATION_DIRS=	bin

do-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}.jar ${WRKSRC}
	${SED} -e 's|@SH@|${SH}|g' -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/applerecords > ${WRKSRC}/applerecords

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/applerecords
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${PREFIX}/lib/applerecords/applerecords.jar
	${INSTALL_SCRIPT} ${WRKSRC}/applerecords ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
