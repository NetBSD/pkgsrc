# $NetBSD: Makefile,v 1.1.1.1 2004/06/06 07:20:12 agc Exp $
#

DISTNAME=		applerecords
PKGNAME=		applerecords-0.4
CATEGORIES=		audio
MASTER_SITES=		http://www.cdavies.org/code/
EXTRACT_SUFX=		.jar

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.cdavies.org/applerecords.html
COMMENT=		Java DAAP client

DIST_SUBDIR=		${PKGNAME}
NO_BUILD=		# defined
WRKSRC=			${WRKDIR}
USE_JAVA=		run

do-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/applerecords.jar ${WRKSRC}
	${SED} -e 's|@SH@|${SH}|g' -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/applerecords > ${WRKSRC}/applerecords

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/applerecords
	${INSTALL_DATA} ${WRKSRC}/applerecords.jar ${PREFIX}/lib/applerecords/applerecords.jar
	${INSTALL_SCRIPT} ${WRKSRC}/applerecords ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
