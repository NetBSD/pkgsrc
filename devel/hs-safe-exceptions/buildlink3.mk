# $NetBSD: buildlink3.mk,v 1.12 2026/11/13 14:39:15 pho Exp $

BUILDLINK_TREE+=	hs-safe-exceptions

.if !defined(HS_SAFE_EXCEPTIONS_BUILDLINK3_MK)
HS_SAFE_EXCEPTIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-safe-exceptions+=	hs-safe-exceptions>=0.1.7
BUILDLINK_ABI_DEPENDS.hs-safe-exceptions+=	hs-safe-exceptions>=0.1.7.4nb6
BUILDLINK_PKGSRCDIR.hs-safe-exceptions?=	../../devel/hs-safe-exceptions
.endif	# HS_SAFE_EXCEPTIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-safe-exceptions
