# $NetBSD: buildlink3.mk,v 1.17 2022/06/28 11:34:14 wiz Exp $

BUILDLINK_TREE+=	nqp

.if !defined(NQP_BUILDLINK3_MK)
NQP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nqp+=		nqp>=2022.06
BUILDLINK_ABI_DEPENDS.nqp+=		nqp>=2022.06nb1
BUILDLINK_PKGSRCDIR.nqp?=		../../lang/nqp

.include "../../devel/MoarVM/buildlink3.mk"
.endif # NQP_BUILDLINK3_MK

BUILDLINK_TREE+=	-nqp
