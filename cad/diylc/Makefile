# $NetBSD: Makefile,v 1.1 2014/05/21 12:25:32 dsainty Exp $

DISTNAME=	diylc-3.28.0
CATEGORIES=	cad java
MASTER_SITES=	http://diy-layout-creator.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://code.google.com/p/diy-layout-creator/
COMMENT=	Simple electronic schematics CAD tool
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
USE_JAVA=	run

INSTALLATION_DIRS=	bin lib/java lib/java/diylc

do-build:
	set -e; \
	( \
	  cd "${WRKSRC}/lib"; unset cp; \
	  for jar in diylc.jar main.jar *.jar; do \
	    cp="$${cp}$${cp+:}${PREFIX}/lib/java/diylc/$${jar}"; \
	  done; \
	  ${ECHO} "#!${SH}"; ${ECHO} "exec ${JAVA_BINPREFIX}-java -Xms512m -Xmx2048m -Dorg.diylc.scriptRun=true -cp \"$${cp}\" org.diylc.DIYLCStarter \"\$$@\"" \
	) > ${WRKSRC}/diylc.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/diylc.sh \
		${DESTDIR}${PREFIX}/bin/diylc
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar \
		${DESTDIR}${PREFIX}/lib/java/diylc/
	${INSTALL_DATA} ${WRKSRC}/library/*.jar \
		${DESTDIR}${PREFIX}/lib/java/diylc/
	${INSTALL_DATA} ${WRKSRC}/diylc.jar \
		${DESTDIR}${PREFIX}/lib/java/diylc/diylc.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
