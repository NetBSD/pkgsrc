# $NetBSD: buildlink3.mk,v 1.9 2024/05/09 01:31:58 pho Exp $

BUILDLINK_TREE+=	hs-hie-compat

.if !defined(HS_HIE_COMPAT_BUILDLINK3_MK)
HS_HIE_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hie-compat+=	hs-hie-compat>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-hie-compat+=	hs-hie-compat>=0.3.1.2nb1
BUILDLINK_PKGSRCDIR.hs-hie-compat?=	../../devel/hs-hie-compat
.endif	# HS_HIE_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hie-compat
