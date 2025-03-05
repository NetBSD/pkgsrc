# $NetBSD: buildlink3.mk,v 1.11 2025/03/05 03:39:15 pho Exp $

BUILDLINK_TREE+=	hs-hie-compat

.if !defined(HS_HIE_COMPAT_BUILDLINK3_MK)
HS_HIE_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hie-compat+=	hs-hie-compat>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-hie-compat+=	hs-hie-compat>=0.3.1.2nb3
BUILDLINK_PKGSRCDIR.hs-hie-compat?=	../../devel/hs-hie-compat
.endif	# HS_HIE_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hie-compat
