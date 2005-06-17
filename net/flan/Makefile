# $NetBSD: Makefile,v 1.16 2005/06/17 03:50:25 jlam Exp $
#

DISTNAME=	Flan
PKGNAME=	flan-1.1rc1
CATEGORIES=	net java
MASTER_SITES=	http://picolibre.enst-bretagne.fr/projects/flan/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://picolibre.enst-bretagne.fr/projects/flan/index.html
COMMENT=	Simulator for IP networks written in Java

WRKSRC=			${WRKDIR}/src
USE_JAVA=		yes
PKG_JVMS_ACCEPTED=	sun-jdk13 sun-jdk14 jdk13 jdk14
USE_TOOLS+=		gmake
INSTALLATION_DIRS=	bin

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
