# $NetBSD: Makefile,v 1.5 2003/07/12 00:51:12 zuntum Exp $
#

DISTNAME=	poink-1.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	zuntum@netbsd.org
COMMENT=	nosuid, absolutely secure version of ping utility

NO_SRC_ON_FTP=	"Already in MASTER_SITE_LOCAL"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/poink ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ping.1 ${PREFIX}/man/man1/poink.1

.include "../../mk/bsd.pkg.mk"
