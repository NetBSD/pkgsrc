# $NetBSD: Makefile,v 1.2 2016/07/09 13:04:06 wiz Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	caja-dropbox-${MATE_VERSION}
CATEGORIES=	sysutils

COMMENT=	Dropbox Caja extension

DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2
DEPENDS+=	${PYPKGPREFIX}-gobject-[0-9]*:../../devel/py-gobject
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-gtk2, py-gobject

REPLACE_PYTHON=	caja-dropbox.in

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../sysutils/caja/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
