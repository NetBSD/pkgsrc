# $NetBSD: tool.mk,v 1.1 2014/08/21 14:49:43 he Exp $

.if !defined(GYP_TOOL_MK)
GYP_TOOL_MK= defined

# Gyp really wants an executable "python"; this does it
.include "../../lang/python/tool.mk"

.endif #GYP_TOOL_MK
