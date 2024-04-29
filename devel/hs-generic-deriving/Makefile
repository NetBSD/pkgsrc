# $NetBSD: Makefile,v 1.13 2024/04/29 05:14:57 pho Exp $

DISTNAME=	generic-deriving-1.14.5
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Generic programming library for generalised deriving
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	th-abstraction

.include "../../mk/haskell.mk"
.include "../../devel/hs-th-abstraction/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
