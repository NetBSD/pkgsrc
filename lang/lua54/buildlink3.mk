# $NetBSD: buildlink3.mk,v 1.2 2020/06/30 13:48:59 nia Exp $

BUILDLINK_TREE+=	lua54

.if !defined(LUA54_BUILDLINK3_MK)
LUA54_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lua54+=	lua54>=5.4.0<5.5
BUILDLINK_PKGSRCDIR.lua54?=	../../lang/lua54

.if defined(BUILDLINK_DEPMETHOD.lua)
BUILDLINK_DEPMETHOD.lua54?=	${BUILDLINK_DEPMETHOD.lua}
.endif

# -llua -> -llua5.4
BUILDLINK_TRANSFORM+=		l:lua:lua5.4
BUILDLINK_INCDIRS.lua54+=	include/lua-5.4

.include "../../mk/readline.buildlink3.mk"
.endif # LUA54_BUILDLINK3_MK

BUILDLINK_TREE+=	-lua54
