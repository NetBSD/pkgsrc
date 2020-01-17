# $NetBSD: Makefile,v 1.2 2020/01/17 07:14:22 pho Exp $

DISTNAME=	jira-wiki-markup-1.0.0
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Handle Jira wiki markup
LICENSE=	mit

post-patch:
	${RUN}${CP} -f ${FILESDIR}/Setup.hs ${WRKSRC}/

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
