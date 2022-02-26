# $NetBSD: Makefile,v 1.2 2022/02/26 03:57:55 pho Exp $

DISTNAME=	ghc-check-0.5.0.6
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
