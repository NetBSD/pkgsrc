# $NetBSD: buildlink3.mk,v 1.12 2025/01/10 10:12:25 wiz Exp $

BUILDLINK_TREE+=	hs-pandoc-lua-marshal

.if !defined(HS_PANDOC_LUA_MARSHAL_BUILDLINK3_MK)
HS_PANDOC_LUA_MARSHAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pandoc-lua-marshal+=	hs-pandoc-lua-marshal>=0.3.0
BUILDLINK_ABI_DEPENDS.hs-pandoc-lua-marshal+=	hs-pandoc-lua-marshal>=0.3.0
BUILDLINK_PKGSRCDIR.hs-pandoc-lua-marshal?=	../../devel/hs-pandoc-lua-marshal

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../lang/hs-hslua/buildlink3.mk"
.include "../../lang/hs-hslua-list/buildlink3.mk"
.include "../../lang/hs-hslua-marshalling/buildlink3.mk"
.include "../../lang/hs-lua/buildlink3.mk"
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../lang/hs-hslua-list/buildlink3.mk"
.endif	# HS_PANDOC_LUA_MARSHAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pandoc-lua-marshal
