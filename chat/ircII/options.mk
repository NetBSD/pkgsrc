# $NetBSD: options.mk,v 1.3 2019/11/02 22:18:22 rillig Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ircII
PKG_SUPPORTED_OPTIONS=		# only socks group
PKG_OPTIONS_OPTIONAL_GROUPS=	socks
PKG_OPTIONS_GROUP.socks=	socks4 dante

.include "../../mk/bsd.options.mk"

# Include SOCKS firewall support
.if !empty(PKG_OPTIONS:Msocks4)
.include "../../net/socks4/buildlink3.mk"
CONFIGURE_ARGS+=	--with-socks4=${BUILDLINK_PREFIX.socks4}
.endif
.if !empty(PKG_OPTIONS:Mdante)
.include "../../net/dante/buildlink3.mk"
CONFIGURE_ARGS+=	--with-socks4=${BUILDLINK_PREFIX.dante}
.endif
