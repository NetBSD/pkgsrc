# $NetBSD: Makefile,v 1.1.1.1 2001/10/17 12:32:17 agc Exp $
#

DISTNAME=	javadeps-1.1
CATEGORIES=	devel
MASTER_SITES=	http://www.vet.com.au/java/javadeps/
EXTRACT_SUFX=	.zip

MAINTAINER=	ben@wongs.net
HOMEPAGE=	http://www.vet.com.au/java/javadeps/
COMMENT=	Automatic dependency tracking for Java

DEPENDS=	sun-jdk-[0-9]*:../../lang/sun-jdk13

WRKSRC=		${WRKDIR}/JavaDeps-1.1

NO_BUILD=	yes

do-install:
	${CP} ${WRKSRC}/jdeps ${PREFIX}/bin
	${INSTALL_PROGRAM_DIR} ${PREFIX}/share/jdeps
	${CP} ${WRKSRC}/jdeps.jar ${PREFIX}/share/jdeps/jdeps.jar
	${INSTALL_PROGRAM_DIR} ${PREFIX}/share/doc/jdeps
	cd ${WRKSRC}/doc; ${PAX} -rwpe . ${PREFIX}/share/doc/jdeps
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/jdeps ${PREFIX}/share/doc/jdeps

.include "../../mk/bsd.pkg.mk"
