# $NetBSD: Makefile,v 1.1 2021/04/23 07:41:59 pho Exp $

DISTNAME=	indexed-traversable-0.1.1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	FunctorWithIndex, FoldableWithIndex, TraversableWithIndex
LICENSE=	2-clause-bsd

# Setup.hs is missing from the package.
post-patch:
	${CP} -f ${FILESDIR}/Setup.hs ${WRKSRC}/Setup.hs

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
