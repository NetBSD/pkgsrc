# $NetBSD: options.mk,v 1.3 2006/12/03 21:48:54 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.arping
PKG_OPTIONS_REQUIRED_GROUPS=	libnet
PKG_OPTIONS_GROUP.libnet=	arping1 arping2
PKG_SUGGESTED_OPTIONS= 	arping1

.include "../../mk/bsd.options.mk"

###
### Can't support both versions of arping
###
.if !empty(PKG_OPTIONS:Marping1) && !empty(PKG_OPTIONS:Marping2)
PKG_FAIL_REASON+=	"arping1 and arping2 cannot both be selected." \
			"This is due to the conflicting versions of libnet."
.endif

###
### Build arping1 which uses libnet 1.0.x branch as is more tested
###
.if !empty(PKG_OPTIONS:Marping1)
.	include "../../devel/libnet/buildlink3.mk"
.endif

###
### Build arping2 which uses libnet 1.1.x branch as is less tested
###
.if !empty(PKG_OPTIONS:Marping2)
.	include "../../devel/libnet11/buildlink3.mk"
.endif
