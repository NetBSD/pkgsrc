# $NetBSD: Makefile,v 1.18 2020/01/02 14:41:22 pho Exp $

DISTNAME=	pandoc-types-1.17.6.1
CATEGORIES=	textproc

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Types for representing a structured document
LICENSE=	gnu-gpl-v2

.include "../../mk/haskell.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
