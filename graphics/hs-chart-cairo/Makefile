# $NetBSD: Makefile,v 1.4 2026/01/27 08:39:43 wiz Exp $

DISTNAME=	Chart-cairo-1.9.4.1
PKGNAME=	hs-${DISTNAME:tl}
PKGREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Cairo backend for Charts
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	data-default-class	\
	lens

.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../graphics/hs-cairo/buildlink3.mk"
.include "../../devel/hs-colour/buildlink3.mk"
.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../devel/hs-operational/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../graphics/hs-chart/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
