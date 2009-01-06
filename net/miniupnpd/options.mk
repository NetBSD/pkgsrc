# $NetBSD: options.mk,v 1.1.1.1 2009/01/06 03:56:45 jmcneill Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.miniupnpd
PKG_OPTIONS_REQUIRED_GROUPS=	miniupnpd-fw
PKG_OPTIONS_GROUP.miniupnpd-fw=	pf ipfilter

.if exists(/usr/include/net/pfvar.h)
PKG_SUGGESTED_OPTIONS+=		pf
.else
PKG_SUGGESTED_OPTIONS+=		ipfilter
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mipfilter)
MAKE_ENV+=	FWNAME=ipf
.else
MAKE_ENV+=	FWNAME=pf
.endif
