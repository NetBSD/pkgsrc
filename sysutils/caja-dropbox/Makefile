# $NetBSD: Makefile,v 1.50 2026/05/15 17:01:03 wiz Exp $

PKGREVISION= 15
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	caja-dropbox-${VERSION:R}.0
CATEGORIES=	sysutils

COMMENT=	Dropbox Caja extension

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

CONFIGURE_ARGS+=	ac_cv_path_PYTHON3=${PYTHONBIN}

REPLACE_PYTHON=	caja-dropbox.in rst2man.py

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../sysutils/caja/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
