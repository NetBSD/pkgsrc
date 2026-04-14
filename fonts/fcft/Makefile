# $NetBSD: Makefile,v 1.1 2026/04/14 12:06:06 kikadf Exp $

DISTNAME=	fcft-3.3.3
CATEGORIES=	fonts
MASTER_SITES=	https://codeberg.org/dnkl/fcft/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://codeberg.org/dnkl/fcft/
COMMENT=	Simple library for font loading and glyph rasterization
LICENSE=	mit

USE_TOOLS+=	pkg-config

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../converters/utf8proc/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../devel/tllist/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../mk/bsd.pkg.mk"
