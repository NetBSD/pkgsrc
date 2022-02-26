# $NetBSD: buildlink3.mk,v 1.3 2022/02/26 03:58:04 pho Exp $

BUILDLINK_TREE+=	hs-pandoc-lua-marshal

.if !defined(HS_PANDOC_LUA_MARSHAL_BUILDLINK3_MK)
HS_PANDOC_LUA_MARSHAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pandoc-lua-marshal+=	hs-pandoc-lua-marshal>=0.1.4
BUILDLINK_ABI_DEPENDS.hs-pandoc-lua-marshal+=	hs-pandoc-lua-marshal>=0.1.4nb2
BUILDLINK_PKGSRCDIR.hs-pandoc-lua-marshal?=	../../devel/hs-pandoc-lua-marshal

.include "../../lang/hs-hslua/buildlink3.mk"
.include "../../lang/hs-hslua-marshalling/buildlink3.mk"
.include "../../lang/hs-lua/buildlink3.mk"
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.endif	# HS_PANDOC_LUA_MARSHAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pandoc-lua-marshal
