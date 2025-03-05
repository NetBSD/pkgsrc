# $NetBSD: Makefile,v 1.36 2025/03/05 03:40:00 pho Exp $

DISTNAME=	pandoc-types-1.23.1
PKGREVISION=	4
CATEGORIES=	textproc converters

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Types for representing a structured document
LICENSE=	gnu-gpl-v2

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	QuickCheck	\
	deepseq

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
