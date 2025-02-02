# $NetBSD: Makefile,v 1.18 2025/02/02 13:05:15 pho Exp $

DISTNAME=	mmorph-1.2.0
PKGREVISION=	7
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
