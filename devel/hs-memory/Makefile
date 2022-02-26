# $NetBSD: Makefile,v 1.6 2022/02/26 03:58:01 pho Exp $

DISTNAME=	memory-0.16.0
PKGREVISION=	2
CATEGORIES=	devel

# Compatibility with GHC 9.2:
# https://github.com/vincenthz/hs-memory/issues/86
PATCH_SITES=		https://gitlab.haskell.org/ghc/head.hackage/-/raw/c50d7587a23ef1260721e84f8bcc1450d73177db/patches/
PATCHFILES=		memory-0.16.0.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	pho@cielonegro.org
COMMENT=	Memory and related abstraction stuff
LICENSE=	modified-bsd

.include "../../devel/hs-basement/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
