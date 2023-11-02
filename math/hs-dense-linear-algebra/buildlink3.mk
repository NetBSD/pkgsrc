# $NetBSD: buildlink3.mk,v 1.2 2023/11/02 06:37:11 pho Exp $

BUILDLINK_TREE+=	hs-dense-linear-algebra

.if !defined(HS_DENSE_LINEAR_ALGEBRA_BUILDLINK3_MK)
HS_DENSE_LINEAR_ALGEBRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dense-linear-algebra+=	hs-dense-linear-algebra>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-dense-linear-algebra+=	hs-dense-linear-algebra>=0.1.0.0nb1
BUILDLINK_PKGSRCDIR.hs-dense-linear-algebra?=	../../math/hs-dense-linear-algebra

.include "../../math/hs-math-functions/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-vector-algorithms/buildlink3.mk"
.include "../../devel/hs-vector-binary-instances/buildlink3.mk"
.include "../../devel/hs-vector-th-unbox/buildlink3.mk"
.endif	# HS_DENSE_LINEAR_ALGEBRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dense-linear-algebra
