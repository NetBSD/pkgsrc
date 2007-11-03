# $NetBSD: Makefile,v 1.44 2007/11/03 00:19:52 rillig Exp $
#

DISTNAME=	cgoban-java-3.3.20
CATEGORIES=	games java
MASTER_SITES=	${MASTER_SITE_LOCAL}
# Mirrored from http://files.gokgs.com/javaBin/cgoban.jar
EXTRACT_SUFX=	.jar

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gokgs.com/
COMMENT=	Client for the KGS Go Server and SGF viewer/editor

WRKSRC=		${WRKDIR}
USE_JAVA=	run
USE_JAVA2=	yes
USE_TOOLS+=	printf

INSTALLATION_DIRS=	bin lib/java

do-build:
	printf "#! ${SH}\\nexec ${JAVA_BINPREFIX}-java -jar ${PREFIX}/lib/java/${DISTNAME}.jar \"\$$@\"\\n" > ${WRKSRC}/cgoban-java.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cgoban-java.sh ${PREFIX}/bin/cgoban-java
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${PREFIX}/lib/java/${DISTNAME}.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
