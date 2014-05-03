# $NetBSD: tool.mk,v 1.1 2014/05/03 13:00:44 alnsn Exp $
#
# Create `lua' interpreter wrapper for applicable Lua bin.
#
# This mk fragment can be included in all packages that uses `lua'
# as a tool without version suffix.
#
# Keywords: Lua
#

.if !defined(LUA_TOOL_MK)
LUA_TOOL_MK=	defined

.if !defined(LUA_LUAVERSION_MK)
.include "../../lang/lua/luaversion.mk"
.endif

BUILDLINK_TARGETS+=	buildlink-bin-lua buildlink-bin-luac

.PHONY: buildlink-bin-lua
buildlink-bin-lua:
	${RUN} \
	f="${LUA_INTERPRETER}"; \
	t="${BUILDLINK_DIR}/bin/lua"; \
	if ${TEST} -f $$f -a ! -f $$t ; then \
		${LN} -sf $$f $$t; \
	fi

.PHONY: buildlink-bin-luac
buildlink-bin-luac:
	${RUN} \
	f="${LUA_COMPILER}"; \
	t="${BUILDLINK_DIR}/bin/luac"; \
	if ${TEST} -f $$f -a ! -f $$t ; then \
		${LN} -sf $$f $$t; \
	fi

.endif # LUA_TOOL_MK
