# $NetBSD: Makefile,v 1.153 2025/10/23 20:36:56 wiz Exp $

PKGREVISION= 1
.include "Makefile.common"

COMMENT=	OpenType text shaping engine

# Use external icu support.
MESON_ARGS+=	-Dicu=disabled
MESON_ARGS+=	-Dtests=disabled

.include "../../mk/bsd.pkg.mk"
