# $NetBSD: options.mk,v 1.5 2014/01/30 15:07:57 adam Exp $

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
MAKE_ENV+=	FWNAME=ipf
FILES_SUBST+=	FWNAME=ipfilter
.endif

.if !empty(PKG_OPTIONS:Mipfw)
MAKE_ENV+=	FWNAME=ipfw
FILES_SUBST+=	FWNAME=ipfw
.endif

.if !empty(PKG_OPTIONS:Mpf)
MAKE_ENV+=	FWNAME=pf
FILES_SUBST+=	FWNAME=pf
.endif
