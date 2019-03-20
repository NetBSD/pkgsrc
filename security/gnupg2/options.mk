# $NetBSD: options.mk,v 1.14 2019/03/20 06:39:52 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnupg2
PKG_SUPPORTED_OPTIONS=	bzip2 gnutls ldap libusb-1 zlib
PKG_SUGGESTED_OPTIONS=	bzip2 gnutls libusb-1 zlib

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbzip2)
CONFIGURE_ARGS+=       --with-bzip2=${BUILDLINK_PREFIX.bzip2}
.include "../../archivers/bzip2/buildlink3.mk"
.else
CONFIGURE_ARGS+=       --disable-bzip2
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
.else
CONFIGURE_ARGS+=       --disable-gnutls
.endif

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

.if !empty(PKG_OPTIONS:Mzlib)
CONFIGURE_ARGS+=       --with-zlib=${BUILDLINK_PREFIX.zlib}
.include "../../devel/zlib/buildlink3.mk"
.else
CONFIGURE_ARGS+=       --disable-zip
.endif
