# $NetBSD: Makefile,v 1.4 2004/06/17 12:46:08 grant Exp $
#

DISTNAME=	checkpassword-0.90
CATEGORIES=	sysutils
MASTER_SITES=	http://cr.yp.to/checkpwd/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://cr.yp.to/checkpwd.html
COMMENT=	Simple, uniform password-checking interface to all root applications

ALL_TARGET=	#
INSTALL_TARGET=	setup check

post-patch:
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home
	${ECHO} ${CC} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} > ${WRKSRC}/conf-ld

post-install:
	${CHMOD} +x ${PREFIX}/bin/checkpassword

.include "../../mk/bsd.pkg.mk"
