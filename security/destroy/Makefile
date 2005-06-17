# $NetBSD: Makefile,v 1.5 2005/06/17 03:50:31 jlam Exp $
#

DISTNAME=	destroy-20040415
CATEGORIES=	security
MASTER_SITES=	http://www.freebsdhackers.net/destroy/ \
		http://www.impurity.org/mirrors/destroy/

MAINTAINER=	shane@freebsdhackers.net
HOMEPAGE=	http://www.freebsdhackers.net/destroy/
COMMENT=	A program to securely destroy files on the hard disk

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/destroy ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/destroy.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
