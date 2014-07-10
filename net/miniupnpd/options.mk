# $NetBSD: options.mk,v 1.6 2014/07/10 13:44:22 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.miniupnpd
PKG_OPTIONS_REQUIRED_GROUPS=	miniupnpd-fw
PKG_OPTIONS_GROUP.miniupnpd-fw=	ipfilter ipfw pf

.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=		ipfilter
.else
.  if exists(/usr/include/net/pfvar.h) || exists(/usr/include/net/pf/pfvar.h)
PKG_SUGGESTED_OPTIONS+=		pf
.  else
PKG_SUGGESTED_OPTIONS+=		ipfilter
.  endif
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mipfilter)
FWNAME=	ipf
.endif

.if !empty(PKG_OPTIONS:Mipfw)
FWNAME=	ipfw
.endif

.if !empty(PKG_OPTIONS:Mpf)
FWNAME=	pf
.endif

MAKE_ENV+=	FWNAME=${FWNAME}
