# $NetBSD: buildlink3.mk,v 1.8 2024/05/09 01:32:10 pho Exp $

BUILDLINK_TREE+=	hs-safe-exceptions

.if !defined(HS_SAFE_EXCEPTIONS_BUILDLINK3_MK)
HS_SAFE_EXCEPTIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-safe-exceptions+=	hs-safe-exceptions>=0.1.7
BUILDLINK_ABI_DEPENDS.hs-safe-exceptions+=	hs-safe-exceptions>=0.1.7.4nb2
BUILDLINK_PKGSRCDIR.hs-safe-exceptions?=	../../devel/hs-safe-exceptions
.endif	# HS_SAFE_EXCEPTIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-safe-exceptions
