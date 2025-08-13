# $NetBSD: Makefile,v 1.20 2025/08/13 11:06:49 pho Exp $

DISTNAME=	mmorph-1.2.0
PKGREVISION=	9
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
