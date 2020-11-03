# $NetBSD: options.mk,v 1.1 2020/11/03 22:46:23 otis Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.zabbix50-agent
PKG_SUPPORTED_OPTIONS+=		inet6

.if empty(MISSING_FEATURES:Minet6)
PKG_SUGGESTED_OPTIONS+=		inet6
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif
