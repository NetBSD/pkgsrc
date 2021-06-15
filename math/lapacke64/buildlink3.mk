# $NetBSD: buildlink3.mk,v 1.1 2021/06/15 04:41:52 thor Exp $

BUILDLINK_TREE+=	lapacke64

.if !defined(LAPACKE64_BUILDLINK3_MK)
LAPACKE64_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lapacke64+=	lapacke64>=3.9.0
BUILDLINK_PKGSRCDIR.lapacke?=	../../math/lapacke64

.include	"../../math/lapack64/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-lapacke64
