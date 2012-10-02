# $NetBSD: Makefile,v 1.4 2012/10/02 17:12:01 tron Exp $
#

DISTNAME=	virt-manager-0.9.4
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://virt-manager.org/download/sources/virt-manager/

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	http://virt-manager.org/
COMMENT=	GUI to manage virtual machines
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libvirt-package-names=libvirt

USE_TOOLS+=		gmake intltool
USE_PKGLOCALEDIR=	yes

GCONF_SCHEMAS+=	virt-manager.schemas

DEPENDS=	libvirt>=0.9.3:../../sysutils/libvirt
DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.24:../../x11/py-gtk2
DEPENDS+=	virtinst>=0.600.3:../../sysutils/virtinst
DEPENDS+=	${PYPKGPREFIX}-libxml2>=2.8.0:../../textproc/py-libxml2
DEPENDS+=	urlgrabber>=3.1.0:../../www/urlgrabber
DEPENDS+=	${PYPKGPREFIX}-dbus>=1.1.1:../../sysutils/py-dbus
DEPENDS+=	gtk-vnc>=0.5.1:../../net/gtk-vnc

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_MESSAGE.python=	Fixing hard-coded config file paths.
SUBST_FILES.python=	src/virt-manager.in src/virt-manager-tui.in src/virt-manager-launch.in
SUBST_SED.python=	-e 's,@@PYTHONBIN@@,${PYTHONBIN},'

REPLACE_PYTHON=		src/virtManagerTui/startnetwork.py

.include "../../lang/python/application.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
