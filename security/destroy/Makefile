# $NetBSD: Makefile,v 1.2 2004/03/12 18:01:57 recht Exp $
#

DISTNAME=	destroy-20040310
CATEGORIES=	security
MASTER_SITES=	http://www.freebsdhackers.net/destroy/ \
		http://www.impurity.org/mirrors/destroy/

MAINTAINER=	shane@freebsdhackers.net
HOMEPAGE=	http://www.freebsdhackers.net/destroy/
COMMENT=	A program to securely destroy files on the hard disk

USE_BUILDLINK3=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/destroy ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/destroy.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
