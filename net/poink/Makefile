# $NetBSD: Makefile,v 1.3 2001/09/15 13:52:27 zuntum Exp $
#

DISTNAME=	poink-1.5
CATEGORIES=	net
MASTER_SITES=	http://zuntum.utech.lublin.pl/distfiles/

MAINTAINER=	zuntum@netbsd.org
COMMENT=	nosuid, absolutely secure version of ping utility

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/poink ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ping.1 ${PREFIX}/man/man1/poink.1

.include "../../mk/bsd.pkg.mk"
