# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:36:11 wiz Exp $

BUILDLINK_TREE+=	hyphen

.if !defined(HYPHEN_BUILDLINK3_MK)
HYPHEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hyphen+=	hyphen>=2.8.6
BUILDLINK_ABI_DEPENDS.hyphen?=	hyphen>=2.8.8nb5
BUILDLINK_PKGSRCDIR.hyphen?=	../../textproc/hyphen
.endif	# HYPHEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hyphen
