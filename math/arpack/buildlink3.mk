# $NetBSD: buildlink3.mk,v 1.3 2017/02/09 06:06:25 minskim Exp $

BUILDLINK_TREE+=	arpack

.if !defined(ARPACK_BUILDLINK3_MK)
ARPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.arpack+=	arpack>=96
BUILDLINK_PKGSRCDIR.arpack?=	../../math/arpack
.endif	# ARPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-arpack
