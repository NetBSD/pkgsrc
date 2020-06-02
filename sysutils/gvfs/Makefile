# $NetBSD: Makefile,v 1.111 2020/06/02 08:24:45 adam Exp $
#

DISTNAME=	gvfs-1.6.7
PKGREVISION=	50
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gvfs/1.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Userspace virtual filesystem
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		intltool gmake pkg-config msgfmt
CONFIGURE_ARGS+=	--enable-http
CONFIGURE_ARGS+=	--disable-bash-completion

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.gvfs
PKG_SUPPORTED_OPTIONS+=	avahi hal fuse samba
PKG_SUGGESTED_OPTIONS+=	samba
PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

# XXX fuse.bl3.mk will fail if we include it and fuse is not available
.if ${OPSYS} == "Linux" #|| (${OPSYS} == "NetBSD" && exists(/usr/include/fuse.h))
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

.if !empty(PKG_OPTIONS:Msamba)
CONFIGURE_ARGS+=	--with-samba-includes=${BUILDLINK_PREFIX.samba}/include
CONFIGURE_ARGS+=	--with-samba-libs=${BUILDLINK_PREFIX.samba}/lib
.include "../../net/samba4/buildlink3.mk"
PLIST.samba=		yes
.else
CONFIGURE_ARGS+=	--disable-samba
.endif

.if !empty(PKG_OPTIONS:Mhal)
.include "../../misc/libcdio-paranoia/buildlink3.mk"
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

BUILDLINK_TRANSFORM+=	rm:-DG_DISABLE_DEPRECATED

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang) || !empty(CC_VERSION:Mgcc-[6-9]*)
CFLAGS.SunOS+=		-D_XOPEN_SOURCE=600 -D__EXTENSIONS__
.else
CFLAGS.SunOS+=		-D_XOPEN_SOURCE=500 -D__EXTENSIONS__
.endif

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.23.4
.include "../../devel/glib2/modules.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsoup+=	libsoup>=2.26.0
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
