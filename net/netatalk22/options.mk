# $NetBSD: options.mk,v 1.7 2023/01/10 22:07:33 hauke Exp $
#
PKG_OPTIONS_VAR=	PKG_OPTIONS.netatalk
PKG_SUPPORTED_OPTIONS=	cups debug dnssd kerberos ldap pam slp

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups-base/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cups
.else
CONFIGURE_ARGS+=	--disable-cups
.endif

.if !empty(PKG_OPTIONS:Mdebug)
# Debugging
CONFIGURE_ARGS+=	--enable-debug1
CONFIGURE_ARGS+=	--enable-debug
CONFIGURE_ARGS+=	--enable-debugging
CFLAGS+=		-g3
INSTALL_UNSTRIPPED=	yes
.endif

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
CONFIGURE_ARGS+=	--without-gssapi
.endif

PLIST_VARS+=		ldap
.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=       --with-ldap=yes
PLIST.ldap=		yes
CONF_FILES+=		${EGDIR}/afp_ldap.conf ${PKG_SYSCONFDIR}/afp_ldap.conf
.else
CONFIGURE_ARGS+=       --with-ldap=no
.endif

PLIST_VARS+=		pam
.if !empty(PKG_OPTIONS:Mpam)
.include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam=yes
PLIST.pam=		yes
MESSAGE_SRC+=		MESSAGE MESSAGE.pam
.else
CONFIGURE_ARGS+=	--with-pam=no
.endif

.if !empty(PKG_OPTIONS:Mslp)
.include "../../net/openslp/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-srvloc
.else
CONFIGURE_ARGS+=	--disable-srvloc
.endif
