# $NetBSD: Makefile,v 1.1.1.1 2004/09/20 21:16:06 jschauma Exp $
#

DISTNAME=		news-0.1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.netmeister.org/apps/

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://www.netmeister.org/
COMMENT=		System V news(1)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/news ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/news.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
