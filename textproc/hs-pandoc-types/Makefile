# $NetBSD: Makefile,v 1.37 2025/08/13 11:07:33 pho Exp $

DISTNAME=	pandoc-types-1.23.1
PKGREVISION=	5
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
