# $NetBSD: Makefile,v 1.21 2021/05/03 19:01:16 pho Exp $

DISTNAME=	pandoc-types-1.22
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Types for representing a structured document
LICENSE=	gnu-gpl-v2

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
