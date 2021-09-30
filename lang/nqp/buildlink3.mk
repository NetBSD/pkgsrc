# $NetBSD: buildlink3.mk,v 1.15 2021/09/30 14:18:14 mef Exp $

BUILDLINK_TREE+=	nqp

.if !defined(NQP_BUILDLINK3_MK)
NQP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nqp+=		nqp>=2021.09
BUILDLINK_ABI_DEPENDS.nqp+=		nqp>=2021.09
BUILDLINK_PKGSRCDIR.nqp?=		../../lang/nqp

.include "../../devel/MoarVM/buildlink3.mk"
.endif # NQP_BUILDLINK3_MK

BUILDLINK_TREE+=	-nqp
