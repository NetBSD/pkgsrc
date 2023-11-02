# $NetBSD: Makefile,v 1.32 2023/11/02 06:37:34 pho Exp $

DISTNAME=	pandoc-types-1.23.1
PKGREVISION=	1
CATEGORIES=	textproc converters

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Types for representing a structured document
LICENSE=	gnu-gpl-v2

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
