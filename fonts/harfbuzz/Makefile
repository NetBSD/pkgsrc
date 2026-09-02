# $NetBSD: Makefile,v 1.161 2026/09/02 19:02:04 wiz Exp $

PKGREVISION= 1
.include "Makefile.common"

COMMENT=	OpenType text shaping engine

MESON_ARGS+=	-Ddocs=disabled
# Use external icu support.
MESON_ARGS+=	-Dicu=disabled
MESON_ARGS+=	-Dtests=disabled

.include "../../mk/bsd.pkg.mk"
