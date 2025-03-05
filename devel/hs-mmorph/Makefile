# $NetBSD: Makefile,v 1.19 2025/03/05 03:39:20 pho Exp $

DISTNAME=	mmorph-1.2.0
PKGREVISION=	8
CATEGORIES=	devel

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Monad morphisms
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	mtl	\
	transformers	\
	transformers-compat

.include "../../mk/haskell.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
