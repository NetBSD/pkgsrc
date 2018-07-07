# $NetBSD: buildlink3.mk,v 1.1 2018/07/07 04:15:18 minskim Exp $

BUILDLINK_TREE+=	sundials

.if !defined(SUNDIALS_BUILDLINK3_MK)
SUNDIALS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sundials+=	sundials>=3.1.1
BUILDLINK_PKGSRCDIR.sundials?=		../../math/sundials
.endif	# SUNDIALS_BUILDLINK3_MK

BUILDLINK_TREE+=	-sundials
