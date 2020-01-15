# $NetBSD: buildlink3.mk,v 1.1 2020/01/15 12:40:38 pho Exp $

BUILDLINK_TREE+=	hs-hslua

.if !defined(HS_HSLUA_BUILDLINK3_MK)
HS_HSLUA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua+=	hs-hslua>=1.0.3
BUILDLINK_ABI_DEPENDS.hs-hslua+=	hs-hslua>=1.0.3.2
BUILDLINK_PKGSRCDIR.hs-hslua?=		../../lang/hs-hslua

.include "../../devel/hs-exceptions/buildlink3.mk"
.include "../../devel/hs-fail/buildlink3.mk"
.include "../../lang/lua53/buildlink3.mk"
.endif	# HS_HSLUA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua
