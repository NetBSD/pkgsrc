# $NetBSD: Makefile,v 1.26 2025/08/13 11:07:28 pho Exp $

DISTNAME=	blaze-markup-0.8.3.0
PKGREVISION=	4
CATEGORIES=	textproc

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Blazingly fast markup combinator library for Haskell
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	text

.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
