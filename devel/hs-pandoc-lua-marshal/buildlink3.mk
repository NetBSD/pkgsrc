# $NetBSD: buildlink3.mk,v 1.6 2023/02/07 01:40:46 pho Exp $

BUILDLINK_TREE+=	hs-pandoc-lua-marshal

.if !defined(HS_PANDOC_LUA_MARSHAL_BUILDLINK3_MK)
HS_PANDOC_LUA_MARSHAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pandoc-lua-marshal+=	hs-pandoc-lua-marshal>=0.2.0
BUILDLINK_ABI_DEPENDS.hs-pandoc-lua-marshal+=	hs-pandoc-lua-marshal>=0.2.0nb1
BUILDLINK_PKGSRCDIR.hs-pandoc-lua-marshal?=	../../devel/hs-pandoc-lua-marshal

.include "../../lang/hs-hslua/buildlink3.mk"
.include "../../lang/hs-hslua-list/buildlink3.mk"
.include "../../lang/hs-hslua-marshalling/buildlink3.mk"
.include "../../lang/hs-lua/buildlink3.mk"
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.endif	# HS_PANDOC_LUA_MARSHAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pandoc-lua-marshal
