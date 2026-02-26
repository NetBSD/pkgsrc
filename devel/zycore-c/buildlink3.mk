# $NetBSD: buildlink3.mk,v 1.1 2026/02/26 22:51:44 alnsn Exp $

BUILDLINK_TREE+=	zycore-c

.if !defined(ZYCORE_C_BUILDLINK3_MK)
ZYCORE_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zycore-c+=	zycore-c>=1.5.1
BUILDLINK_ABI_DEPENDS.zycore-c+=	zycore-c>=1.5.1
BUILDLINK_PKGSRCDIR.zycore-c?=		../../devel/zycore-c
.endif	# ZYCORE_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-zycore-c
