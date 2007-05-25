# $NetBSD: Makefile,v 1.39 2007/05/25 02:41:25 rh Exp $
#

DISTNAME=	cgoban-java-3.3.17
PKGREVISION=	1
CATEGORIES=	games java
MASTER_SITES=	${MASTER_SITE_LOCAL}
# Mirrored from http://files.gokgs.com/javaBin/cgoban.jar
EXTRACT_SUFX=	.jar

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gokgs.com/
COMMENT=	Client for the Kiseido Go Server and SGF viewer/editor

WRKSRC=		${WRKDIR}
USE_JAVA=	run
USE_JAVA2=	yes
USE_TOOLS+=	printf

INSTALLATION_DIRS=	bin lib/java

do-build:
	printf "#! ${SH}\\nexec `${ECHO} '${PKG_JAVA_HOME}'-java |	\
		${SED}	-e 's/java/bin/'				\
			-e 's/-6/6/'					\
			-e 's/-1.5/15/'					\
			-e 's/-1.4/14/'					\
			-e 's/-1.3.[0-9]/13/'`				\
		-jar ${PREFIX}/lib/java/${DISTNAME}.jar \"\$$@\"\\n"	\
			> ${WRKSRC}/cgoban-java.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cgoban-java.sh ${PREFIX}/bin/cgoban-java
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${PREFIX}/lib/java/${DISTNAME}.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
