# $NetBSD: tool.mk,v 1.1 2019/06/08 19:51:38 leot Exp $
#
# This mk fragment can be included by all packages that need librsvg as a tool
# dependency (e.g. for rsvg-convert).
#

.if !defined(LIBRSVG_TOOL_MK)
LIBRSVG_TOOL_MK=	defined

.include "../../graphics/librsvg/available.mk"

.if ${LIBRSVG_TYPE} == "rust"
TOOL_DEPENDS+=	librsvg-[0-9]*:../../graphics/librsvg
.else
TOOL_DEPENDS+=	librsvg-[0-9]*:../../graphics/librsvg-c
.endif

.endif # LIBRSVG_TOOL_MK
