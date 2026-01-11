# $NetBSD: Makefile,v 1.155 2026/01/11 06:00:33 wiz Exp $

PKGREVISION=1
.include "Makefile.common"

COMMENT=	OpenType text shaping engine

# Use external icu support.
MESON_ARGS+=	-Dicu=disabled
MESON_ARGS+=	-Dtests=disabled

.include "../../mk/bsd.pkg.mk"
