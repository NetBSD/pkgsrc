# $NetBSD: buildlink3.mk,v 1.1 2026/04/15 08:04:23 kikadf Exp $

BUILDLINK_TREE+=	vali

.if !defined(VALI_BUILDLINK3_MK)
VALI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vali+=	vali>=0.1.1
BUILDLINK_PKGSRCDIR.vali?=	../../devel/vali

.endif	# VALI_BUILDLINK3_MK

BUILDLINK_TREE+=	-vali
