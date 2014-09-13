# $NetBSD: Makefile,v 1.2 2014/09/13 22:23:28 szptvlfn Exp $

DISTNAME=	pandoc-types-1.12.4.1
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Types for representing a structured document
LICENSE=	gnu-gpl-v2

.include "../../mk/haskell.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-deepseq-generics/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
