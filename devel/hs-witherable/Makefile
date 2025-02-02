# $NetBSD: Makefile,v 1.12 2025/02/02 13:05:31 pho Exp $

DISTNAME=	witherable-0.5
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Filterable traversable
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	hashable

.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-indexed-traversable/buildlink3.mk"
.include "../../devel/hs-indexed-traversable-instances/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
