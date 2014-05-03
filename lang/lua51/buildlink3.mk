# $NetBSD: buildlink3.mk,v 1.3 2014/05/03 13:00:44 alnsn Exp $

BUILDLINK_TREE+=	lua51

.if !defined(LUA51_BUILDLINK3_MK)
LUA51_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lua51+=	lua51>=5.1.1<5.2
BUILDLINK_PKGSRCDIR.lua51?=	../../lang/lua51

.if defined(BUILDLINK_DEPMETHOD.lua)
BUILDLINK_DEPMETHOD.lua51?=	${BUILDLINK_DEPMETHOD.lua}
.endif

# -llua -> -llua5.1
BUILDLINK_TRANSFORM+=		l:lua:lua5.1
BUILDLINK_INCDIRS.lua51+=	include/lua-5.1

BUILDLINK_FNAME_TRANSFORM.lua51+=	-e 's|lib/pkgconfig/lua-5.1.pc|lib/pkgconfig/lua.pc|'

.include "../../mk/readline.buildlink3.mk"
.endif # LUA51_BUILDLINK3_MK

BUILDLINK_TREE+=	-lua51
