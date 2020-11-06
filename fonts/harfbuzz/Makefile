# $NetBSD: Makefile,v 1.137 2020/11/06 15:06:49 nia Exp $

PKGREVISION=	1

.include "Makefile.common"

COMMENT=	OpenType text shaping engine

# Use external icu support.
MESON_ARGS+=	-Dicu=disabled

.include "../../mk/bsd.pkg.mk"
