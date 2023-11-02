# $NetBSD: Makefile,v 1.17 2023/11/02 06:37:03 pho Exp $

DISTNAME=	vector-algorithms-0.9.0.1
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Efficient algorithms for vector arrays
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	primitive

.include "../../devel/hs-bitvec/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
