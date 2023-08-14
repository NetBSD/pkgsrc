# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:24:50 wiz Exp $

BUILDLINK_TREE+=	sundials

.if !defined(SUNDIALS_BUILDLINK3_MK)
SUNDIALS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sundials+=	sundials>=3.1.1
BUILDLINK_ABI_DEPENDS.sundials?=		sundials>=4.1.0nb2
BUILDLINK_PKGSRCDIR.sundials?=		../../math/sundials
.endif	# SUNDIALS_BUILDLINK3_MK

BUILDLINK_TREE+=	-sundials
