# $NetBSD: options.mk,v 1.2 2008/04/12 22:43:12 jlam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.apcupsd
PKG_SUPPORTED_OPTIONS=		snmp cgi
PKG_SUGGESTED_OPTIONS=		snmp cgi

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msnmp)
.  include "../../net/net-snmp/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-snmp		# enable SNMP driver
.endif

PLIST_VARS+=		cgi
.if !empty(PKG_OPTIONS:Mcgi)
CONFIGURE_ARGS+=	--enable-cgi		# include CGI support
CONFIGURE_ARGS+=	--with-cgi-bin=${PREFIX}/libexec/cgi-bin
PLIST.cgi=		yes
.endif
