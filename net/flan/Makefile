# $NetBSD: Makefile,v 1.2 2002/07/24 13:47:36 schmonz Exp $
#

DISTNAME=	Flan
PKGNAME=	flan-1.1rc1
CATEGORIES=	net
MASTER_SITES=	http://picolibre.enst-bretagne.fr/projects/flan/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://picolibre.enst-bretagne.fr/projects/flan/index.html
COMMENT=	Simulator for IP networks writen in Java

USE_JAVA=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/src

post-build:
	cd ${WRKSRC} ; ${JAVA_HOME}/bin/jar cf flan.jar flan/ graphic/
	${SED} -e 's,@JAVA_HOME@,${JAVA_HOME},g'			\
		-e 's,@PREFIX@,${PREFIX},g'				\
		< ${FILESDIR}/flan > ${WRKDIR}/flan

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java/flan
	${INSTALL_DATA} ${WRKSRC}/xmlcode.jar ${PREFIX}/lib/java/flan
	${INSTALL_DATA} ${WRKSRC}/xalan2.jar ${PREFIX}/lib/java/flan
	${INSTALL_DATA} ${WRKSRC}/crimson.jar ${PREFIX}/lib/java/flan
	${INSTALL_DATA} ${WRKSRC}/flan.jar ${PREFIX}/lib/java/flan
	${INSTALL_SCRIPT} ${WRKDIR}/flan ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
