# $NetBSD: Makefile,v 1.3 2021/04/24 15:40:07 pho Exp $

DISTNAME=	jira-wiki-markup-1.3.4
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Handle Jira wiki markup
LICENSE=	mit

post-patch:
	${RUN}${CP} -f ${FILESDIR}/Setup.hs ${WRKSRC}/

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
