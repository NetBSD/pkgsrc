# $NetBSD: buildlink3.mk,v 1.10 2023/11/02 06:37:04 pho Exp $

BUILDLINK_TREE+=	hs-vector-binary-instances

.if !defined(HS_VECTOR_BINARY_INSTANCES_BUILDLINK3_MK)
HS_VECTOR_BINARY_INSTANCES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vector-binary-instances+=	hs-vector-binary-instances>=0.2.5
BUILDLINK_ABI_DEPENDS.hs-vector-binary-instances+=	hs-vector-binary-instances>=0.2.5.2nb8
BUILDLINK_PKGSRCDIR.hs-vector-binary-instances?=	../../devel/hs-vector-binary-instances

.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_VECTOR_BINARY_INSTANCES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vector-binary-instances
