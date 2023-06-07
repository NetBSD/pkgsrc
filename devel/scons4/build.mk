# $NetBSD: build.mk,v 1.1 2023/06/07 18:25:03 wiz Exp $
#
# This Makefile fragment supports building using the SCons build tool.
#
# Package-settable variables:
#
# SCONS_BUILD_ARGS
#	Arguments to pass to SCons during build. Default: empty
#
# SCONS_INSTALL_ARGS
#	Arguments to pass to SCons during installation: Default: empty
#

PYTHON_FOR_BUILD_ONLY?=	tool

.include "../../lang/python/pyversion.mk"

TOOL_DEPENDS+=	${PYPKGPREFIX}-scons>=4:../../devel/scons4

SCONSBIN=	scons-${PYVERSSUFFIX}

_SCONS_BUILD_ARGS+=	PREFIX=${PREFIX}
_SCONS_BUILD_ARGS+=	${SCONS_BUILD_ARGS}
_SCONS_INSTALL_ARGS+=	${_SCONS_BUILD_ARGS}
_SCONS_INSTALL_ARGS+=	${SCONS_INSTALL_ARGS}

.PHONY: scons-build scons-install

do-build: scons-build
scons-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONSBIN} ${_SCONS_BUILD_ARGS}

do-install: scons-install
scons-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONSBIN} ${_SCONS_INSTALL_ARGS} install

_VARGROUPS+=		scons
_PKG_VARS.scons+=	PYPKGPREFIX
_PKG_VARS.scons+=	SCONS_BUILD_ARGS
_PKG_VARS.scons+=	SCONS_INSTALL_ARGS
_PKG_VARS.scons+=	SCONSBIN
_PKG_VARS.scons+=	_SCONS_BUILD_ARGS
_PKG_VARS.scons+=	_SCONS_INSTALL_ARGS
_IGN_VARS.scons+=	MAKE_ENV PREFIX WRKSRC PYVERSSUFFIX PYTHON_FOR_BUILD_ONLY
_IGN_VARS.scons+=	SETENV TOOL_DEPENDS
#_LISTED_VARS.scons+=	*_ARGS
#_SORTED_VARS.scons+=	*_ENV
