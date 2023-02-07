# $NetBSD: Makefile,v 1.15 2023/02/07 01:40:37 pho Exp $

DISTNAME=	hint-0.9.0.5
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Runtime Haskell interpreter (GHC API wrapper)
LICENSE=	modified-bsd

BROKEN+=	"It is incompatible with GHC 9.4. Work is underway: https://github.com/haskell-beam/beam/issues/649"

.include "../../mk/haskell.mk"
.include "../../devel/hs-ghc-paths/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
