# $NetBSD: options.mk,v 1.6 2023/11/04 12:32:11 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libvirt

# Common options.
PKG_SUPPORTED_OPTIONS+=	libssh2 lvm dbus avahi
PKG_SUGGESTED_OPTIONS=	libssh2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibssh2)
CONFIGURE_ARGS+=	--with-ssh2=${BUILDLINK_PREFIX.libssh2}
.  include "../../security/libssh2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlvm)
CONFIGURE_ARGS+=	--with-storage-lvm
.endif

.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--with-dbus=${BUILDLINK_PREFIX.dbus}
.  include "../../sysutils/dbus/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mavahi)
CONFIGURE_ARGS+=	--with-avahi=${BUILDLINK_PREFIX.avahi}
.  include "../../net/avahi/buildlink3.mk"
.endif
