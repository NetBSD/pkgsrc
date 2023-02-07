# $NetBSD: Makefile,v 1.4 2023/02/07 01:40:35 pho Exp $

DISTNAME=	ghc-check-0.5.0.8
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Detect mismatches between compile and run-time versions of the GHC API
LICENSE=	modified-bsd

.include "../../devel/hs-ghc-paths/buildlink3.mk"
.include "../../devel/hs-safe-exceptions/buildlink3.mk"
.include "../../devel/hs-th-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
