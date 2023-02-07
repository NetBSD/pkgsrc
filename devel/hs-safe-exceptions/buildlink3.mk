# $NetBSD: buildlink3.mk,v 1.4 2023/02/07 01:40:48 pho Exp $

BUILDLINK_TREE+=	hs-safe-exceptions

.if !defined(HS_SAFE_EXCEPTIONS_BUILDLINK3_MK)
HS_SAFE_EXCEPTIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-safe-exceptions+=	hs-safe-exceptions>=0.1.7
BUILDLINK_ABI_DEPENDS.hs-safe-exceptions+=	hs-safe-exceptions>=0.1.7.3nb1
BUILDLINK_PKGSRCDIR.hs-safe-exceptions?=	../../devel/hs-safe-exceptions
.endif	# HS_SAFE_EXCEPTIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-safe-exceptions
