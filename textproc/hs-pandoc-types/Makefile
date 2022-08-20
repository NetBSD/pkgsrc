# $NetBSD: Makefile,v 1.26 2022/08/20 08:08:22 wiz Exp $

DISTNAME=	pandoc-types-1.22.1
PKGREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Types for representing a structured document
LICENSE=	gnu-gpl-v2

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
