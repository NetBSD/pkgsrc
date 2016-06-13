# $NetBSD: Makefile,v 1.2 2016/06/13 22:41:16 youri Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	engrampa-1.14.1
CATEGORIES=	archivers

COMMENT=	Archive manager utility for the MATE Environment

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool

USE_TOOLS+=		gtar:run gzip:run bzip2:run unzip:run zip:run xz:run

.include "../../devel/glib2/schemas.mk"

.include "../../sysutils/caja/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_DEPMETHOD.libSM=	build
.include "../../x11/libSM/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
