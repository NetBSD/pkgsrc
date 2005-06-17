# $NetBSD: Makefile,v 1.3 2005/06/17 03:50:34 jlam Exp $
#

DISTNAME=		news-0.2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.netmeister.org/apps/

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://www.netmeister.org/
COMMENT=		System V news(1)

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/news ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/news.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
