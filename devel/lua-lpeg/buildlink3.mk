#	$NetBSD: buildlink3.mk,v 1.2 2025/02/07 07:50:33 adam Exp $

BUILDLINK_TREE+=	lua-lpeg

.if !defined(LUA_LPEG_BUILDLINK3_MK)
LUA_LPEG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lua-lpeg+=	${LUA_PKGPREFIX}-lpeg>=1.1.0nb1
BUILDLINK_ABI_DEPENDS.lua-lpeg+=	${LUA_PKGPREFIX}-lpeg>=1.1.0nb1
BUILDLINK_PKGSRCDIR.lua-lpeg=		../../devel/lua-lpeg

BUILDLINK_FILES.lua-lpeg+=	lib/lua/*/lpeg.dylib
BUILDLINK_FILES.lua-lpeg+=	lib/lua/*/lpeg.so
.endif

BUILDLINK_TREE+=	-lua-lpeg
