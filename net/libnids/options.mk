# $NetBSD: options.mk,v 1.4 2007/02/22 19:26:54 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libnids
PKG_SUPPORTED_OPTIONS=	libnet10 libnet11
PKG_SUGGESTED_OPTIONS=	libnet10

.include "../../mk/bsd.options.mk"

###
### Can't support both versions of libnet
###
.if !empty(PKG_OPTIONS:Mlibnet10) && !empty(PKG_OPTIONS:Mlibnet11)
PKG_FAIL_REASON+=	"libnet-1.0.x and libnet-1.1.x cannot both be selected." \
			"This is due to the packages conflicting."
.endif

###
### libnet 1.0.x branch support
###
.if !empty(PKG_OPTIONS:Mlibnet10)
.	include "../../devel/libnet10/buildlink3.mk"
BUILDLINK_DEPMETHOD.libnet10=	build
SUBST_SED.conf=	-e "s|libnet-config|libnet10-config|g"
.endif

###
### libnet 1.1.x branch support
###
.if !empty(PKG_OPTIONS:Mlibnet11)
.	include "../../devel/libnet11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libnet11=	build
SUBST_SED.conf=	-e "s|libnet-config|libnet11-config|g"
.endif
