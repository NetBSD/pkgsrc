# $NetBSD: tool.mk,v 1.4 2023/10/16 23:40:20 gutteridge Exp $
#
# This mk fragment can be included in all packages that use `cython'
# and `cythonize' as tools without a version suffix.
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
.for cythontool in cython cythonize
	${RUN} \
	f="${PREFIX}/bin/${cythontool}-${PYVERSSUFFIX}"; \
	t="${BUILDLINK_DIR}/bin/${cythontool}"; \
	if ${TEST} -f $$f -a ! -f $$t ; then \
		${LN} -sf $$f $$t; \
	fi
.endfor
.endif # CYTHON_TOOL_MK
