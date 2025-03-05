# $NetBSD: Makefile,v 1.10 2025/03/05 03:39:45 pho Exp $

DISTNAME=	cabal-install-solver-3.12.1.0
PKGREVISION=	2
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Solver component used in cabal-install command-line program
LICENSE=	modified-bsd

# There is no version supporting Cabal-3.12.0.0 that comes with GHC 9.10.1.
HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	Cabal	\
	Cabal-syntax

.include "../../textproc/hs-edit-distance/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
