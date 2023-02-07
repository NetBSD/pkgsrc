# $NetBSD: buildlink3.mk,v 1.4 2023/02/07 01:40:37 pho Exp $

BUILDLINK_TREE+=	hs-hie-compat

.if !defined(HS_HIE_COMPAT_BUILDLINK3_MK)
HS_HIE_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hie-compat+=	hs-hie-compat>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-hie-compat+=	hs-hie-compat>=0.3.1.0nb1
BUILDLINK_PKGSRCDIR.hs-hie-compat?=	../../devel/hs-hie-compat
.endif	# HS_HIE_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hie-compat
