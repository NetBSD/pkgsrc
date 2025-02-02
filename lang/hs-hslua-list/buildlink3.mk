# $NetBSD: buildlink3.mk,v 1.8 2025/02/02 13:05:33 pho Exp $

BUILDLINK_TREE+=	hs-hslua-list

.if !defined(HS_HSLUA_LIST_BUILDLINK3_MK)
HS_HSLUA_LIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua-list+=	hs-hslua-list>=1.1.4
BUILDLINK_ABI_DEPENDS.hs-hslua-list+=	hs-hslua-list>=1.1.4nb1
BUILDLINK_PKGSRCDIR.hs-hslua-list?=	../../lang/hs-hslua-list

.include "../../lang/hs-hslua-core/buildlink3.mk"
.endif	# HS_HSLUA_LIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua-list
