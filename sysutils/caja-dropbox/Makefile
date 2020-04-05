# $NetBSD: Makefile,v 1.25 2020/04/05 16:05:40 bsiegert Exp $

# Makefile.common already includes python .mk files, so need to set this here
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	caja-dropbox-${VERSION}
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
