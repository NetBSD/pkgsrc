# $NetBSD: buildlink3.mk,v 1.22 2025/05/17 11:37:52 mef Exp $

BUILDLINK_TREE+=	MoarVM

.if !defined(MOARVM_BUILDLINK3_MK)
MOARVM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.MoarVM+=	MoarVM>=2025.04
BUILDLINK_ABI_DEPENDS.MoarVM+=	MoarVM>=2025.04
BUILDLINK_PKGSRCDIR.MoarVM?=	../../devel/MoarVM

.include "../../devel/libatomic_ops/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../math/ltm/buildlink3.mk"
.endif	# MOARVM_BUILDLINK3_MK

BUILDLINK_TREE+=	-MoarVM
