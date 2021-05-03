# $NetBSD: buildlink3.mk,v 1.3 2021/05/03 19:01:07 pho Exp $

BUILDLINK_TREE+=	hs-hslua

.if !defined(HS_HSLUA_BUILDLINK3_MK)
HS_HSLUA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua+=	hs-hslua>=1.3.0
BUILDLINK_ABI_DEPENDS.hs-hslua+=	hs-hslua>=1.3.0.1nb1
BUILDLINK_PKGSRCDIR.hs-hslua?=		../../lang/hs-hslua

.include "../../lang/lua53/buildlink3.mk"
.endif	# HS_HSLUA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua
