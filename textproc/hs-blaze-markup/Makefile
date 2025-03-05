# $NetBSD: Makefile,v 1.25 2025/03/05 03:39:55 pho Exp $

DISTNAME=	blaze-markup-0.8.3.0
PKGREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Blazingly fast markup combinator library for Haskell
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	text

.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
