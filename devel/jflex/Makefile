# $NetBSD: Makefile,v 1.1.1.1 2007/02/22 08:24:44 rillig Exp $
#

DISTNAME=	jflex-1.4.1
CATEGORIES=	devel
MASTER_SITES=	http://jflex.de/

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://jflex.de/
COMMENT=	Fast lexical analyzer generator for Java

USE_LANGUAGES=	# none
USE_JAVA=	run

INSTALLATION_DIRS=	bin lib/java share/doc/jflex share/examples/jflex

do-build:
	printf "#! ${SH}\\nexec ${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/lib/java/JFlex.jar \"\$$@\"\\n" > ${WRKSRC}/jflex.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jflex.sh ${PREFIX}/bin/jflex
	${INSTALL_DATA} ${WRKSRC}/lib/JFlex.jar ${PREFIX}/lib/java/
	cd ${WRKSRC}/doc && pax -wr -pm * ${PREFIX}/share/doc/jflex
	cd ${WRKSRC}/examples && pax -wr -pm * ${PREFIX}/share/examples/jflex

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
