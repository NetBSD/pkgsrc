# $NetBSD: Makefile,v 1.12 2020/06/02 08:24:21 adam Exp $

PKGREVISION= 1
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-calc-${VERSION}
CATEGORIES=	misc

COMMENT=	Calculator for MATE Desktop

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool

USE_LANGUAGES=	c

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
