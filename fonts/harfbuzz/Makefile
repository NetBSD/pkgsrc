# $NetBSD: Makefile,v 1.159 2026/04/21 20:53:41 wiz Exp $

.include "Makefile.common"

PKGREVISION=	1
COMMENT=	OpenType text shaping engine

MESON_ARGS+=	-Ddocs=disabled
# Use external icu support.
MESON_ARGS+=	-Dicu=disabled
MESON_ARGS+=	-Dtests=disabled

.include "../../mk/bsd.pkg.mk"
