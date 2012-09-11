# $NetBSD: Makefile,v 1.9 2012/09/11 23:59:24 asau Exp $
#

DISTNAME=		applerecords-0.5
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		#
EXTRACT_SUFX=		.jar

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://web.archive.org/web/20060501054520/http://www.cdavies.org/applerecords.html
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
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/applerecords
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar \
		${DESTDIR}${PREFIX}/lib/applerecords/applerecords.jar
	${INSTALL_SCRIPT} ${WRKSRC}/applerecords ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
