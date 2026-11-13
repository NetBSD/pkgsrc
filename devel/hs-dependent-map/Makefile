# $NetBSD: Makefile,v 1.12 2026/11/13 14:38:55 pho Exp $

DISTNAME=	dependent-map-0.4.0.0
PKGREVISION=	9
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
