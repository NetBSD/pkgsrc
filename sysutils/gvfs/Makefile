# $NetBSD: Makefile,v 1.13 2008/12/20 20:11:54 jmcneill Exp $
#

DISTNAME=	gvfs-1.0.3
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gvfs/1.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Userspace virtual filesystem

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool gmake pkg-config msgfmt
CONFIGURE_ARGS+=	--with-samba-includes=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-samba-libs=${LOCALBASE}/lib/samba
CONFIGURE_ARGS+=	--enable-http

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=        PKG_OPTIONS.gvfs
PKG_SUPPORTED_OPTIONS+= avahi hal
PKG_SUGGESTED_OPTIONS+= avahi hal
PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mavahi)
.include "../../net/avahi/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-avahi
PLIST.avahi=		yes
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

.if !empty(PKG_OPTIONS:Mhal)
.include "../../misc/libcdio/buildlink3.mk"
.include "../../sysutils/hal/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-hal
CONFIGURE_ARGS+=	--enable-cdda
PLIST.hal=		yes
.else
CONFIGURE_ARGS+=	--disable-hal
CONFIGURE_ARGS+=	--disable-cdda
.endif

# Not yet; will cause the package to fail if fuse is not present
#.include "../../mk/fuse.buildlink3.mk"

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.17.6
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../net/samba/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsoup24+=	libsoup24>=2.23.91
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
