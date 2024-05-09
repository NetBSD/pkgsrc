# $NetBSD: Makefile,v 1.4 2024/05/09 01:31:55 pho Exp $

DISTNAME=	foldable1-classes-compat-0.1
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Compatibility package for the Foldable1 and Bifoldable1 type classes
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	ghc-prim

.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
