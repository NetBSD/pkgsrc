# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:25 pho Exp $

BUILDLINK_TREE+=	hs-dense-linear-algebra

.if !defined(HS_DENSE_LINEAR_ALGEBRA_BUILDLINK3_MK)
HS_DENSE_LINEAR_ALGEBRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dense-linear-algebra+=	hs-dense-linear-algebra>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-dense-linear-algebra+=	hs-dense-linear-algebra>=0.1.0.0nb2
BUILDLINK_PKGSRCDIR.hs-dense-linear-algebra?=	../../math/hs-dense-linear-algebra

.include "../../math/hs-math-functions/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-vector-algorithms/buildlink3.mk"
.include "../../devel/hs-vector-binary-instances/buildlink3.mk"
.include "../../devel/hs-vector-th-unbox/buildlink3.mk"
.endif	# HS_DENSE_LINEAR_ALGEBRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dense-linear-algebra
