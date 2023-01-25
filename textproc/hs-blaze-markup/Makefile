# $NetBSD: Makefile,v 1.18 2023/01/25 03:45:55 pho Exp $

DISTNAME=	blaze-markup-0.8.2.8
PKGREVISION=	4
CATEGORIES=	textproc

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Blazingly fast markup combinator library for Haskell
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	text

.include "../../mk/haskell.mk"
.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
