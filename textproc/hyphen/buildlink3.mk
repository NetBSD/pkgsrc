# $NetBSD: buildlink3.mk,v 1.1 2013/11/23 14:53:48 jaapb Exp $

BUILDLINK_TREE+=	hyphen

.if !defined(HYPHEN_BUILDLINK3_MK)
HYPHEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hyphen+=	hyphen>=2.8.6
BUILDLINK_PKGSRCDIR.hyphen?=	../../textproc/hyphen
.endif	# HYPHEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hyphen
