# $NetBSD: Makefile,v 1.1.1.1 2001/04/03 11:29:34 zuntum Exp $
#

DISTNAME=	poink-1.5
CATEGORIES=	net
MASTER_SITES=	http://zuntum.net/distfiles/

MAINTAINER=	zuntum@netbsd.org
COMMENT=	nosuid, absolutery secure version of ping utility

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/poink ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ping.1 ${PREFIX}/man/man1/poink.1

.include "../../mk/bsd.pkg.mk"
