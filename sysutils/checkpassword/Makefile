# $NetBSD: Makefile,v 1.5 2004/07/22 01:07:24 schmonz Exp $
#

DISTNAME=	checkpassword-0.90
CATEGORIES=	sysutils
MASTER_SITES=	http://cr.yp.to/checkpwd/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://cr.yp.to/checkpwd.html
COMMENT=	Simple, uniform password-checking interface to all root applications

ALL_TARGET=	it
INSTALL_TARGET=	setup check

do-configure:
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld

post-install:
	${CHMOD} +x ${PREFIX}/bin/checkpassword

.include "../../mk/bsd.pkg.mk"
