# $NetBSD: options.mk,v 1.1 2018/04/13 08:04:14 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mariadb-connector-c
PKG_SUPPORTED_OPTIONS=	curl kerberos
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		curl gss

.if !empty(PKG_OPTIONS:Mcurl)
PLIST.curl=		yes
.  include "../../www/curl/buildlink3.mk"
.else
CMAKE_ARGS+=		-DWITH_CURL=OFF
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
PLIST.gss=		yes
.  include "../../mk/krb5.buildlink3.mk"
.else
CMAKE_ARGS+=		-DWITH_GSS=OFF
.endif
