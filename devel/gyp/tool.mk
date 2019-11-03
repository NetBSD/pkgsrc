# $NetBSD: tool.mk,v 1.3 2019/11/03 10:39:13 rillig Exp $

.if !defined(GYP_TOOL_MK)
GYP_TOOL_MK=	defined

PYTHON_VERSIONS_ACCEPTED=	27

# Gyp really wants an executable "python"; this does it
.include "../../lang/python/tool.mk"

.endif #GYP_TOOL_MK
