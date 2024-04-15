# $NetBSD: buildlink3.mk,v 1.4 2024/04/15 09:23:36 adam Exp $

BUILDLINK_TREE+=	mm-common

.if !defined(MM_COMMON_BUILDLINK3_MK)
MM_COMMON_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.mm-common?=	build

BUILDLINK_API_DEPENDS.mm-common+=	mm-common>=0.9.6
BUILDLINK_ABI_DEPENDS.mm-common+=	mm-common>=1.0.5nb1
BUILDLINK_PKGSRCDIR.mm-common?=		../../devel/mm-common
.endif	# MM_COMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-mm-common
