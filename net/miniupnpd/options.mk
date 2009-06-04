# $NetBSD: options.mk,v 1.4 2009/06/04 07:54:26 hasso Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.miniupnpd
PKG_OPTIONS_REQUIRED_GROUPS=	miniupnpd-fw
PKG_OPTIONS_GROUP.miniupnpd-fw=	pf ipfilter

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

.if !empty(PKG_OPTIONS:Mpf)
MAKE_ENV+=	FWNAME=pf
FILES_SUBST+=	FWNAME=pf
.endif
