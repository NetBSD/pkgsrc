# $NetBSD: tool.mk,v 1.1 2016/03/07 18:27:32 nros Exp $
#
# This mk fragment can be included in all packages that uses `cython'
# and `cythonize' as tools without version suffix.
#
# Keywords: python
#

.if !defined(CYTHON_TOOL_MK)
CYTHON_TOOL_MK=	defined

.if !defined(PYTHON_PYVERSION_MK)
.include "../../lang/python/pyversion.mk"
.endif

BUILDLINK_TARGETS+=	buildlink-bin-cython

.PHONY: buildlink-bin-cython
buildlink-bin-cython:
.for CYTHONTOOL in cython cythonize
	${RUN} \
	f="${PREFIX}/bin/${CYTHONTOOL}${PYVERSSUFFIX}"; \
	t="${BUILDLINK_DIR}/bin/${CYTHONTOOL}"; \
	if ${TEST} -f $$f -a ! -f $$t ; then \
		${LN} -sf $$f $$t; \
	fi
.endfor
.endif # CYTHON_TOOL_MK
