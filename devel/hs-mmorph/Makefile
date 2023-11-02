# $NetBSD: Makefile,v 1.16 2023/11/02 06:36:47 pho Exp $

DISTNAME=	mmorph-1.2.0
PKGREVISION=	5
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
