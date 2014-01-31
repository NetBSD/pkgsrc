# $NetBSD: versioned_dependencies.mk,v 1.11 2014/01/31 11:26:12 wiz Exp $
#
# This file determines which separate distribution of a Python
# package is used as dependency, depending on the Python version
# used.
#
# === User-settable variables ===
#
# PYTHON_VERSIONED_DEPENDENCIES
#       The Python package which should be added as a dependency.
#
#       Possible values: dateutil
#       Default: (nothing)
#

.include "../../lang/python/pyversion.mk"

_SUPPORTED_PACKAGES=# empty
_SUPPORTED_PACKAGES+=Pmw x11/py-Pmw x11/py-Pmw2
_SUPPORTED_PACKAGES+=X x11/py-X2 x11/py-X
_SUPPORTED_PACKAGES+=cairo graphics/py-cairo graphics/py-cairo3
_SUPPORTED_PACKAGES+=dateutil time/py-dateutil time/py-dateutil2
_SUPPORTED_PACKAGES+=dns net/py-dns net/py-dns3
_SUPPORTED_PACKAGES+=ephem math/py-ephem math/py-ephem3
_SUPPORTED_PACKAGES+=flup www/py-flup www/py-flup3
_SUPPORTED_PACKAGES+=jsonlib textproc/py-jsonlib textproc/py-jsonlib3
_SUPPORTED_PACKAGES+=unittest2 devel/py-unittest2 devel/py-unittest2py3k

.for pattern in ${PYTHON_VERSIONED_DEPENDENCIES}
_PKG_MATCHED=	no
pkg:=	${pattern:C/:.*//}
type:=	${pattern:C/[^:]*//}
.for name py2dir py3dir in ${_SUPPORTED_PACKAGES}
.if "${pkg}" == "${name}"
_PKG_MATCHED=	yes
.if ${PYPKGPREFIX} == "py26" || ${PYPKGPREFIX} == "py27"
dir:=	${py2dir}
.else
dir:=	${py3dir}
.endif
.if "${type}" == ":link"
.include "../../${dir}/buildlink3.mk"
.elif "${type}" == ":build"
BUILD_DEPENDS:=	${BUILD_DEPENDS} ${PYPKGPREFIX}-${pkg}-[0-9]*:../../${dir}
.else
DEPENDS:=	${DEPENDS} ${PYPKGPREFIX}-${pkg}-[0-9]*:../../${dir}
.endif
.endif
.endfor
.if ${_PKG_MATCHED} == "no"
PKG_FAIL_REASON=	"${pkg} unsupported in PYTHON_VERSIONED_DEPENDENCIES"
.endif
.endfor
