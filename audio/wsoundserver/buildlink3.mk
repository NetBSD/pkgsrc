# $NetBSD: buildlink3.mk,v 1.30 2020/08/17 20:17:17 leot Exp $

BUILDLINK_TREE+=	wsoundserver

.if !defined(WSOUNDSERVER_BUILDLINK3_MK)
WSOUNDSERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wsoundserver+=	wsoundserver>=0.4.0nb4
BUILDLINK_ABI_DEPENDS.wsoundserver+=	wsoundserver>=0.4.0nb28
BUILDLINK_PKGSRCDIR.wsoundserver?=	../../audio/wsoundserver

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../devel/libdockapp/buildlink3.mk"
.include "../../devel/libproplist/buildlink3.mk"
.include "../../wm/windowmaker/buildlink3.mk"
.endif # WSOUNDSERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-wsoundserver
