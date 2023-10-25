# $NetBSD: bootstrap.mk,v 1.2 2023/10/25 22:22:49 wiz Exp $
#
# Initial mk for building and installing Python packages that
# are on the module install bootstrap path.
#
# As of October 2023, this consists of
# - devel/py-flit_core (has own build rules)
# - misc/py-installer (has own build rules)
# - devel/py-build and its dependencies:
#   - devel/py-packaging
#   - devel/py-pyparsing
#   - devel/py-pyproject_hooks


WHEELFILE?=	${WRKSRC}/dist/*.whl
PY_PATCHPLIST?=	yes

WHEEL_NAME?=	${DISTNAME:C/-([^0-9])/_\1/g}
_WHEEL_INFODIR=	${WHEEL_NAME}.dist-info
PLIST_SUBST+=	PYSITELIB=${PYSITELIB}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PLIST_SUBST+=	WHEEL_INFODIR=${_WHEEL_INFODIR}

# for ALTERNATIVES files
FILES_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

PRINT_PLIST_AWK+=	{ gsub(/${_WHEEL_INFODIR:S,.,\.,g}/, "$${WHEEL_INFODIR}") }

.if !target(do-build)
TOOL_DEPENDS+= ${PYPKGPREFIX}-flit_core>=3.9.0nb1:../../devel/py-flit_core
do-build:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${TOOL_PYTHONBIN} -m flit_core.wheel
.endif

.if !target(do-install)
TOOL_DEPENDS+= ${PYPKGPREFIX}-installer>=0.7.0nb1:../../misc/py-installer
do-install:
	${RUN} cd ${WRKSRC} && \
	${SETENV} ${INSTALL_ENV} \
	${TOOL_PYTHONBIN} -m installer --destdir ${DESTDIR:Q} \
		--prefix ${PREFIX:Q} ${WHEELFILE}
.endif

.include "../../lang/python/extension.mk"
