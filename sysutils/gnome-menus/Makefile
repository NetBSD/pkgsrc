# $NetBSD: Makefile,v 1.60 2023/08/14 05:25:15 wiz Exp $
#

DISTNAME=	gnome-menus-2.30.5
PKGREVISION=	7
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-menus/2.30/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Implementation of the desktop menu specification for GNOME

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--disable-python

INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} menudir=${EXAMPLEDIR}

PKGCONFIG_OVERRIDE+=	${WRKSRC}/libmenu/libgnome-menu.pc.in

EXAMPLEDIR=		${PREFIX}/share/examples/gnome-menus/xdg/menus
OWN_DIRS=		${PKG_SYSCONFDIR}/xdg/menus
CONF_FILES=		${EXAMPLEDIR}/applications.menu \
			${PKG_SYSCONFDIR}/xdg/menus/applications.menu
CONF_FILES+=		${EXAMPLEDIR}/settings.menu \
			${PKG_SYSCONFDIR}/xdg/menus/settings.menu

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing paths to installation prefix.
SUBST_FILES.paths=	layout/*.menu
SUBST_SED.paths=	-e 's|/usr/|${PREFIX}/|g'
SUBST_SED.paths+=	-e 's|/etc/X11/applnk|${PREFIX}/share/kde/applnk/|g'

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.0

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
