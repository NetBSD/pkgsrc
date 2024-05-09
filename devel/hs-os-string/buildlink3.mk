# $NetBSD: buildlink3.mk,v 1.2 2024/05/09 01:32:06 pho Exp $

BUILDLINK_TREE+=	hs-os-string

.if !defined(HS_OS_STRING_BUILDLINK3_MK)
HS_OS_STRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-os-string+=	hs-os-string>=2.0.2
BUILDLINK_ABI_DEPENDS.hs-os-string+=	hs-os-string>=2.0.2.1nb1
BUILDLINK_PKGSRCDIR.hs-os-string?=	../../devel/hs-os-string
.endif	# HS_OS_STRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-os-string
