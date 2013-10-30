# $NetBSD: buildlink3.mk,v 1.1 2013/10/30 06:18:09 dholland Exp $

BUILDLINK_TREE+=	lua51

.if !defined(LUA51_BUILDLINK3_MK)
LUA51_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lua51+=	lua51>=5.1.1<5.2
BUILDLINK_ABI_DEPENDS.lua51+=	lua51>=5.1.4nb1<5.2
BUILDLINK_PKGSRCDIR.lua51?=	../../lang/lua51

.include "../../devel/readline/buildlink3.mk"
.endif # LUA51_BUILDLINK3_MK

BUILDLINK_TREE+=	-lua51
