# $NetBSD: Makefile,v 1.4 2002/12/31 15:44:28 jlam Exp $
#

DISTNAME=	sablecc-2.16.2
CATEGORIES=	devel
MASTER_SITES=	http://dl.sourceforge.net/sourceforge/sablecc/

MAINTAINER=	hag@linnaean.org
HOMEPAGE=	http://www.sablecc.org/
COMMENT=	Java based Compiler Compiler

USE_JAVA=	run
USE_JAVA2=	yes

do-build:
	${SED}	-e 's,@PREFIX@,${PREFIX},g'				\
		-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g'			\
		< ${FILESDIR}/sablecc > ${WRKDIR}/sablecc

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/sablecc ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/lib/sablecc.jar ${PREFIX}/lib/java

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
