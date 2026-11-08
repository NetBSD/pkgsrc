# $NetBSD: buildlink3.mk,v 1.2 2026/11/08 13:57:54 alnsn Exp $

BUILDLINK_TREE+=	symfpu

.if !defined(SYMFPU_BUILDLINK3_MK)
SYMFPU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.symfpu+=	symfpu>=1.2.0
BUILDLINK_ABI_DEPENDS.symfpu+=	symfpu>=1.2.0nb1
BUILDLINK_PKGSRCDIR.symfpu?=	../../math/symfpu
.endif # SYMFPU_BUILDLINK3_MK

BUILDLINK_TREE+=	-symfpu
