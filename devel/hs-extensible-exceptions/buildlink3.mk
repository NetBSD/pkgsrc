# $NetBSD: buildlink3.mk,v 1.5 2022/01/18 02:48:07 pho Exp $

BUILDLINK_TREE+=	hs-extensible-exceptions

.if !defined(HS_EXTENSIBLE_EXCEPTIONS_BUILDLINK3_MK)
HS_EXTENSIBLE_EXCEPTIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-extensible-exceptions+=	hs-extensible-exceptions>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-extensible-exceptions+=	hs-extensible-exceptions>=0.1.1.4nb2
BUILDLINK_PKGSRCDIR.hs-extensible-exceptions?=		../../devel/hs-extensible-exceptions
.endif	# HS_EXTENSIBLE_EXCEPTIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-extensible-exceptions
