# $NetBSD: Makefile,v 1.1.1.1 2002/09/18 10:46:17 agc Exp $
#

DISTNAME=	sablecc-2.16.2
CATEGORIES=	devel
MASTER_SITES=	http://dl.sourceforge.net/sourceforge/sablecc/

MAINTAINER=	hag@linnaean.org
HOMEPAGE=	http://www.sablecc.org/
COMMENT=	Java based Compiler Compiler

USE_JAVA=	yes
PKG_JVM=	sun-jdk

WRKSRC=		${WRKDIR}/sablecc-2.16.2

do-build:
	${SED} -e 's,@PREFIX@,${PREFIX},g' -e 's,@JAVA_HOME@,${JAVA_HOME},g' \
		< ${FILESDIR}/sablecc > ${WRKDIR}/sablecc

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/sablecc ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/lib/sablecc.jar ${PREFIX}/lib/java

.include "../../mk/bsd.pkg.mk"
