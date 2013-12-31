# $NetBSD: Makefile,v 1.6 2013/12/31 22:12:03 ryoon Exp $
#

DISTNAME=	jflex-1.4.3
CATEGORIES=	devel
MASTER_SITES=	http://jflex.de/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jflex.de/
COMMENT=	Fast lexical analyzer generator for Java

USE_LANGUAGES=	# none
USE_JAVA=	run
USE_TOOLS+=	pax

INSTALLATION_DIRS=	bin lib/java share/doc/jflex share/examples/jflex

do-build:
	printf "#! ${SH}\\nexec ${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/lib/java/JFlex.jar \"\$$@\"\\n" > ${WRKSRC}/jflex.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jflex.sh ${DESTDIR}${PREFIX}/bin/jflex
	${INSTALL_DATA} ${WRKSRC}/lib/JFlex.jar ${DESTDIR}${PREFIX}/lib/java/
	cd ${WRKSRC}/doc && pax -wr -pm * ${DESTDIR}${PREFIX}/share/doc/jflex
	cd ${WRKSRC}/examples && pax -wr -pm * \
		${DESTDIR}${PREFIX}/share/examples/jflex

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
