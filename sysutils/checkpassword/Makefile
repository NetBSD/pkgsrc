# $NetBSD: Makefile,v 1.1.1.1 2001/08/13 10:29:54 zuntum Exp $
#

DISTNAME=	checkpassword-0.90
CATEGORIES=	sysutils
MASTER_SITES=	http://cr.yp.to/checkpwd/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://cr.yp.to/checkpwd.html
COMMENT=	simple, uniform password-checking interface to all root applications

ALL_TARGET=	#
INSTALL_TARGET=	setup check

post-patch:
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home

.include "../../mk/bsd.pkg.mk"
