# $NetBSD: options.mk,v 1.1 2004/08/05 03:04:34 jlam Exp $

# Global and legacy options
.if defined(KERBEROS) || defined(SASL_USE_GSSAPI)
.  if !defined(PKG_OPTIONS.cyrus-sasl)
.    if defined(KERBEROS) 
PKG_OPTIONS.cyrus-sasl+=	kerberos
.    endif
.    if defined(SASL_USE_GSSAPI) && !empty(SASL_USE_GSSAPI:M[yY][eE][sS])
PKG_OPTIONS.cyrus-sasl+=	gssapi
.    endif
.  endif
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.cyrus-sasl
PKG_SUPPORTED_OPTIONS=	gssapi kerberos
.include "../../mk/bsd.options.mk"

###
### Kerberos authentication is via GSSAPI.
###
.if !empty(PKG_OPTIONS:Mkerberos)
.  if empty(PKG_OPTIONS:Mgssapi)
PKG_OPTIONS+=	gssapi
.  endif
.endif

###
### Authentication via GSSAPI (which supports primarily Kerberos 5)
###
.if !empty(PKG_OPTIONS:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gssapi=${KRB5BASE}
CONFIGURE_ARGS+=	--with-gss_impl=${GSSIMPL.${KRB5_TYPE}}
GSSIMPL.heimdal=	heimdal
GSSIMPL.mit-krb5=	mit
PLIST_SUBST+=		GSSAPI=
.else
PLIST_SUBST+=		GSSAPI="@comment "
.endif
