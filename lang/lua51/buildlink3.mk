# $NetBSD: buildlink3.mk,v 1.2 2013/10/30 08:59:36 obache Exp $

BUILDLINK_TREE+=	lua51

.if !defined(LUA51_BUILDLINK3_MK)
LUA51_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lua51+=	lua51>=5.1.1<5.2
BUILDLINK_PKGSRCDIR.lua51?=	../../lang/lua51

.include "../../devel/readline/buildlink3.mk"
.endif # LUA51_BUILDLINK3_MK

BUILDLINK_TREE+=	-lua51
