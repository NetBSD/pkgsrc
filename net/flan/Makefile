# $NetBSD: Makefile,v 1.1.1.1 2002/07/24 11:59:01 agc Exp $
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

post-build:
	cd ${WRKSRC} ; ${PREFIX}/java/bin/jar cf flan.jar flan/ graphic/
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/flan > ${WRKDIR}/flan

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java/flan
	${INSTALL_DATA} ${WRKSRC}/xmlcode.jar ${PREFIX}/lib/java/flan
	${INSTALL_DATA} ${WRKSRC}/xalan2.jar ${PREFIX}/lib/java/flan
	${INSTALL_DATA} ${WRKSRC}/crimson.jar ${PREFIX}/lib/java/flan
	${INSTALL_DATA} ${WRKSRC}/flan.jar ${PREFIX}/lib/java/flan
	${INSTALL_SCRIPT} ${WRKDIR}/flan ${PREFIX}/bin

WRKSRC=		${WRKDIR}/src

.include "../../mk/bsd.pkg.mk"
