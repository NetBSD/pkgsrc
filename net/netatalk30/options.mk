# $NetBSD: options.mk,v 1.3 2016/02/07 20:34:54 szptvlfn Exp $
#
PKG_OPTIONS_VAR=	PKG_OPTIONS.netatalk
PKG_SUPPORTED_OPTIONS=	cups debug dnssd kerberos ldap pam

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups15/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cups
.else
CONFIGURE_ARGS+=	--disable-cups
.endif

PLIST_VARS+=		debug
.if !empty(PKG_OPTIONS:Mdebug)
# Debugging
CONFIGURE_ARGS+=	--enable-debug1
CONFIGURE_ARGS+=	--enable-debug
CONFIGURE_ARGS+=	--enable-debugging
CFLAGS+=		-g3
INSTALL_UNSTRIPPED=	yes
.endif

PLIST_VARS+=		dnssd
.if !empty(PKG_OPTIONS:Mdnssd)
.include "../../net/mDNSResponder/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-zeroconf
.else
# configure patched to zeroconf="no"
.endif

PLIST_VARS+=		gssapi
.if !empty(PKG_OPTIONS:Mkerberos)
.include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-gssapi --enable-krbV-uam
CONFIGURE_ENV+=		GSSAPI_LIBS="-lkrb5 -lroken -lasn1 -lcrypto -lcom_err"
PLIST.gssapi=		yes
.else
CONFIGURE_ARGS+=	--without-kerberos
.endif

.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=       --with-ldap=yes
.else
CONFIGURE_ARGS+=       --with-ldap=no
.endif

PLIST_VARS+=		pam
.if !empty(PKG_OPTIONS:Mpam)
.include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
PLIST.pam=		yes
MESSAGE_SRC+=		MESSAGE MESSAGE.pam
.else
CONFIGURE_ARGS+=	--without-pam
.endif
