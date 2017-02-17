# $NetBSD: options.mk,v 1.21 2017/02/17 23:45:48 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cups
PKG_SUPPORTED_OPTIONS=	acl dnssd kerberos pam tcpwrappers
PKG_SUGGESTED_OPTIONS=	dnssd kerberos

PLIST_VARS+=		apple dbus dnssd ippfind libusb pam

.if ${OPSYS} == "Darwin"
PLIST.apple=		yes
PLIST.ippfind=		yes
.else
# CUPS on Darwin does not support DBus and libusb
PKG_SUPPORTED_OPTIONS+=	avahi dbus
PKG_SUGGESTED_OPTIONS+=	dbus
# Neither DragonFly nor SunOS can build libusb1
.  if ${OPSYS} != "DragonFly" && ${OPSYS} != "SunOS"
PKG_SUPPORTED_OPTIONS+=	libusb
PKG_SUGGESTED_OPTIONS+=	libusb
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
CONFIGURE_ARGS+=	--enable-avahi
PLIST.ippfind=		yes
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

.if !empty(PKG_OPTIONS:Mdbus)
.  include "../../sysutils/dbus/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dbus
PLIST.dbus=		yes
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

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
# https://github.com/apple/cups/issues/4947
SUBST_CLASSES+=		nokerb
SUBST_STAGE.nokerb=	post-build
SUBST_SED.nokerb+=	-e '\%<Policy kerberos>%,\%</Policy>%s/^/\#/'
SUBST_FILES.nokerb+=	conf/cupsd.conf
SUBST_MESSAGE.nokerb=	Commenting out kerberos section in config.
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
