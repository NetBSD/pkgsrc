# $NetBSD: buildlink3.mk,v 1.3 2022/02/26 03:58:15 pho Exp $

BUILDLINK_TREE+=	hs-lua

.if !defined(HS_LUA_BUILDLINK3_MK)
HS_LUA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lua+=	hs-lua>=2.1.0
BUILDLINK_ABI_DEPENDS.hs-lua+=	hs-lua>=2.1.0nb2
BUILDLINK_PKGSRCDIR.hs-lua?=	../../lang/hs-lua

.include "../../lang/lua53/buildlink3.mk"
.endif	# HS_LUA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lua
