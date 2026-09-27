# $NetBSD: Makefile,v 1.6 2026/09/27 11:36:47 tnn Exp $

DISTNAME=	cairo-0.13.11.0
PKGREVISION=	5
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Binding to the Cairo library
LICENSE=	modified-bsd

USE_TOOLS+=	gtk2hs-buildtools pkg-config

.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
