# $NetBSD: Makefile,v 1.10 2010/06/13 22:45:13 wiz Exp $
#

DISTNAME=	vinagre-2.28.1
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/vinagre/2.28/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.gnome.org/vinagre/
COMMENT=	VNC client for GNOME
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config msgfmt

GCONF_SCHEMAS+=	vinagre.schemas

PKG_OPTIONS_VAR=	PKG_OPTIONS.vinagre
PKG_SUPPORTED_OPTIONS=	avahi
.include "../../mk/bsd.options.mk"
.if empty(PKG_OPTIONS:Mavahi)
CONFIGURE_ARGS+= --disable-avahi
.else
.include "../../net/avahi/buildlink3.mk"
.endif

.include "../../databases/shared-mime-info/mimedb.mk"
BUILDLINK_API_DEPENDS.GConf+=	GConf>=2.16.0
.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.17.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk-vnc+=	gtk-vnc>=0.3.8nb1
.include "../../net/gtk-vnc/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.13.1
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
