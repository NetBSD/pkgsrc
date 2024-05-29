# $NetBSD: Makefile,v 1.37 2024/05/29 16:33:38 adam Exp $

PKGREVISION= 10
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-calc-${VERSION:R}.0
CATEGORIES=	misc

COMMENT=	Calculator for MATE Desktop

# "error: 'for' loop initial declarations are only allowed in C99 mode"
# 'unknown type name ulong' when building in strict ISO C mode
FORCE_C_STD=	gnu99

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
BUILDLINK_API_DEPENDS.mpfr+=	mpfr>=4.0.2
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
