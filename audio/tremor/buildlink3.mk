# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:23:59 joerg Exp $

BUILDLINK_TREE+=	tremor

.if !defined(TREMOR_BUILDLINK3_MK)
TREMOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tremor+=	tremor>=1.0.2
BUILDLINK_ABI_DEPENDS.tremor+=	tremor>=1.0.2nb5
BUILDLINK_PKGSRCDIR.tremor?=	../../audio/tremor
.endif # TREMOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-tremor
