# $NetBSD: buildlink3.mk,v 1.12 2020/03/08 16:47:52 wiz Exp $

BUILDLINK_TREE+=	nqp

.if !defined(NQP_BUILDLINK3_MK)
NQP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nqp+=		nqp>=2015.11
BUILDLINK_ABI_DEPENDS.nqp+=		nqp>=2019.07.1nb2
BUILDLINK_PKGSRCDIR.nqp?=		../../lang/nqp

.include "../../devel/MoarVM/buildlink3.mk"
.endif # NQP_BUILDLINK3_MK

BUILDLINK_TREE+=	-nqp
