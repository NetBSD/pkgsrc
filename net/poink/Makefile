# $NetBSD: Makefile,v 1.8 2005/06/17 03:50:27 jlam Exp $
#

DISTNAME=	poink-1.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	zuntum@NetBSD.org
COMMENT=	Nosuid, absolutely secure version of ping utility

NO_SRC_ON_FTP=	"Already in MASTER_SITE_LOCAL"

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/poink ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ping.1 ${PREFIX}/man/man1/poink.1

.include "../../mk/bsd.pkg.mk"
