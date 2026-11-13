# $NetBSD: Makefile,v 1.26 2026/11/13 14:39:25 pho Exp $

DISTNAME=	vault-0.3.1.5
PKGREVISION=	12
CATEGORIES=	devel

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Persistent store for values of arbitrary types
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	containers	\
	hashable

.include "../../mk/haskell.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
