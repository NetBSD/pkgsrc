# $NetBSD: Makefile,v 1.20 2012/09/07 19:17:22 adam Exp $
#

DISTNAME=		twitux-0.69
PKGREVISION=		14
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=twitux/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://live.gnome.org/DanielMorales/Twitux
COMMENT=		GTK+ Twitter client

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES

GCONF_SCHEMAS=		twitux.schemas

PKG_OPTIONS_VAR=	PKG_OPTIONS.twitux
PKG_SUPPORTED_OPTIONS=	aspell
PKG_SUGGESTED_OPTIONS=	aspell

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Maspell)
CONFIGURE_ARGS+=	--enable-aspell=yes
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-aspell=no
.endif

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/libsexy/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
