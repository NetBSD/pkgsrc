# $NetBSD: Makefile,v 1.28 2012/07/15 08:22:53 wiz Exp $
#

DISTNAME=	vinagre-2.30.3
PKGREVISION=	14
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/vinagre/2.30/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.gnome.org/vinagre/
COMMENT=	VNC client for GNOME
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config msgfmt
USE_LANGUAGES=	c c++

GCONF_SCHEMAS+=	vinagre.schemas

PKG_OPTIONS_VAR=	PKG_OPTIONS.vinagre
PKG_SUPPORTED_OPTIONS=	avahi telepathy
.include "../../mk/bsd.options.mk"
.if empty(PKG_OPTIONS:Mavahi)
CONFIGURE_ARGS+= --disable-avahi
.else
.include "../../net/avahi/buildlink3.mk"
.endif
PLIST_VARS+= telepathy
.if !empty(PKG_OPTIONS:Mtelepathy)
CONFIGURE_ARGS+= --enable-telepathy
.include "../../chat/telepathy-glib/buildlink3.mk"
PLIST.telepathy= yes
.else
CONFIGURE_ARGS+= --disable-telepathy
.endif

.include "../../databases/shared-mime-info/mimedb.mk"
BUILDLINK_API_DEPENDS.GConf+=	GConf>=2.16.0
.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.17.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk-vnc+=	gtk-vnc>=0.3.8nb1
.include "../../net/gtk-vnc/buildlink3.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.13.1
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
