# $NetBSD: Makefile,v 1.7 2024/05/09 01:32:28 pho Exp $

# NOTE: Cannot update to >=3.10.3.0 because they depend on GHC 10.
DISTNAME=	cabal-install-solver-3.10.2.1
PKGREVISION=	1
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Solver component used in cabal-install command-line program
LICENSE=	modified-bsd

.include "../../textproc/hs-edit-distance/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
