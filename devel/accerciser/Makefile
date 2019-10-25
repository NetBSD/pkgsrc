# $NetBSD: Makefile,v 1.33 2019/10/25 14:13:23 kamil Exp $

DISTNAME=	accerciser-3.34.0
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/accerciser/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://live.gnome.org/Accerciser/
COMMENT=	Interactive Python accessibility explorer for the GNOME desktop
LICENSE=	modified-bsd

USE_TOOLS+=		gmake msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
PY_PATCHPLIST=		yes
REPLACE_PYTHON=		plugins/ipython_view.py
REPLACE_PYTHON+=	src/accerciser.in

TOOL_DEPENDS+=		gettext-tools>=0.19.8:../../devel/gettext-tools
_TOOLS_USE_PKGSRC.msgfmt=yes
BUILD_DEPENDS+=		itstool-[0-9]*:../../textproc/itstool

DEPENDS+=	libwnck3-[0-9]*:../../devel/libwnck3
DEPENDS+=	${PYPKGPREFIX}-at-spi2-[0-9]*:../../devel/py-at-spi2
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-ipython>=1.2.1:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-Xlib-[0-9]*:../../x11/py-Xlib

# dependencies to keep package's configure script happy:
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/at-spi2-core/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
