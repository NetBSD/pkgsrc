# $NetBSD: Makefile,v 1.15 2025/01/31 13:15:44 pho Exp $

DISTNAME=	generic-deriving-1.14.6
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
