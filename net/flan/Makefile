# $NetBSD: Makefile,v 1.11 2004/01/24 14:50:05 grant Exp $
#

DISTNAME=	Flan
PKGNAME=	flan-1.1rc1
CATEGORIES=	net java
MASTER_SITES=	http://picolibre.enst-bretagne.fr/projects/flan/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://picolibre.enst-bretagne.fr/projects/flan/index.html
COMMENT=	Simulator for IP networks writen in Java

WRKSRC=		${WRKDIR}/src
PKG_JVM=	sun-jdk13
USE_GNU_TOOLS+=	make

post-build:
	cd ${WRKSRC} ; ${PKG_JAVA_HOME}/bin/jar cf flan.jar flan/ graphic/
	${SED} -e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g'			\
		-e 's,@PREFIX@,${PREFIX},g'				\
		< ${FILESDIR}/flan > ${WRKDIR}/flan

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java/flan
	${INSTALL_DATA} ${WRKSRC}/xmlcode.jar ${PREFIX}/lib/java/flan
	${INSTALL_DATA} ${WRKSRC}/xalan2.jar ${PREFIX}/lib/java/flan
	${INSTALL_DATA} ${WRKSRC}/crimson.jar ${PREFIX}/lib/java/flan
	${INSTALL_DATA} ${WRKSRC}/flan.jar ${PREFIX}/lib/java/flan
	${INSTALL_SCRIPT} ${WRKDIR}/flan ${PREFIX}/bin

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
