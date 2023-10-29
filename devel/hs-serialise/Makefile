# $NetBSD: Makefile,v 1.8 2023/10/29 07:26:45 pho Exp $

DISTNAME=	serialise-0.2.6.0
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Binary serialisation library for Haskell values
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	ghc-prim	\
	primitive	\
	strict	\
	these	\
	vector

.include "../../devel/hs-cborg/buildlink3.mk"
.include "../../devel/hs-half/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-strict/buildlink3.mk"
.include "../../devel/hs-these/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
