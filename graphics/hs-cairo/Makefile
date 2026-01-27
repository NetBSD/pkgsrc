# $NetBSD: Makefile,v 1.4 2026/01/27 08:39:42 wiz Exp $

DISTNAME=	cairo-0.13.11.0
PKGREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Binding to the Cairo library
LICENSE=	modified-bsd

USE_TOOLS+=	gtk2hs-buildtools pkg-config

.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
