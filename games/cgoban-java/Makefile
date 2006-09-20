# $NetBSD: Makefile,v 1.32 2006/09/20 23:07:12 rillig Exp $
#

DISTNAME=	cgoban-java-3.3.1
CATEGORIES=	games java
MASTER_SITES=	http://files.gokgs.com/javaBin/
DISTFILES=	cgoban.jar
DIST_SUBDIR=	${DISTNAME}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://kgs.kiseido.com/en_US/download.html
COMMENT=	Client for the Kiseido Go Server and SGF viewer/editor

WRKSRC=		${WRKDIR}
USE_JAVA=	run
USE_JAVA2=	yes

INSTALLATION_DIRS=	bin libexec

do-build:
	printf "#! ${SH}\\nexec ${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/libexec/cgoban3.jar \"\$$@\"\\n" > ${WRKSRC}/cgoban-java.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cgoban-java.sh ${PREFIX}/bin/cgoban-java
	${INSTALL_DATA} ${WRKSRC}/cgoban.jar ${PREFIX}/libexec/cgoban3.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
