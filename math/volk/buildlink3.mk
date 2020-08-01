# $NetBSD: buildlink3.mk,v 1.1 2020/08/01 04:35:09 tnn Exp $

BUILDLINK_TREE+=	volk

.if !defined(VOLK_BUILDLINK3_MK)
VOLK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.volk+=	volk>=2.3.0
BUILDLINK_PKGSRCDIR.volk?=	../../math/volk

.include "../../devel/orc/buildlink3.mk"
.endif	# VOLK_BUILDLINK3_MK

BUILDLINK_TREE+=	-volk
