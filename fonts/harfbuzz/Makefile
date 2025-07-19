# $NetBSD: Makefile,v 1.151 2025/07/19 05:37:36 wiz Exp $

PKGREVISION= 1
.include "Makefile.common"

COMMENT=	OpenType text shaping engine

# Use external icu support.
MESON_ARGS+=	-Dicu=disabled
MESON_ARGS+=	-Dtests=disabled

.include "../../mk/bsd.pkg.mk"
