# $NetBSD: options.mk,v 1.1 2009/12/15 13:11:18 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cue
PKG_SUPPORTED_OPTIONS=	canna idea inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6) && (${OPSYS} != "SunOS")
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mcanna)
.  include "../../inputmethod/canna-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-canna=${BUILDLINK_PREFIX.canna}
.else
CONFIGURE_ARGS+=	--without-canna
.endif

.if !empty(PKG_OPTIONS:Midea)
CONFIGURE_ARGS+=	--enable-idea
.endif
