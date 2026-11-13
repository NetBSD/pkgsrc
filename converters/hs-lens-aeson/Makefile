# $NetBSD: Makefile,v 1.14 2026/11/13 14:38:42 pho Exp $

DISTNAME=	lens-aeson-1.2.3
PKGREVISION=	6
CATEGORIES=	converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Law-abiding lenses for aeson
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	bytestring	\
	text

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../textproc/hs-text-short/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
