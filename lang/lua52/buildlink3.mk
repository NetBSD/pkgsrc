# $NetBSD: buildlink3.mk,v 1.2 2013/10/30 09:02:06 obache Exp $

BUILDLINK_TREE+=	lua52

.if !defined(LUA52_BUILDLINK3_MK)
LUA52_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lua52+=	lua52>=5.2.0<5.3
BUILDLINK_PKGSRCDIR.lua52?=	../../lang/lua52

.include "../../mk/readline.buildlink3.mk"
.endif # LUA52_BUILDLINK3_MK

BUILDLINK_TREE+=	-lua52
