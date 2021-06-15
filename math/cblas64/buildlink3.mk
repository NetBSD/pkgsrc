# $NetBSD: buildlink3.mk,v 1.1 2021/06/15 04:41:52 thor Exp $

BUILDLINK_TREE+=	cblas64

.if !defined(CBLAS64_BUILDLINK3_MK)
CBLAS64_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cblas64+=	cblas64>=3.9.0
BUILDLINK_PKGSRCDIR.cblas64?=	../../math/cblas64

.include	"../../math/blas64/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-cblas64
