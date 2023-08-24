# $NetBSD: tool.mk,v 1.3 2023/08/24 20:44:14 wiz Exp $
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
.for cythontool in cython cythonize
	${RUN} \
	f="${PREFIX}/bin/${cythontool}-${PYVERSSUFFIX}"; \
	t="${BUILDLINK_DIR}/bin/${cythontool}"; \
	if ${TEST} -f $$f -a ! -f $$t ; then \
		${LN} -sf $$f $$t; \
	fi
.endfor
.endif # CYTHON_TOOL_MK
