# $NetBSD: Makefile,v 1.152 2025/07/21 16:38:41 wiz Exp $

.include "Makefile.common"

COMMENT=	OpenType text shaping engine

# Use external icu support.
MESON_ARGS+=	-Dicu=disabled
MESON_ARGS+=	-Dtests=disabled

.include "../../mk/bsd.pkg.mk"
