# $NetBSD: options.mk,v 1.2.30.1 2011/08/07 09:39:48 tron Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.apcupsd
PKG_SUPPORTED_OPTIONS=		cgi
PKG_SUGGESTED_OPTIONS=		cgi

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		cgi
.if !empty(PKG_OPTIONS:Mcgi)
.  include "../../graphics/gd/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cgi		# include CGI support
CONFIGURE_ARGS+=	--with-cgi-bin=${PREFIX}/libexec/cgi-bin
PLIST.cgi=		yes
.endif
