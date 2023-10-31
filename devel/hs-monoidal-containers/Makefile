# $NetBSD: Makefile,v 1.5 2023/10/31 02:53:31 pho Exp $

DISTNAME=	monoidal-containers-0.6.4.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Containers with monoidal accumulation
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	aeson

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
