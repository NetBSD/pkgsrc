# $NetBSD: Makefile,v 1.32 2026/11/13 14:39:36 pho Exp $

DISTNAME=	scientific-0.3.8.0
PKGREVISION=	4
CATEGORIES=	math

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Numbers represented using scientific notation
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	hashable

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../math/hs-integer-logarithms/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
