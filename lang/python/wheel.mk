# $NetBSD: wheel.mk,v 1.10 2023/10/28 19:57:10 wiz Exp $
#
# Build and install Python wheels
#
# Variables:
#
# WHEELFILE:		path to the wheelfile to be installed
#			only needs to be set if do-build is redefined
#

PY_PATCHPLIST?=	yes

WHEELFILE?=	${WRKSRC}/dist/*.whl
WHEEL_NAME?=	${DISTNAME:C/-([^0-9])/_\1/g}
_WHEEL_INFODIR=	${WHEEL_NAME}.dist-info
PLIST_SUBST+=	WHEEL_INFODIR=${_WHEEL_INFODIR}

PRINT_PLIST_AWK+=	{ gsub(/${_WHEEL_INFODIR:S,.,\.,g}/, "$${WHEEL_INFODIR}") }

.if !target(do-build)
TOOL_DEPENDS+= ${PYPKGPREFIX}-build>=0:../../devel/py-build
do-build:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${TOOL_PYTHONBIN} \
		-m build --wheel --skip-dependency-check --no-isolation
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
