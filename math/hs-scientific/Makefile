# $NetBSD: Makefile,v 1.26 2024/04/29 23:06:07 pho Exp $

DISTNAME=	scientific-0.3.7.0
PKGREVISION=	5
CATEGORIES=	math

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Numbers represented using scientific notation
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base			\
	bytestring		\
	deepseq			\
	hashable		\
	primitive		\
	template-haskell	\
	text

.include "../../mk/haskell.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../math/hs-integer-logarithms/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
