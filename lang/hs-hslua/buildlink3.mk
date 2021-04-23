# $NetBSD: buildlink3.mk,v 1.2 2021/04/23 09:47:37 pho Exp $

BUILDLINK_TREE+=	hs-hslua

.if !defined(HS_HSLUA_BUILDLINK3_MK)
HS_HSLUA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua+=	hs-hslua>=1.3.0
BUILDLINK_ABI_DEPENDS.hs-hslua+=	hs-hslua>=1.3.0.1
BUILDLINK_PKGSRCDIR.hs-hslua?=		../../lang/hs-hslua

.include "../../lang/lua53/buildlink3.mk"
.endif	# HS_HSLUA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua
