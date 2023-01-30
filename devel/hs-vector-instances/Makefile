# $NetBSD: Makefile,v 1.4 2023/01/30 03:18:36 pho Exp $

DISTNAME=	vector-instances-3.4
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Orphan Instances for 'Data.Vector'
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	vector

.include "../../math/hs-comonad/buildlink3.mk"
.include "../../devel/hs-keys/buildlink3.mk"
.include "../../devel/hs-pointed/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
