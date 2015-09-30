# $NetBSD: options.mk,v 1.2 2015/09/30 08:25:37 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.suck
PKG_OPTIONS_OPTIONAL_GROUPS+=	socks
PKG_OPTIONS_GROUP.socks=	socks4 dante

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msocks4)
.include "../../net/socks4/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mdante)
CFLAGS+=	-I${BUILDLINK_PREFIX.dante}/include/dante
CPPFLAGS+=	-I${BUILDLINK_PREFIX.dante}/include/dante
.include "../../net/dante/buildlink3.mk"
.endif
