# $NetBSD: Makefile,v 1.33 2006/10/07 10:08:31 rillig Exp $
#

DISTNAME=	cgoban-java-3.3.5
CATEGORIES=	games java
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.jar

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://kgs.kiseido.com/en_US/download.html
COMMENT=	Client for the Kiseido Go Server and SGF viewer/editor

WRKSRC=		${WRKDIR}
USE_JAVA=	run
USE_JAVA2=	yes
USE_TOOLS+=	printf

INSTALLATION_DIRS=	bin lib/java

do-build:
	printf "#! ${SH}\\nexec ${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/lib/java/${DISTFILE}.jar \"\$$@\"\\n" > ${WRKSRC}/cgoban-java.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cgoban-java.sh ${PREFIX}/bin/cgoban-java
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${PREFIX}/lib/java/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
