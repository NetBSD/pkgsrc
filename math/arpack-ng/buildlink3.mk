# $NetBSD: buildlink3.mk,v 1.1 2020/02/28 21:51:40 plunky Exp $

BUILDLINK_TREE+=	arpack-ng

.if !defined(ARPACK_NG_BUILDLINK3_MK)
ARPACK_NG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.arpack-ng+=	arpack-ng>=3.7.0
BUILDLINK_PKGSRCDIR.arpack-ng?=		../../math/arpack-ng
.endif	# ARPACK_NG_BUILDLINK3_MK

BUILDLINK_TREE+=	-arpack-ng
