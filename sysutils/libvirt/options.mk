# $NetBSD: options.mk,v 1.4 2016/07/09 12:47:05 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libvirt

# Common options.
PKG_SUPPORTED_OPTIONS+=	xen libssh2 lvm hal dbus avahi
PKG_SUGGESTED_OPTIONS=	libssh2

.include "../../mk/bsd.options.mk"

# xentools42 is the only version to install
# the include files
PLIST_VARS+=	xen hal

# xen means xen 4.2.
.if !empty(PKG_OPTIONS:Mxen)
PLIST.xen= yes
CONFIGURE_ARGS+=	--without-xen
CONFIGURE_ARGS+=	--with-libxl=${BUILDLINK_PREFIX.xentools42}
CONFIGURE_ARGS+=	--with-xenapi=${BUILDLINK_PREFIX.xentools42}
.  include "../../sysutils/xentools42/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibssh2)
CONFIGURE_ARGS+=	--with-ssh2=${BUILDLINK_PREFIX.libssh2}
.   include "../../security/libssh2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlvm)
CONFIGURE_ARGS+=	--with-storage-lvm
.endif

.if !empty(PKG_OPTIONS:Mhal)
PLIST.hal= yes
CONFIGURE_ARGS+=	--with-hal=${BUILDLINK_PREFIX.hal}
.   include "../../sysutils/hal/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--with-dbus=${BUILDLINK_PREFIX.dbus}
.   include "../../sysutils/dbus/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mavahi)
CONFIGURE_ARGS+=	--with-avahi=${BUILDLINK_PREFIX.avahi}
.   include "../../net/avahi/buildlink3.mk"
.endif
