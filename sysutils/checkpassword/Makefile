# $NetBSD: Makefile,v 1.2 2003/07/17 22:53:29 grant Exp $
#

DISTNAME=	checkpassword-0.90
CATEGORIES=	sysutils
MASTER_SITES=	http://cr.yp.to/checkpwd/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://cr.yp.to/checkpwd.html
COMMENT=	simple, uniform password-checking interface to all root applications

ALL_TARGET=	#
INSTALL_TARGET=	setup check

post-patch:
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home

.include "../../mk/bsd.pkg.mk"
