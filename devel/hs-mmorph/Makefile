# $NetBSD: Makefile,v 1.14 2023/10/09 04:54:24 pho Exp $

DISTNAME=	mmorph-1.2.0
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Monad morphisms
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	transformers-compat

.include "../../mk/haskell.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
