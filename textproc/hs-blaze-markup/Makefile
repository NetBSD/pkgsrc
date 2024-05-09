# $NetBSD: Makefile,v 1.23 2024/05/09 01:32:39 pho Exp $

DISTNAME=	blaze-markup-0.8.3.0
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Blazingly fast markup combinator library for Haskell
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	text

.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
