# $NetBSD: Makefile,v 1.27 2023/07/01 14:20:56 nia Exp $

PKGREVISION= 3
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-calc-${VERSION}
CATEGORIES=	misc

COMMENT=	Calculator for MATE Desktop

# "error: 'for' loop initial declarations are only allowed in C99 mode"
USE_LANGUAGES=	c99

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
BUILDLINK_API_DEPENDS.mpfr+=	mpfr>=4.0.2
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
