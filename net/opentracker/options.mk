# $NetBSD: options.mk,v 1.1 2020/11/16 08:43:13 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opentracker
PKG_SUPPORTED_OPTIONS=	opentracker-ipv6-only opentracker-restrictions
PKG_SUGGESTED_OPTIONS=	opentracker-restrictions

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopentracker-ipv6-only)
CFLAGS+=	-DWANT_V6
.endif

.if !empty(PKG_OPTIONS:Mopentracker-restrictions)
CFLAGS+=	-DWANT_ACCESSLIST_WHITE
CFLAGS+=	-DWANT_RESTRICT_STATS
DEPENDS+=	torrentutils-[0-9]*:../../net/torrentutils
.endif
