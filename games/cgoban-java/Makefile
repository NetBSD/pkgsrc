# $NetBSD: Makefile,v 1.35 2006/10/16 10:46:53 salo Exp $
#

DISTNAME=	cgoban-java-3.3.8
MASTER_SITES=	http://files.gokgs.com/javaBin/
DISTFILES=	cgoban.jar
DIST_SUBDIR=	${DISTNAME}
CATEGORIES=	games java

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://kgs.kiseido.com/en_US/download.html
COMMENT=	Client for the Kiseido Go Server and SGF viewer/editor

WRKSRC=		${WRKDIR}
USE_JAVA=	run
USE_JAVA2=	yes
USE_TOOLS+=	printf

INSTALLATION_DIRS=	bin lib/java

do-build:
	${PRINTF} "#! ${SH}\\nexec ${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/lib/java/${PKGNAME}.jar \"\$$@\"\\n" > ${WRKSRC}/cgoban-java.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cgoban-java.sh ${PREFIX}/bin/cgoban-java
	${INSTALL_DATA} ${WRKSRC}/cgoban.jar ${PREFIX}/lib/java/${PKGNAME}.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
