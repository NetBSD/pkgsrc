# $NetBSD: Makefile,v 1.33 2012/01/31 12:05:04 obache Exp $
#

DISTNAME=	orca-2.32.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/orca/2.32/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Orca
COMMENT=	Screen reader
LICENSE=	gnu-lgpl-v2

# dependency versions are for Gnome 2.32.
DEPENDS+=	${PYPKGPREFIX}-at-spi>=1.32:../../devel/py-at-spi
DEPENDS+=	${PYPKGPREFIX}-gobject>=2.26:../../devel/py-gobject
DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg
DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo
DEPENDS+=	${PYPKGPREFIX}-ORBit>=2.24:../../net/py-ORBit
DEPENDS+=	${PYPKGPREFIX}-dbus-[0-9]*:../../sysutils/py-dbus
DEPENDS+=	${PYPKGPREFIX}-gnome2>=2.28:../../x11/py-gnome2
DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.22:../../x11/py-gtk2
DEPENDS+=	gnome-speech>=0.4.25:../../audio/gnome-speech
DEPENDS+=	gnome-mag>=0.16.2:../../x11/gnome-mag

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool pkg-config gmake msgfmt
USE_PKGLOCALEDIR=	yes

CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
PY_PATCHPLIST=	yes

.include "../../mk/bsd.prefs.mk"
.if ${X11_TYPE} == "modular" || !exists(${X11BASE}/bin/xmodmap)
DEPENDS+=	xmodmap-[0-9]*:../../x11/xmodmap
.endif

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
