# $NetBSD: buildlink3.mk,v 1.7 2023/10/27 08:31:06 pho Exp $

BUILDLINK_TREE+=	hs-hslua-core

.if !defined(HS_HSLUA_CORE_BUILDLINK3_MK)
HS_HSLUA_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua-core+=	hs-hslua-core>=2.3.1
BUILDLINK_ABI_DEPENDS.hs-hslua-core+=	hs-hslua-core>=2.3.1
BUILDLINK_PKGSRCDIR.hs-hslua-core?=	../../lang/hs-hslua-core

.include "../../lang/hs-lua/buildlink3.mk"
.endif	# HS_HSLUA_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua-core
