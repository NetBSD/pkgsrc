# $NetBSD: tool.mk,v 1.1 2024/11/13 13:28:17 jperkin Exp $
#
# Maturin will by default spawn as many build threads as it finds online
# CPUs, which is completely unsuitable for bulk builds.  This file should
# be used instead of a plain TOOL_DEPENDS so that MAKE_JOBS is correctly
# handled.

.if !defined(MATURIN_TOOL_MK)
MATURIN_TOOL_MK:=

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin-[0-9]*:../../devel/py-maturin

WHEEL_ARGS+=	-Cbuild-args=${_MAKE_JOBS}
.endif
