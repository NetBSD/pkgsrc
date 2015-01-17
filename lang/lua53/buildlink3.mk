# $NetBSD: buildlink3.mk,v 1.1.1.1 2015/01/17 17:50:23 alnsn Exp $

BUILDLINK_TREE+=	lua53

.if !defined(LUA53_BUILDLINK3_MK)
LUA53_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lua53+=	lua53>=5.3.0<5.4
BUILDLINK_PKGSRCDIR.lua53?=	../../lang/lua53

.if defined(BUILDLINK_DEPMETHOD.lua)
BUILDLINK_DEPMETHOD.lua53?=	${BUILDLINK_DEPMETHOD.lua}
.endif

# -llua -> -llua5.3
BUILDLINK_TRANSFORM+=		l:lua:lua5.3
BUILDLINK_INCDIRS.lua53+=	include/lua-5.3

BUILDLINK_FNAME_TRANSFORM.lua53+=	-e 's|lib/pkgconfig/lua-5.3.pc|lib/pkgconfig/lua.pc|'

.include "../../mk/readline.buildlink3.mk"
.endif # LUA53_BUILDLINK3_MK

BUILDLINK_TREE+=	-lua53
