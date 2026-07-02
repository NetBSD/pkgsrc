# $NetBSD: buildlink3.mk,v 1.1 2026/07/02 19:34:01 alnsn Exp $

BUILDLINK_TREE+=	symfpu

.if !defined(SYMFPU_BUILDLINK3_MK)
SYMFPU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.symfpu+=	symfpu>=1.2.0
BUILDLINK_ABI_DEPENDS.symfpu+=	symfpu>=1.2.0
BUILDLINK_PKGSRCDIR.symfpu?=	../../math/symfpu
.endif # SYMFPU_BUILDLINK3_MK

BUILDLINK_TREE+=	-symfpu
