# $NetBSD: buildlink3.mk,v 1.2 2022/07/06 15:16:59 adam Exp $

BUILDLINK_TREE+=	abseil

.if !defined(ABSEIL_BUILDLINK3_MK)
ABSEIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.abseil+=	abseil>=20220623.0
BUILDLINK_PKGSRCDIR.abseil?=	../../devel/abseil
.endif	# ABSEIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-abseil
