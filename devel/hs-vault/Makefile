# $NetBSD: Makefile,v 1.20 2023/11/02 06:37:03 pho Exp $

DISTNAME=	vault-0.3.1.5
PKGREVISION=	7
CATEGORIES=	devel

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Persistent store for values of arbitrary types
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	hashable

.include "../../mk/haskell.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
