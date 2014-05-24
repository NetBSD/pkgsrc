# $NetBSD: buildlink3.mk,v 1.1 2014/05/24 22:00:42 szptvlfn Exp $

BUILDLINK_TREE+=	hs-exceptions

.if !defined(HS_EXCEPTIONS_BUILDLINK3_MK)
HS_EXCEPTIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-exceptions+=	hs-exceptions>=0.6.1
BUILDLINK_PKGSRCDIR.hs-exceptions?=	../../devel/hs-exceptions

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_EXCEPTIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-exceptions
