# $NetBSD: Makefile,v 1.1 2025/03/07 12:39:35 pho Exp $

DISTNAME=	Chart-1.9.5
PKGNAME=	hs-${DISTNAME:tl}
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Library for generating 2D Charts and Plots
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	data-default-class	\
	lens

.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-colour/buildlink3.mk"
.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../devel/hs-operational/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
