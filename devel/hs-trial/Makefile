# $NetBSD: Makefile,v 1.6 2026/11/13 14:39:22 pho Exp $

DISTNAME=	trial-0.0.0.0
PKGREVISION=	5
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
