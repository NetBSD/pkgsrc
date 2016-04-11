# $NetBSD: buildlink3.mk,v 1.6 2016/04/11 19:01:35 ryoon Exp $

BUILDLINK_TREE+=	nqp

.if !defined(NQP_BUILDLINK3_MK)
NQP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nqp+=		nqp>=2013.08
BUILDLINK_ABI_DEPENDS.nqp+=		nqp>=2013.08nb8
BUILDLINK_PKGSRCDIR.nqp?=		../../lang/nqp

.include "../../lang/parrot/buildlink3.mk"
.endif # NQP_BUILDLINK3_MK

BUILDLINK_TREE+=	-nqp
