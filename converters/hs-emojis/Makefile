# $NetBSD: Makefile,v 1.1 2020/01/15 11:53:16 pho Exp $

DISTNAME=	emojis-0.1
CATEGORIES=	converters

MAINTAINER=	pho@cielonegro.org
COMMENT=	Conversion between emoji characters and their names
LICENSE=	modified-bsd

post-patch:
	${RUN}${CP} -f ${FILESDIR}/Setup.hs ${WRKSRC}/

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
