# $NetBSD: options.mk,v 1.1 2004/08/05 03:04:33 jlam Exp $

# Global and legacy options
.if defined(KERBEROS) || defined(USE_SASL) || defined(USE_SASL2)
.  if !defined(PKG_OPTIONS.openldap)
.    if defined(KERBEROS)
PKG_OPTIONS.openldap+=	kerberos
.    endif
.    if defined(USE_SASL) && !empty(USE_SASL:M[yY][eE][sS])
PKG_OPTIONS.openldap+=	sasl
.    endif
.    if defined(USE_SASL2) && !empty(USE_SASL2:M[yY][eE][sS])
PKG_OPTIONS.openldap+=	sasl
.    endif
.  endif
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.openldap
PKG_SUPPORTED_OPTIONS=	dynamic kerberos sasl slp
.include "../../mk/bsd.options.mk"

###
### Whether to build with dynamically-loadable backend modules.  If not
### specified, then link the backend modules statically into slapd.
###
.if !empty(PKG_OPTIONS:Mdynamic)
.  include "../../devel/libtool/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-modules
PLIST_SUBST+=		DYNAMIC_MOD=
.else
PLIST_SUBST+=		DYNAMIC_MOD="@comment "
.endif

###
### Kerberos authentication is via SASL.
###
.if !empty(PKG_OPTIONS:Mkerberos)
.  if empty(PKG_OPTIONS:Msasl)
PKG_OPTIONS+=		sasl
.  endif
.endif

###
### SASL authentication
###
.if !empty(PKG_OPTIONS:Msasl)
.  if !defined(USE_SASL2) && !defined(USE_SASL)
.    include "../../security/cyrus-sasl2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-cyrus-sasl
.  elif defined(USE_SASL2) && !empty(USE_SASL2:M[yY][eE][sS])
.    include "../../security/cyrus-sasl2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-cyrus-sasl
.  elif defined(USE_SASL) && !empty(USE_SASL:M[yY][eE][sS])
.    include "../../security/cyrus-sasl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-cyrus-sasl
.  endif
.endif

###
### SLP (Service Locator Protocol)
###
.if !empty(PKG_OPTIONS:Mslp)
.  include "../../net/openslp/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-slp
.endif
