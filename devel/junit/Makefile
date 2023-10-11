# $NetBSD: Makefile,v 1.1 2023/10/11 13:20:04 bouyer Exp $

VERSION=	4.13.2
DISTNAME=       junit-${VERSION}
CATEGORIES=     devel java
MASTER_SITES=   https://repo1.maven.org/maven2/junit/junit/${VERSION}/
EXTRACT_SUFX=   .jar

MAINTAINER=     pkgsrc-users@NetBSD.org
HOMEPAGE=       https://www.junit.org/
COMMENT=        Regression testing utility for use with the Java(TM) Language
LICENSE=        eclipse-v2.0

USE_JAVA=       run
USE_JAVA2=      7
NO_BUILD=       yes

INSTALLATION_DIRS=      lib/java/ant

DEPENDS+=       apache-ant>=1.5:../../devel/apache-ant

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}.jar ${DESTDIR}${PREFIX}/lib/java/ant/junit.jar
	${LN} -sf junit.jar ${DESTDIR}${PREFIX}/lib/java/ant/junit4.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
