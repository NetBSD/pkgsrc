# $NetBSD: Makefile,v 1.12 2011/02/25 09:47:20 wiz Exp $

DISTNAME=	bzr-gtk-${VER}
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/bzr-gtk/trunk/${VER}/+download/
VER=		0.98.0

MAINTAINER=	jan.m.danielsson@gmail.com
HOMEPAGE=	http://bazaar-vcs.org/bzr-gtk
COMMENT=	Various GTK+ frontends to Bazaar commands

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-cairo>=1.0:../../graphics/py-cairo
DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.8:../../x11/py-gtk2

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED=	27 26 25
REPLACE_PYTHON=	create-credits.py

USE_TOOLS+=	msgfmt

# Insists on working X display, and fails anyway, so disable.
BZR_PLUGIN_TEST=no

PRIVILEGED_STAGES+=	clean

.include "../../devel/bzr/plugin.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
