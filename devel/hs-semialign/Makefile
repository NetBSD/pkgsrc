# $NetBSD: Makefile,v 1.16 2026/11/13 14:39:16 pho Exp $

DISTNAME=	semialign-1.3.1
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Align and Zip type-classes from the common Semialign ancestor
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	hashable

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-indexed-traversable/buildlink3.mk"
.include "../../devel/hs-indexed-traversable-instances/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-these/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
