# $NetBSD: Makefile,v 1.24 2025/02/02 13:05:50 pho Exp $

DISTNAME=	blaze-markup-0.8.3.0
PKGREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Blazingly fast markup combinator library for Haskell
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	text

.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
