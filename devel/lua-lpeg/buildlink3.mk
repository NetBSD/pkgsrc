#	$NetBSD: buildlink3.mk,v 1.1 2025/01/24 12:45:54 riastradh Exp $

BUILDLINK_TREE+=	lua-lpeg

.if !defined(LUA_LPEG_BUILDLINK3_MK)
LUA_LPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lua-lpeg+=	${LUA_PKGPREFIX}-lpeg>=1.1.0nb1
BUILDLINK_ABI_DEPENDS.lua-lpeg+=	${LUA_PKGPREFIX}-lpeg>=1.1.0nb1
BUILDLINK_PKGSRCDIR.lua-lpeg=		../../devel/lua-lpeg

BUILDLINK_FILES.lua-lpeg+=		lib/lua/*/lpeg.so
.endif

BUILDLINK_TREE+=	-lua-lpeg
