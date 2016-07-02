# $NetBSD: options.mk,v 1.2 2016/07/02 15:16:11 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnupg21
PKG_SUPPORTED_OPTIONS=	ldap libusb-1
PKG_SUGGESTED_OPTIONS=	libusb-1

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		ldap
.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap-client}
PLIST.ldap=		yes
.include "../../databases/openldap-client/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ldap
.endif

.if !empty(PKG_OPTIONS:Mlibusb-1)
# gnupg unfortunately doesn't use pkg-config
CONFIGURE_ARGS+=	CPPFLAGS="${CPPFLAGS} -I${BUILDLINK_PREFIX.libusb1}/include/libusb-1.0"
CONFIGURE_ARGS+=	LDFLAGS="${LDFLAGS} ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libusb1}/lib -L${BUILDLINK_PREFIX.libusb1}/lib"
.include "../../devel/libusb1/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ccid-driver
.endif
