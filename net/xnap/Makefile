# $NetBSD: Makefile,v 1.1.1.1 2002/04/28 22:15:14 hubertf Exp $
#

DISTNAME=	xnap-2.0
CATEGORIES=	net
MASTER_SITES=	http://telia.dl.sourceforge.net/xnap/

MAINTAINER=	Benjamin.Wong@cc.gatech.edu
HOMEPAGE=	http://xnap.sourceforge.net/
COMMENT=	Java filesharing client with support for OpenNap

DEPENDS=        sun-jdk-[0-9]*:../../lang/sun-jdk13

NO_BUILD=       yes

do-install:
	${CP} ${WRKSRC}/xnap.sh ${PREFIX}/bin/xnap
	${INSTALL_PROGRAM_DIR} ${PREFIX}/share/xnap
	${CP} ${WRKSRC}/xnap.jar ${PREFIX}/share/xnap/xnap.jar
	${INSTALL_PROGRAM_DIR} ${PREFIX}/share/doc/xnap
	${CP} ${WRKSRC}/README ${PREFIX}/share/doc/xnap
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/xnap ${PREFIX}/share/doc/xnap

.include "../../mk/bsd.pkg.mk"
