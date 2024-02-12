# $NetBSD: buildlink3.mk,v 1.15 2024/02/12 02:59:44 mef Exp $

BUILDLINK_TREE+=	MoarVM

.if !defined(MOARVM_BUILDLINK3_MK)
MOARVM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.MoarVM+=	MoarVM>=2024.01
BUILDLINK_ABI_DEPENDS.MoarVM+=	MoarVM>=2024.01
BUILDLINK_PKGSRCDIR.MoarVM?=	../../devel/MoarVM

.include "../../devel/libatomic_ops/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../math/ltm/buildlink3.mk"
.endif	# MOARVM_BUILDLINK3_MK

BUILDLINK_TREE+=	-MoarVM
