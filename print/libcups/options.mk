# $NetBSD: options.mk,v 1.3 2022/05/10 20:47:38 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libcups
PKG_SUPPORTED_OPTIONS=	acl dnssd kerberos tcpwrappers
PKG_SUGGESTED_OPTIONS=	dnssd kerberos

.if defined(PKG_OPTIONS.cups)
PKG_LEGACY_OPTIONS+=		${PKG_OPTIONS.cups}
PKG_OPTIONS_DEPRECATED_WARNINGS+= \
	"Deprecated variable PKG_OPTIONS.cups used, use ${PKG_OPTIONS_VAR} instead."
.endif

.if ${OPSYS} != "Darwin"
# CUPS on Darwin does not support DBus and libusb
PKG_SUPPORTED_OPTIONS+=	avahi dbus
PKG_SUGGESTED_OPTIONS+=	dbus
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Macl)
CONFIGURE_ARGS+=	--enable-acl
.else
CONFIGURE_ARGS+=	--disable-acl
.endif

.if !empty(PKG_OPTIONS:Mavahi)
.include "../../net/avahi/buildlink3.mk"
CONFIGURE_ARGS+=	--with-dnssd=avahi
.endif

.if !empty(PKG_OPTIONS:Mdbus)
.  include "../../sysutils/dbus/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dbus
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mdnssd)
.include "../../net/mDNSResponder/buildlink3.mk"
CONFIGURE_ARGS+=	--with-dnssd=yes
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
.include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gssapi
.else
CONFIGURE_ARGS+=	--disable-gssapi
.endif

.if !empty(PKG_OPTIONS:Mtcpwrappers)
.include "../../security/tcp_wrappers/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-tcp-wrappers
.else
CONFIGURE_ARGS+=	--disable-tcp-wrappers
.endif
