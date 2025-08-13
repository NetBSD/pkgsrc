# $NetBSD: Makefile,v 1.11 2025/08/13 11:06:37 pho Exp $

DISTNAME=	dependent-map-0.4.0.0
PKGREVISION=	8
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Dependent finite maps (partial dependent products)
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	containers	\
	constraints-extras

.include "../../devel/hs-constraints-extras/buildlink3.mk"
.include "../../devel/hs-dependent-sum/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
