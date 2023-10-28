# $NetBSD: Makefile,v 1.24 2023/10/28 14:27:31 pho Exp $

DISTNAME=	scientific-0.3.7.0
PKGREVISION=	4
CATEGORIES=	math

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Numbers represented using scientific notation
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	hashable	\
	primitive	\
	template-haskell	\
	text

.include "../../mk/haskell.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../math/hs-integer-logarithms/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
