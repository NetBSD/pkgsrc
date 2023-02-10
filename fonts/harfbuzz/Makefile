# $NetBSD: Makefile,v 1.146 2023/02/10 14:41:50 ryoon Exp $

.include "Makefile.common"

COMMENT=	OpenType text shaping engine

# Use external icu support.
MESON_ARGS+=	-Dicu=disabled
MESON_ARGS+=	-Dtests=disabled

.include "../../mk/bsd.pkg.mk"
