# $NetBSD: buildlink3.mk,v 1.4 2014/10/07 16:47:12 adam Exp $

BUILDLINK_TREE+=	nqp

.if !defined(NQP_BUILDLINK3_MK)
NQP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nqp+=		nqp>=2013.08
BUILDLINK_ABI_DEPENDS.nqp+=		nqp>=2013.08nb4
BUILDLINK_PKGSRCDIR.nqp?=		../../lang/nqp

.include "../../lang/parrot/buildlink3.mk"
.endif # NQP_BUILDLINK3_MK

BUILDLINK_TREE+=	-nqp
