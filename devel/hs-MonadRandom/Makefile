# $NetBSD: Makefile,v 1.3 2020/01/01 03:33:07 pho Exp $

DISTNAME=	MonadRandom-0.3
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Random-number generation monad
LICENSE=	2-clause-bsd
# http://www.haskell.org/haskellwiki/HaskellWiki:Copyrights

.include "../../mk/haskell.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../devel/hs-fail/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
