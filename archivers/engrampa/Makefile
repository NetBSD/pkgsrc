# $NetBSD: Makefile,v 1.20 2020/03/10 22:09:17 wiz Exp $

PKGREVISION= 2
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	engrampa-${VERSION:R}.3
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
