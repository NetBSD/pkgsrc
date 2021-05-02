# $NetBSD: Makefile,v 1.17 2021/05/02 10:24:50 nia Exp $

PKGREVISION= 5
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-calc-${VERSION}
CATEGORIES=	misc

COMMENT=	Calculator for MATE Desktop

USE_LANGUAGES=	c

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
