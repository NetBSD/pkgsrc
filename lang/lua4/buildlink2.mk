# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/04/29 23:15:36 jtb Exp $
#
# This Makefile fragment is included by packages that use lua4.
#

.if !defined(LUA4_BUILDLINK2_MK)
LUA4_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		lua4
BUILDLINK_DEPENDS.lua4?=	lua4>=4.0.1
BUILDLINK_PKGSRCDIR.lua4?=	../../lang/lua4

EVAL_PREFIX+=	BUILDLINK_PREFIX.lua4=lua4
BUILDLINK_PREFIX.lua4_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.lua4+=	include/lauxlib4.h
BUILDLINK_FILES.lua4+=	include/lua4.h
BUILDLINK_FILES.lua4+=	include/luadebug4.h
BUILDLINK_FILES.lua4+=	include/lualib4.h
BUILDLINK_FILES.lua4+=	lib/liblua4.*
BUILDLINK_FILES.lua4+=	lib/liblualib4.*

BUILDLINK_TARGETS+=	lua4-buildlink

lua4-buildlink: _BUILDLINK_USE

.endif	# LUA4_BUILDLINK2_MK
