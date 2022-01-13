# $NetBSD: wheel.mk,v 1.2 2022/01/13 09:49:35 wiz Exp $
#
# Initial mk for building and installing python wheels
#
# Variables:
# 
# WHEELFILE:		path to the wheelfile to be installed
#			only needs to be set if do-build is redefined
#
# MASTER_SITE_WHEEL:	master site to grab wheels directly 
#			use like ${MASTER_SITE_WHEEL:=project/}
#			uses debian pypi redirector so that there
#			is no need for hashes in urls.
#
# TODO: 		fix BUILDDIR support
#			
# Feel free to contribute to this file
#			

.include "../../lang/python/pyversion.mk"

TOOL_DEPENDS+= ${PYPKGPREFIX}-pip>=0:../../devel/py-pip

WHEELFILE?= ${WRKSRC}/dist/*.whl

.if defined(NO_BUILD)

MASTER_SITE_WHEEL= https://pypi.debian.net/

WHEELFILE= ${DISTFILES}

.for i in 2 3
.if !empty(_PYTHON_VERSIONS_ACCEPTED:M${i}*)
PYMAJORVERSIONS+= py${i}
.endif
.endfor

EXTRACT_SUFX= -${PYMAJORVERSIONS:ts.}-none-any.whl

.else
#we need to build a wheel

TOOL_DEPENDS+= ${PYPKGPREFIX}-build>=0:../../devel/py-build

.if !target(do-build)
do-build:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} -m build --wheel -x -n
.endif

.endif

WHEEL_NAME?=	${DISTNAME:C/-([^0-9])/_\1/g}
_WHEEL_INFODIR=	${WHEEL_NAME}.dist-info
PLIST_SUBST+=	PYSITELIB=${PYSITELIB}
PLIST_SUBST+=	WHEEL_INFODIR=${_WHEEL_INFODIR}

PRINT_PLIST_AWK+=	{ gsub(/${_WHEEL_INFODIR:S,.,\.,g}/, "$${WHEEL_INFODIR}") }

INSTALL_ENV+= PIP_NO_CACHEDIR=1

do-install:
	${RUN} cd ${WRKDIR} && \
	${SETENV} ${INSTALL_ENV} \
	${PYTHONBIN} -m pip install --no-cache-dir --no-deps --root ${DESTDIR:Q} --prefix ${PREFIX:Q} --compile --force-reinstall -I ${WHEELFILE}
