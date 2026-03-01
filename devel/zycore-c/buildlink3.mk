# $NetBSD: buildlink3.mk,v 1.2 2026/03/01 22:34:45 alnsn Exp $

BUILDLINK_TREE+=	zycore-c

.if !defined(ZYCORE_C_BUILDLINK3_MK)
ZYCORE_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zycore-c+=	zycore-c>=1.5.1
BUILDLINK_ABI_DEPENDS.zycore-c+=	zycore-c>=1.5.1
BUILDLINK_PKGSRCDIR.zycore-c?=		../../devel/zycore-c

BUILDLINK_INCDIRS.zycore-c+=		include/Zycore

.endif	# ZYCORE_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-zycore-c
