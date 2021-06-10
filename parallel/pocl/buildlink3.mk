# $NetBSD: buildlink3.mk,v 1.1 2021/06/10 21:50:29 nia Exp $

BUILDLINK_TREE+=	pocl

.if !defined(POCL_BUILDLINK3_MK)
POCL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pocl+=	pocl>=1.7nb2
BUILDLINK_PKGSRCDIR.pocl?=	../../parallel/pocl
.endif	# POCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-pocl
