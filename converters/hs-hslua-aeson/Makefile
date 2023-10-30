# $NetBSD: Makefile,v 1.8 2023/10/30 13:24:57 pho Exp $

DISTNAME=	hslua-aeson-2.3.0.1
CATEGORIES=	converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Allow aeson data types to be used with Lua
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	aeson

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../lang/hs-hslua-core/buildlink3.mk"
.include "../../lang/hs-hslua-marshalling/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
