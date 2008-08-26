# $NetBSD: Makefile,v 1.1.1.1 2008/08/26 01:20:25 epg Exp $

DISTNAME=	bzr-gtk-${VER}
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/bzr-gtk/0.95/${VER}/+download/
VER=		0.95.0

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://bazaar-vcs.org/bzr-gtk
COMMENT=	Various GTK+ frontends to Bazaar commands

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-cairo>=1.0:../../graphics/py-cairo
DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.8:../../x11/py-gtk2

PYDISTUTILSPKG=	yes
USE_DIRS+=	xdg-1.1

# Insists on working X display, and fails anyway, so disable.
BZR_PLUGIN_TEST=no

.include "../../devel/bzr/plugin.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
