# $NetBSD: Makefile,v 1.1 2020/01/16 15:02:50 pho Exp $

DISTNAME=	jira-wiki-markup-1.0.0
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Handle Jira wiki markup
LICENSE=	mit

post-patch:
	${RUN}${CP} -f ${FILESDIR}/Setup.hs ${WRKSRC}/

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
