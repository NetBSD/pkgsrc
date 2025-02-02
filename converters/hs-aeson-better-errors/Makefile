# $NetBSD: Makefile,v 1.11 2025/02/02 13:04:50 pho Exp $

DISTNAME=	aeson-better-errors-0.9.1.1
PKGREVISION=	6
CATEGORIES=	converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Better error messages when decoding JSON values
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	aeson

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-void/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
