# $NetBSD: Makefile,v 1.139 2021/12/08 16:02:05 adam Exp $

PKGREVISION= 1
.include "Makefile.common"

COMMENT=	OpenType text shaping engine

# Use external icu support.
MESON_ARGS+=	-Dicu=disabled

.include "../../mk/bsd.pkg.mk"
