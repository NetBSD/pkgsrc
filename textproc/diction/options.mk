# $NetBSD: options.mk,v 1.1 2007/12/04 00:57:38 bjs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.diction
PKG_SUPPORTED_OPTIONS=	pcre

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpcre)
LIBPCREPOSIX=	-lpcreposix
MAKE_ENV+=	LIBPCREPOSIX=${LIBPCREPOSIX:Q}
.  include "../../devel/pcre/buildlink3.mk"
.endif
