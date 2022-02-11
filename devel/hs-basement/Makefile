# $NetBSD: Makefile,v 1.7 2022/02/11 09:28:47 pho Exp $

DISTNAME=	basement-0.0.12
CATEGORIES=	devel

# Compatibility with GHC 9.2:
# https://github.com/haskell-foundation/foundation/issues/554
PATCH_SITES=		https://gitlab.haskell.org/ghc/head.hackage/-/raw/dfd024c9a336c752288ec35879017a43bd7e85a0/patches/
PATCHFILES=		basement-0.0.12.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	pho@cielonegro.org
COMMENT=	Foundation scrap box of array and string
LICENSE=	modified-bsd

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
