# $NetBSD: buildlink3.mk,v 1.15 2026/11/13 14:39:31 pho Exp $

BUILDLINK_TREE+=	hs-lua

.if !defined(HS_LUA_BUILDLINK3_MK)
HS_LUA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lua+=	hs-lua>=2.3.3
BUILDLINK_ABI_DEPENDS.hs-lua+=	hs-lua>=2.3.3nb4
BUILDLINK_PKGSRCDIR.hs-lua?=	../../lang/hs-lua

.include "../../lang/lua54/buildlink3.mk"
.endif	# HS_LUA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lua
