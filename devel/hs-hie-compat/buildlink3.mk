# $NetBSD: buildlink3.mk,v 1.3 2023/01/24 17:26:07 pho Exp $

BUILDLINK_TREE+=	hs-hie-compat

.if !defined(HS_HIE_COMPAT_BUILDLINK3_MK)
HS_HIE_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hie-compat+=	hs-hie-compat>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-hie-compat+=	hs-hie-compat>=0.3.1.0
BUILDLINK_PKGSRCDIR.hs-hie-compat?=	../../devel/hs-hie-compat
.endif	# HS_HIE_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hie-compat
