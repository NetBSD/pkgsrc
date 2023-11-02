# $NetBSD: buildlink3.mk,v 1.5 2023/11/02 06:37:08 pho Exp $

BUILDLINK_TREE+=	hs-hslua-list

.if !defined(HS_HSLUA_LIST_BUILDLINK3_MK)
HS_HSLUA_LIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua-list+=	hs-hslua-list>=1.1.1
BUILDLINK_ABI_DEPENDS.hs-hslua-list+=	hs-hslua-list>=1.1.1nb1
BUILDLINK_PKGSRCDIR.hs-hslua-list?=	../../lang/hs-hslua-list

.include "../../lang/hs-hslua-core/buildlink3.mk"
.endif	# HS_HSLUA_LIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua-list
