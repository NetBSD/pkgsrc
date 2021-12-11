# $NetBSD: buildlink3.mk,v 1.3 2021/12/11 14:03:21 tnn Exp $

BUILDLINK_TREE+=	volk

.if !defined(VOLK_BUILDLINK3_MK)
VOLK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.volk+=	volk>=2.3.0
BUILDLINK_ABI_DEPENDS.volk+=	volk>=2.5.0
BUILDLINK_PKGSRCDIR.volk?=	../../math/volk

.include "../../devel/orc/buildlink3.mk"
.endif	# VOLK_BUILDLINK3_MK

BUILDLINK_TREE+=	-volk
