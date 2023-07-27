# $NetBSD: build.mk,v 1.6 2023/07/27 10:16:39 adam Exp $
#
# This Makefile fragment supports building using the SCons build tool.
#
# Package-settable variables:
#
# SCONS_BUILD_ARGS
#	Arguments to pass to SCons during build. Default: empty
#
# SCONS_TEST_ARGS
#	Arguments to pass to SCons during testing. Default: empty
#
# SCONS_INSTALL_ARGS
#	Arguments to pass to SCons during installation: Default: empty
#
# SCONS_DO_INSTALL
#	Use scons' install target. (Some scons scripts do not provide this.)
#	Default: yes
#

PYTHON_FOR_BUILD_ONLY?=		tool
# scons4 does not support Python 2
PYTHON_VERSIONS_INCOMPATIBLE+=	27

SCONS_DO_INSTALL?=	yes

.include "../../lang/python/pyversion.mk"

TOOL_DEPENDS+=	${PYPKGPREFIX}-scons>=4.5.2nb1:../../devel/scons4

SCONSBIN=	scons-${PYVERSSUFFIX}

_SCONS_BUILD_ARGS+=	PREFIX=${PREFIX}
_SCONS_BUILD_ARGS+=	-j${MAKE_JOBS:U1}
_SCONS_BUILD_ARGS+=	${SCONS_BUILD_ARGS}
_SCONS_INSTALL_ARGS+=	${_SCONS_BUILD_ARGS}
_SCONS_INSTALL_ARGS+=	${SCONS_INSTALL_ARGS}
_SCONS_TEST_ARGS+=	${_SCONS_BUILD_ARGS}
_SCONS_TEST_ARGS+=	${SCONS_TEST_ARGS}

.PHONY: scons-build scons-test scons-install

do-build: scons-build
scons-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONSBIN} ${_SCONS_BUILD_ARGS}

do-test: scons-test
scons-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${SCONSBIN} ${_SCONS_TEST_ARGS} check

.if ${SCONS_DO_INSTALL} == "yes"
do-install: scons-install
scons-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${SCONSBIN} ${_SCONS_INSTALL_ARGS} ${INSTALL_TARGET}
.endif

_VARGROUPS+=		scons
_PKG_VARS.scons+=	PYPKGPREFIX
_PKG_VARS.scons+=	SCONS_BUILD_ARGS
_PKG_VARS.scons+=	SCONS_DO_INSTALL
_PKG_VARS.scons+=	SCONS_TEST_ARGS
_PKG_VARS.scons+=	SCONS_INSTALL_ARGS
_PKG_VARS.scons+=	SCONSBIN
_PKG_VARS.scons+=	_SCONS_BUILD_ARGS
_PKG_VARS.scons+=	_SCONS_TEST_ARGS
_PKG_VARS.scons+=	_SCONS_INSTALL_ARGS
_IGN_VARS.scons+=	MAKE_JOBS PREFIX WRKSRC PYVERSSUFFIX PYTHON_FOR_BUILD_ONLY
_IGN_VARS.scons+=	PYTHON_VERSIONS_INCOMPATIBLE
_IGN_VARS.scons+=	SETENV TOOL_DEPENDS MAKE_ENV TEST_ENV INSTALL_ENV
#_LISTED_VARS.scons+=	*_ARGS
#_SORTED_VARS.scons+=	*_ENV
