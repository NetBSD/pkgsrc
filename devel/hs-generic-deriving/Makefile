# $NetBSD: Makefile,v 1.16 2025/02/02 13:05:07 pho Exp $

DISTNAME=	generic-deriving-1.14.6
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Generic programming library for generalised deriving
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	containers	\
	template-haskell	\
	th-abstraction

.include "../../devel/hs-th-abstraction/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
