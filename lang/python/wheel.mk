# $NetBSD: wheel.mk,v 1.14 2024/01/23 19:59:25 adam Exp $
#
# Build and install Python wheels
#
# Note per PEP-518, the minimum and default requirements to create .whl files
# are py-setuptools plus py-wheel; however, there are various other possible
# tools that projects can use. Thus inclusion of this file does not imply these
# defaults are defined as TOOL_DEPENDS. This must be done in the package Makefile.
#
# Variables:
#
# WHEELFILE:		path to the wheelfile to be installed
#			only needs to be set if do-build is redefined
#
# USE_PYTEST:		If set to yes, depend on py-test and use it for testing.
#			Default: yes
#
# WHEEL_ARGS:		additional arguments to pass during build of the wheel

PY_PATCHPLIST?=	yes
PYSETUPSUBDIR?=	# empty

WHEELFILE?=	${WRKSRC}/${PYSETUPSUBDIR}/dist/*.whl
WHEEL_NAME?=	${DISTNAME:C/-([^0-9])/_\1/g}
_WHEEL_INFODIR=	${WHEEL_NAME}.dist-info
PLIST_SUBST+=	WHEEL_INFODIR=${_WHEEL_INFODIR}
WHEEL_ARGS?=	# empty

PRINT_PLIST_AWK+=	{ gsub(/${_WHEEL_INFODIR:S,.,\.,g}/, "$${WHEEL_INFODIR}") }

.if !target(do-build)
TOOL_DEPENDS+= ${PYPKGPREFIX}-build>=0:../../devel/py-build
do-build:
	${RUN} cd ${WRKSRC}/${PYSETUPSUBDIR} && \
	${SETENV} ${MAKE_ENV} ${TOOL_PYTHONBIN} \
		-m build --wheel --skip-dependency-check --no-isolation ${WHEEL_ARGS}
.endif

.if !target(do-install)
TOOL_DEPENDS+= ${PYPKGPREFIX}-installer>=0.7.0nb1:../../misc/py-installer
do-install:
	${RUN} cd ${WRKSRC}/${PYSETUPSUBDIR} && \
	${SETENV} ${INSTALL_ENV} ${TOOL_PYTHONBIN} \
		-m installer --destdir ${DESTDIR:Q} --prefix ${PREFIX:Q} ${WHEELFILE}
.endif

USE_PYTEST?=	yes
.if !target(do-test) && ${USE_PYTEST:Myes}
TEST_DEPENDS+= ${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
do-test:
	${RUN} cd ${WRKSRC}/${PYSETUPSUBDIR} && \
	${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}
.endif

.include "../../lang/python/extension.mk"
