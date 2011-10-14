# $NetBSD: tool.mk,v 1.1 2011/10/14 08:55:54 obache Exp $
#
# Create `python' interpreter wrapper for applicable Python bin.
#
# This mk fragment can be included in all packages that uses `python'
# as a tool without version suffix.
#
# Keywords: python
#

.if !defined(PYTHON_TOOL_MK)
PYTHON_TOOL_MK=	defined

.if !defined(PYTHON_PYVERSION_MK)
.include "../../lang/python/pyversion.mk"
.endif

BUILDLINK_TARGETS+=	buildlink-bin-python

.PHONY: buildlink-bin-python
buildlink-bin-python:
	${RUN} \
	f="${PYTHONBIN}"; \
	t="${BUILDLINK_DIR}/bin/python"; \
	if ${TEST} -f $$f -a ! -f $$t ; then \
		${LN} -sf $$f $$t; \
	fi

.endif # PYTHON_TOOL_MK
