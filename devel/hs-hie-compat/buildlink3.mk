# $NetBSD: buildlink3.mk,v 1.8 2024/04/28 16:59:17 pho Exp $

BUILDLINK_TREE+=	hs-hie-compat

.if !defined(HS_HIE_COMPAT_BUILDLINK3_MK)
HS_HIE_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hie-compat+=	hs-hie-compat>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-hie-compat+=	hs-hie-compat>=0.3.1.2
BUILDLINK_PKGSRCDIR.hs-hie-compat?=	../../devel/hs-hie-compat
.endif	# HS_HIE_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hie-compat
