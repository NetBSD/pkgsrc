# $NetBSD: Makefile,v 1.8 2018/03/12 11:15:59 wiz Exp $

PKGREVISION= 2
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
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
