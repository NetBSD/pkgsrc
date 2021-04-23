# $NetBSD: Makefile,v 1.1 2021/04/23 08:07:25 pho Exp $

DISTNAME=	assoc-1.0.2
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Symmetric and Semigroupy Bifunctors
LICENSE=	modified-bsd

# Setup.hs is missing from the package.
post-patch:
	${CP} -f ${FILESDIR}/Setup.hs ${WRKSRC}/Setup.hs

.include "../../mk/haskell.mk"
.include "../../math/hs-bifunctors/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
