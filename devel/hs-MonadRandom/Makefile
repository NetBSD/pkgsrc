# $NetBSD: Makefile,v 1.21 2026/11/13 14:38:45 pho Exp $

DISTNAME=	MonadRandom-0.6
PKGREVISION=	8
CATEGORIES=	devel

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Random-number generation monad
LICENSE=	2-clause-bsd
# http://www.haskell.org/haskellwiki/HaskellWiki:Copyrights

BROKEN+=	"Broken due to an incompatibility with random-1.3.0: https://github.com/byorgey/MonadRandom/issues/54"

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
