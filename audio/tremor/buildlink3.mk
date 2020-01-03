# $NetBSD: buildlink3.mk,v 1.10 2020/01/03 02:05:23 tsutsui Exp $

BUILDLINK_TREE+=	tremor

.if !defined(TREMOR_BUILDLINK3_MK)
TREMOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tremor+=	tremor>=1.0.2
BUILDLINK_ABI_DEPENDS.tremor+=	tremor>=1.0.2nb5
BUILDLINK_PKGSRCDIR.tremor?=	../../audio/tremor
.endif # TREMOR_BUILDLINK3_MK

.include "../../multimedia/libogg/buildlink3.mk"

BUILDLINK_TREE+=	-tremor
