# $NetBSD: Makefile,v 1.2 2002/04/30 14:42:38 jwise Exp $
#

DISTNAME=	xnap-2.0
CATEGORIES=	net
MASTER_SITES=	http://telia.dl.sourceforge.net/xnap/

MAINTAINER=	Benjamin.Wong@cc.gatech.edu
HOMEPAGE=	http://xnap.sourceforge.net/
COMMENT=	Java filesharing client with support for OpenNap

USE_JAVA=	yes
NO_BUILD=       yes

do-install:
	${CP} ${WRKSRC}/xnap.sh ${PREFIX}/bin/xnap
	${INSTALL_PROGRAM_DIR} ${PREFIX}/share/xnap
	${CP} ${WRKSRC}/xnap.jar ${PREFIX}/share/xnap/xnap.jar
	${INSTALL_PROGRAM_DIR} ${PREFIX}/share/doc/xnap
	${CP} ${WRKSRC}/README ${PREFIX}/share/doc/xnap
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/xnap ${PREFIX}/share/doc/xnap

.include "../../mk/bsd.pkg.mk"
.if ${PKG_JVM} == "jdk" || ${PKG_JVM} == "kaffe"
DEPENDS+=	swing-[0-9]*:../../x11/swing
.endif
