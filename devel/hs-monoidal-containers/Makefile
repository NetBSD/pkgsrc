# $NetBSD: Makefile,v 1.1 2022/09/07 02:57:02 pho Exp $

DISTNAME=	monoidal-containers-0.6.2.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Containers with monoidal accumulation
LICENSE=	modified-bsd

# Relax version constraints
SUBST_CLASSES+=		cabal
SUBST_STAGE.cabal=	post-extract
SUBST_FILES.cabal=	monoidal-containers.cabal
SUBST_SED.cabal=	-e 's/aeson *>=1.0 *&& <2.1/aeson/'
SUBST_SED.cabal+=	-e 's/base *>=4.7 *&& <4.16/base/'
SUBST_SED.cabal+=	-e 's/lens *>=4.4 *&& <5.2/lens/'

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-newtype/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-witherable/buildlink3.mk"
.include "../../devel/hs-semialign/buildlink3.mk"
.include "../../devel/hs-these/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
