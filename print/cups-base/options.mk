# $NetBSD: options.mk,v 1.8 2022/11/16 16:24:36 hauke Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.cups-base
PKG_SUPPORTED_OPTIONS=		acl kerberos pam tcpwrappers
PKG_SUGGESTED_OPTIONS=		dnssd kerberos

PKG_OPTIONS_OPTIONAL_GROUPS=	mdns
PKG_OPTIONS_GROUP.mdns=		dnssd

PLIST_VARS+=			apple dbus dnssd dnssd-backend ippfind libusb pam

.if defined(PKG_OPTIONS.cups)
PKG_LEGACY_OPTIONS+=		${PKG_OPTIONS.cups}
PKG_OPTIONS_DEPRECATED_WARNINGS+= \
	"Deprecated variable PKG_OPTIONS.cups used, use ${PKG_OPTIONS_VAR} instead."
.endif

.if ${OPSYS} == "Darwin"
PLIST.apple=			yes
PLIST.ippfind=			yes
.else
# CUPS on Darwin does not support DBus and libusb
PKG_SUPPORTED_OPTIONS+=		dbus
PKG_OPTIONS_GROUP.mdns+=	avahi
PKG_SUGGESTED_OPTIONS+=		dbus
# Neither DragonFly nor SunOS can build libusb1
.  if ${OPSYS} != "DragonFly" && ${OPSYS} != "SunOS"
PKG_SUPPORTED_OPTIONS+=		libusb
PKG_SUGGESTED_OPTIONS+=		libusb
.  endif
.endif

.include "../../mk/bsd.options.mk"

MESSAGE_SRC=		${PKGDIR}/MESSAGE

.if !empty(PKG_OPTIONS:Macl)
CONFIGURE_ARGS+=	--enable-acl
.else
CONFIGURE_ARGS+=	--disable-acl
.endif

.if !empty(PKG_OPTIONS:Mavahi)
.include "../../net/avahi/buildlink3.mk"
CONFIGURE_ARGS+=	--with-dnssd=avahi
PLIST.ippfind=		yes
PLIST.dnssd-backend=	yes
.endif

.if !empty(PKG_OPTIONS:Mdnssd)
.include "../../net/mDNSResponder/buildlink3.mk"
CONFIGURE_ARGS+=	--with-dnssd=mdnsresponder
PLIST.dnssd=		yes
PLIST.dnssd-backend=	yes
PLIST.ippfind=		yes
.endif

.if empty(PKG_OPTIONS:Mavahi) && empty(PKG_OPTIONS:Mdnssd)
CONFIGURE_ARGS+=	--with-dnssd=no
.endif

.if !empty(PKG_OPTIONS:Mdbus)
.  include "../../sysutils/dbus/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dbus
PLIST.dbus=		yes
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
.include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gssapi
.else
CONFIGURE_ARGS+=	--disable-gssapi
.endif

.if !empty(PKG_OPTIONS:Mlibusb)
.include "../../devel/libusb1/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libusb
MESSAGE_SRC+=		${PKGDIR}/MESSAGE.libusb
PLIST.libusb=		yes
.else
CONFIGURE_ARGS+=	--disable-libusb
.endif

.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pam
MESSAGE_SRC+=		${PKGDIR}/MESSAGE.pam
PLIST.pam=		yes
.else
CONFIGURE_ARGS+=	--disable-pam
MESSAGE_SRC+=		${.CURDIR}/MESSAGE
.endif

.if !empty(PKG_OPTIONS:Mtcpwrappers)
.include "../../security/tcp_wrappers/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-tcp-wrappers
.else
CONFIGURE_ARGS+=	--disable-tcp-wrappers
.endif
