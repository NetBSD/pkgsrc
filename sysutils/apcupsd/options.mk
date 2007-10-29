# $NetBSD: options.mk,v 1.1 2007/10/29 12:40:58 sborrill Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.apcupsd
PKG_SUPPORTED_OPTIONS=		snmp cgi
PKG_SUGGESTED_OPTIONS=		snmp cgi

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msnmp)
.  include "../../net/net-snmp/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-snmp		# enable SNMP driver
.endif

.if !empty(PKG_OPTIONS:Mcgi)
CONFIGURE_ARGS+=	--enable-cgi		# include CGI support
CONFIGURE_ARGS+=	--with-cgi-bin=${PREFIX}/libexec/cgi-bin
PLIST_SUBST+=	CGI=
.else
PLIST_SUBST+=	CGI="@comment "
.endif
