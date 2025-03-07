# $NetBSD: Makefile,v 1.1 2025/03/07 13:03:47 pho Exp $

DISTNAME=	cairo-0.13.11.0
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Binding to the Cairo library
LICENSE=	modified-bsd

USE_TOOLS+=	gtk2hs-buildtools pkg-config

.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
