# $NetBSD: buildlink3.mk,v 1.11 2019/02/16 19:39:02 bsiegert Exp $

BUILDLINK_TREE+=	nqp

.if !defined(NQP_BUILDLINK3_MK)
NQP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nqp+=		nqp>=2015.11
BUILDLINK_ABI_DEPENDS.nqp+=		nqp>=2018.12
BUILDLINK_PKGSRCDIR.nqp?=		../../lang/nqp

.include "../../devel/MoarVM/buildlink3.mk"
.endif # NQP_BUILDLINK3_MK

BUILDLINK_TREE+=	-nqp
