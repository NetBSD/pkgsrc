# $NetBSD: Makefile,v 1.13 2023/02/07 01:40:44 pho Exp $

DISTNAME=	mmorph-1.2.0
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Monad morphisms
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	transformers-compat

.include "../../mk/haskell.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
