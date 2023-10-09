# $NetBSD: buildlink3.mk,v 1.3 2023/10/09 04:54:37 pho Exp $

BUILDLINK_TREE+=	hs-hslua-list

.if !defined(HS_HSLUA_LIST_BUILDLINK3_MK)
HS_HSLUA_LIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua-list+=	hs-hslua-list>=1.1.0
BUILDLINK_ABI_DEPENDS.hs-hslua-list+=	hs-hslua-list>=1.1.0.1nb2
BUILDLINK_PKGSRCDIR.hs-hslua-list?=	../../lang/hs-hslua-list

.include "../../lang/hs-hslua-core/buildlink3.mk"
.endif	# HS_HSLUA_LIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua-list
