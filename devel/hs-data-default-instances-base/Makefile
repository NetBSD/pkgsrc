# $NetBSD: Makefile,v 1.13 2025/03/05 03:39:08 pho Exp $

DISTNAME=	data-default-instances-base-0.1.0.3
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Default instances for types in base
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	data-default-class

.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
