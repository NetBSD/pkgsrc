# $NetBSD: Makefile,v 1.6 2023/11/02 06:36:27 pho Exp $

DISTNAME=	dependent-map-0.4.0.0
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Dependent finite maps (partial dependent products)
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	constraints-extras

.include "../../devel/hs-constraints-extras/buildlink3.mk"
.include "../../devel/hs-dependent-sum/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
