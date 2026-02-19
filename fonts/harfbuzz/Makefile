# $NetBSD: Makefile,v 1.157 2026/02/19 16:55:29 wiz Exp $

.include "Makefile.common"

PKGREVISION=	1

COMMENT=	OpenType text shaping engine

# Use external icu support.
MESON_ARGS+=	-Dicu=disabled
MESON_ARGS+=	-Dtests=disabled

.include "../../mk/bsd.pkg.mk"
