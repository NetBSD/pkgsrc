# $NetBSD: Makefile,v 1.15 2009/03/16 13:06:40 jmcneill Exp $
#

DISTNAME=	gvfs-1.2.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gvfs/1.2/}
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
PKG_SUPPORTED_OPTIONS+= avahi hal fuse
PKG_SUGGESTED_OPTIONS+= avahi hal
PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

# XXX fuse.bl3.mk will fail if we include it and fuse is not available
.if ${OPSYS} == "Linux" || (${OPSYS} == "NetBSD" && exists(/usr/include/fuse.h))
PKG_SUGGESTED_OPTIONS+=	fuse
.endif

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

.if !empty(PKG_OPTIONS:Mfuse)
.include "../../mk/fuse.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-fuse
PLIST.fuse=		yes
.else
CONFIGURE_ARGS+=	--disable-fuse
.endif

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.17.6
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../net/samba/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsoup24+=	libsoup24>=2.25.1
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
