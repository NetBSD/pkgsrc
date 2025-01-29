# $NetBSD: buildlink3.mk,v 1.7 2025/01/29 15:31:33 pho Exp $

BUILDLINK_TREE+=	hs-hslua-list

.if !defined(HS_HSLUA_LIST_BUILDLINK3_MK)
HS_HSLUA_LIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua-list+=	hs-hslua-list>=1.1.4
BUILDLINK_ABI_DEPENDS.hs-hslua-list+=	hs-hslua-list>=1.1.4
BUILDLINK_PKGSRCDIR.hs-hslua-list?=	../../lang/hs-hslua-list

.include "../../lang/hs-hslua-core/buildlink3.mk"
.endif	# HS_HSLUA_LIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua-list
