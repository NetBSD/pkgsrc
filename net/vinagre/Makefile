# $NetBSD: Makefile,v 1.32 2012/10/02 17:11:49 tron Exp $
#

DISTNAME=	vinagre-3.4.2
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/vinagre/3.4/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.gnome.org/vinagre/
COMMENT=	VNC client for GNOME
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config msgfmt
USE_LANGUAGES=	c c++

USE_PKGLOCALEDIR=	yes

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
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.28.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk-vnc+=	gtk-vnc>=0.4.3
.include "../../net/gtk-vnc/buildlink3.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.0.3
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
