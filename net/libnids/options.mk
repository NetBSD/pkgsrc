# $NetBSD: options.mk,v 1.6 2009/02/24 00:44:26 cube Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libnids
PKG_OPTIONS_REQUIRED_GROUPS=	libnet
PKG_OPTIONS_GROUP.libnet=	libnet10 libnet11
PKG_SUGGESTED_OPTIONS=		libnet10

.include "../../mk/bsd.options.mk"

###
### libnet 1.0.x branch support
###
.if !empty(PKG_OPTIONS:Mlibnet10)
.	include "../../devel/libnet10/buildlink3.mk"
BUILDLINK_DEPMETHOD.libnet10+=	build
SUBST_SED.conf=	-e "s|libnet-config|libnet10-config|g"
.endif

###
### libnet 1.1.x branch support
###
.if !empty(PKG_OPTIONS:Mlibnet11)
.	include "../../devel/libnet11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libnet11+=	build
SUBST_SED.conf=	-e "s|libnet-config|libnet11-config|g"
.endif
