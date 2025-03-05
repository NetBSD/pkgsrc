# $NetBSD: Makefile,v 1.4 2025/03/05 03:40:05 pho Exp $

DISTNAME=	trial-tomland-0.0.0.0
PKGREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Trial helper functions for tomland
LICENSE=	mpl-2.0

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base	\
	text

.include "../../textproc/hs-tomland/buildlink3.mk"
.include "../../devel/hs-trial/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
