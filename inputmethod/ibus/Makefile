# $NetBSD: Makefile,v 1.21 2012/10/02 17:11:21 tron Exp $
#

DISTNAME=	ibus-1.4.2
PKGREVISION=	3
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	Intelligent Input Bus
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg
DEPENDS+=	${PYPKGPREFIX}-notify>=0.1.1nb3:../../sysutils/py-notify

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool msgfmt gmake
USE_LANGUAGES=	c c++
USE_PKGLOCALEDIR=	yes

GCONF_SCHEMAS+=		ibus.schemas
PKGCONFIG_OVERRIDE+=	ibus-1.0.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale
CONFIGURE_ARGS+=	--enable-gtk2
CONFIGURE_ARGS+=	--disable-gtk3
CONFIGURE_ARGS+=	--enable-surrounding-text

SUBST_CLASSES+=		dbus
SUBST_STAGE.dbus=	post-configure
SUBST_FILES.dbus=	src/ibusshare.c
SUBST_SED.dbus=		-e 's,/var/lib/dbus/machine-id,${VARBASE}/db/dbus/machine-id,g'

BUILD_DEFS+=	PKG_SYSCONFBASE VARBASE

BUILDLINK_API_DEPENDS.GConf+=		GConf>=2.12
.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.26.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
PY_PATCHPLIST=	yes
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.py-dbus+=		${PYPKGPREFIX}-dbus>=0.83.0
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
GTK2_IMMODULES=	yes
.include "../../x11/gtk2/modules.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
