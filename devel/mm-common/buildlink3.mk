# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:07 rillig Exp $

BUILDLINK_TREE+=	mm-common

.if !defined(MM_COMMON_BUILDLINK3_MK)
MM_COMMON_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.mm-common?=	build

BUILDLINK_API_DEPENDS.mm-common+=	mm-common>=0.9.6
BUILDLINK_PKGSRCDIR.mm-common?=		../../devel/mm-common
.endif	# MM_COMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-mm-common
