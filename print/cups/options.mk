# $NetBSD: options.mk,v 1.18 2014/08/23 20:02:11 schnoebe Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cups
PKG_SUPPORTED_OPTIONS=	acl dbus dnssd kerberos pam tcpwrappers
PKG_SUGGESTED_OPTIONS=	dbus dnssd kerberos

# Neither DragonFly nor SunOS can build libusb1
.if ${OPSYS} != "DragonFly" && ${OPSYS} != "SunOS"
PKG_SUPPORTED_OPTIONS+= libusb
PKG_SUGGESTED_OPTIONS+= libusb
.endif

.include "../../mk/bsd.options.mk"

MESSAGE_SRC=		${PKGDIR}/MESSAGE

.if !empty(PKG_OPTIONS:Macl)
CONFIGURE_ARGS+=	--enable-acl
.else
CONFIGURE_ARGS+=	--disable-acl
.endif

PLIST_VARS+=		dbus
.if !empty(PKG_OPTIONS:Mdbus)
USE_TOOLS+=		pkg-config
.  include "../../sysutils/dbus/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dbus
PLIST.dbus=		yes
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

PLIST_VARS+=		dnssd
.if !empty(PKG_OPTIONS:Mdnssd)
.include "../../net/mDNSResponder/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dnssd
PLIST.dnssd=		yes
.else
CONFIGURE_ARGS+=	--disable-dnssd
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
.include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gssapi
.else
CONFIGURE_ARGS+=	--disable-gssapi
.endif

PLIST_VARS+=		libusb
.if !empty(PKG_OPTIONS:Mlibusb)
.include "../../devel/libusb1/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libusb
MESSAGE_SRC+=		${PKGDIR}/MESSAGE.libusb
USE_TOOLS+=		pkg-config
PLIST.libusb=		yes
.else
CONFIGURE_ARGS+=	--disable-libusb
.endif

PLIST_VARS+=		pam
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pam
MESSAGE_SRC+=		${PKGDIR}/MESSAGE.pam
PLIST.pam=		yes
.else
CONFIGURE_ARGS+=	--disable-pam
MESSAGE_SRC=		${.CURDIR}/MESSAGE
.endif

.if !empty(PKG_OPTIONS:Mtcpwrappers)
.include "../../security/tcp_wrappers/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-tcp-wrappers
.else
CONFIGURE_ARGS+=	--disable-tcp-wrappers
.endif
