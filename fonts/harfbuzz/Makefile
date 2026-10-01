# $NetBSD: Makefile,v 1.165 2026/10/01 06:45:20 adam Exp $

.include "Makefile.common"

COMMENT=	OpenType text shaping engine

MESON_ARGS+=	-Ddocs=disabled
# Use external icu support.
MESON_ARGS+=	-Dicu=disabled
MESON_ARGS+=	-Dtests=disabled

.include "../../mk/bsd.pkg.mk"
