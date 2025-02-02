# $NetBSD: Makefile,v 1.12 2025/02/02 13:05:03 pho Exp $

DISTNAME=	data-default-instances-old-locale-0.0.1.2
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Default instances for types in old-locale
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	data-default-class

.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
