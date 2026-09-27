# $NetBSD: Makefile,v 1.46 2026/09/27 11:34:46 tnn Exp $

PKGREVISION= 12
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	engrampa-${VERSION:R}.2
CATEGORIES=	archivers

COMMENT=	Archive manager utility for the MATE Environment

USE_TOOLS+=	gtar:run gzip:run bzip2:run unzip:run zip:run xz:run

.include "../../devel/glib2/schemas.mk"

.include "../../sysutils/caja/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
