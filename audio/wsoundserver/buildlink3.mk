# $NetBSD: buildlink3.mk,v 1.13 2010/01/18 09:58:39 wiz Exp $

BUILDLINK_TREE+=	wsoundserver

.if !defined(WSOUNDSERVER_BUILDLINK3_MK)
WSOUNDSERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wsoundserver+=	wsoundserver>=0.4.0nb4
BUILDLINK_ABI_DEPENDS.wsoundserver+=	wsoundserver>=0.4.0nb11
BUILDLINK_PKGSRCDIR.wsoundserver?=	../../audio/wsoundserver

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../devel/libdockapp/buildlink3.mk"
.include "../../devel/libproplist/buildlink3.mk"
.include "../../wm/windowmaker/buildlink3.mk"
.endif # WSOUNDSERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-wsoundserver
