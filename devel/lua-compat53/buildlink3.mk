# $NetBSD: buildlink3.mk,v 1.1 2020/07/08 14:25:38 nia Exp $

BUILDLINK_TREE+=	lua-compat53

.if !defined(LUA_COMPAT53_BUILDLINK3_MK)
LUA_COMPAT53_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lua-compat53+=		${LUA_PKGPREFIX}-compat53>=0.7
BUILDLINK_PKGSRCDIR.lua-compat53?=		../../devel/lua-compat53
BUILDLINK_CONTENTS_FILTER.lua-compat53?=	${EGREP} '(\.c$$|\.h$$)'
.endif	# LUA_COMPAT53_BUILDLINK3_MK

BUILDLINK_TREE+=	-lua-compat53
