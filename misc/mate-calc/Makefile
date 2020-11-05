# $NetBSD: Makefile,v 1.15 2020/11/05 09:08:42 ryoon Exp $

PKGREVISION= 4
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
