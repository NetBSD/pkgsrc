# $NetBSD: buildlink3.mk,v 1.6 2020/01/11 09:00:30 pho Exp $

BUILDLINK_TREE+=	hs-exceptions

.if !defined(HS_EXCEPTIONS_BUILDLINK3_MK)
HS_EXCEPTIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-exceptions+=	hs-exceptions>=0.10.4
BUILDLINK_ABI_DEPENDS.hs-exceptions+=	hs-exceptions>=0.10.4
BUILDLINK_PKGSRCDIR.hs-exceptions?=	../../devel/hs-exceptions
.endif	# HS_EXCEPTIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-exceptions
