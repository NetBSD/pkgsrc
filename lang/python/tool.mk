# $NetBSD: tool.mk,v 1.5 2023/11/23 11:00:52 jperkin Exp $
#
# Create `python' interpreter wrapper for applicable Python bin.
#
# This mk fragment can be included in all packages that use `python'
# as a tool without a pkgsrc-style version suffix.
#
# Keywords: python
#

.if !defined(PYTHON_TOOL_MK)
PYTHON_TOOL_MK=	defined

.if !defined(PYTHON_PYVERSION_MK)
PYTHON_FOR_BUILD_ONLY?=	tool
.include "../../lang/python/pyversion.mk"
.endif

BUILDLINK_TARGETS+=	buildlink-bin-python

.PHONY: buildlink-bin-python
buildlink-bin-python:
.for bin in python python${PYVERSSUFFIX:R}
	${RUN} \
	t=${BUILDLINK_DIR}/bin/${bin}; \
	if ${TEST} -f "${TOOL_PYTHONBIN}" -a ! -f $$t; then \
		${LN} -sf "${TOOL_PYTHONBIN}" $$t; \
	fi
.endfor

.endif # PYTHON_TOOL_MK
