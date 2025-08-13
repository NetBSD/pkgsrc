# $NetBSD: Makefile,v 1.5 2025/08/13 11:07:03 pho Exp $

DISTNAME=	trial-0.0.0.0
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Trial Data Structure
LICENSE=	mpl-2.0

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	dlist

.include "../../devel/hs-colourista/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
