# $NetBSD: Makefile,v 1.19 2020/01/11 10:05:46 pho Exp $

DISTNAME=	pandoc-types-1.20
CATEGORIES=	textproc

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Types for representing a structured document
LICENSE=	gnu-gpl-v2

.include "../../mk/haskell.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
