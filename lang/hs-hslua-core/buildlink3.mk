# $NetBSD: buildlink3.mk,v 1.9 2024/04/29 04:00:13 pho Exp $

BUILDLINK_TREE+=	hs-hslua-core

.if !defined(HS_HSLUA_CORE_BUILDLINK3_MK)
HS_HSLUA_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua-core+=	hs-hslua-core>=2.3.2
BUILDLINK_ABI_DEPENDS.hs-hslua-core+=	hs-hslua-core>=2.3.2
BUILDLINK_PKGSRCDIR.hs-hslua-core?=	../../lang/hs-hslua-core

.include "../../lang/hs-lua/buildlink3.mk"
.endif	# HS_HSLUA_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua-core
