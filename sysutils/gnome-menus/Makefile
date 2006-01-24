# $NetBSD: Makefile,v 1.13 2006/01/24 07:32:34 wiz Exp $
#

DISTNAME=	gnome-menus-2.12.0
PKGREVISION=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-menus/2.12/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Implementation of the desktop menu specification for GNOME

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.2
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--disable-python

PKGCONFIG_OVERRIDE+=	${WRKSRC}/libmenu/libgnome-menu.pc.in

EXAMPLEDIR=		${PREFIX}/share/examples/gnome-menus/xdg/menus
OWN_DIRS=		${PKG_SYSCONFDIR}/xdg/menus
CONF_FILES=		${EXAMPLEDIR}/applications.menu \
			${PKG_SYSCONFDIR}/xdg/menus/applications.menu
CONF_FILES+=		${EXAMPLEDIR}/preferences.menu \
			${PKG_SYSCONFDIR}/xdg/menus/preferences.menu
CONF_FILES+=		${EXAMPLEDIR}/settings.menu \
			${PKG_SYSCONFDIR}/xdg/menus/settings.menu

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	"Fixing paths to installation prefix."
SUBST_FILES.paths=	layout/*.menu
SUBST_SED.paths=	-e 's|/usr/|${PREFIX}/|g'
SUBST_SED.paths+=	-e 's|/etc/X11/applnk|${PREFIX}/share/kde/applnk/|g'

BUILDLINK_DEPENDS.glib2+=	glib2>=2.6.0
BUILDLINK_DEPENDS.gnome-vfs2+=	gnome-vfs2>=2.10.0

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
