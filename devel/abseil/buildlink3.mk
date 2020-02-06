# $NetBSD: buildlink3.mk,v 1.1 2020/02/06 20:11:35 adam Exp $

BUILDLINK_TREE+=	abseil

.if !defined(ABSEIL_BUILDLINK3_MK)
ABSEIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.abseil+=	abseil>=20190808
BUILDLINK_PKGSRCDIR.abseil?=	../../devel/abseil
.endif	# ABSEIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-abseil
