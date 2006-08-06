# $NetBSD: Makefile,v 1.1.1.1 2006/08/06 17:37:21 wiz Exp $
#

DISTNAME=		jing-20030619
CATEGORIES=		textproc
MASTER_SITES=		http://www.thaiopensource.com/download/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.thaiopensource.com/relaxng/trang.html
COMMENT=		RELAX NG validator in Java

USE_JAVA=		run
USE_JAVA2=		1.4

do-build:
	${ECHO} "#!/bin/sh" > ${WRKSRC}/jing
	${ECHO} "${PKG_JAVA_HOME}/bin/java -jar ${PREFIX}/libexec/jing/jing.jar"' "$$@"' >> ${WRKSRC}/jing

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jing ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/jing
	${INSTALL_DATA} ${WRKSRC}/bin/* ${PREFIX}/libexec/jing
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/jing/lib
	${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/libexec/jing/lib
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jing
	${INSTALL_DATA} ${WRKSRC}/readme.html ${PREFIX}/share/doc/jing
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jing/doc
	cd ${WRKSRC}/doc && ${PAX} -pp -rw * ${PREFIX}/share/doc/jing/doc

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
