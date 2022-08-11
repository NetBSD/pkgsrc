# $NetBSD: Makefile,v 1.21 2022/08/11 05:09:03 gutteridge Exp $

PKGREVISION= 3
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-calc-${VERSION:R}.2
CATEGORIES=	misc

COMMENT=	Calculator for MATE Desktop

USE_LANGUAGES=	c

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
