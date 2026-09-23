# $NetBSD: Makefile,v 1.162 2026/09/23 07:38:33 adam Exp $

.include "Makefile.common"

COMMENT=	OpenType text shaping engine

MESON_ARGS+=	-Ddocs=disabled
# Use external icu support.
MESON_ARGS+=	-Dicu=disabled
MESON_ARGS+=	-Dtests=disabled

.include "../../mk/bsd.pkg.mk"
