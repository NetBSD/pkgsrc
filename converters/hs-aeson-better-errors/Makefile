# $NetBSD: Makefile,v 1.5 2022/09/07 06:50:44 pho Exp $

DISTNAME=	aeson-better-errors-0.9.1.1
PKGREVISION=	1
CATEGORIES=	converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Better error messages when decoding JSON values
LICENSE=	mit

# Relax version constraints.
SUBST_CLASSES+=		cabal
SUBST_STAGE.cabal=	post-extract
SUBST_FILES.cabal=	aeson-better-errors.cabal
SUBST_SED.cabal=	-e 's/aeson >=0.7 && <1.6 || >=2.0 && <2.1/aeson/'

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-void/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
