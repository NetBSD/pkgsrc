# $NetBSD: Makefile,v 1.3 2004/04/15 22:07:20 recht Exp $
#

DISTNAME=	destroy-20040415
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
