# $NetBSD: versioned_dependencies.mk,v 1.3 2014/01/18 15:13:26 wiz Exp $
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
#_SUPPORTED_PACKAGES+=cairo graphics/py-cairo graphics/py-cairo3
_SUPPORTED_PACKAGES+=dateutil time/py-dateutil time/py-dateutil2
_SUPPORTED_PACKAGES+=dns net/py-dns net/py-dns3

.for pkg in ${PYTHON_VERSIONED_DEPENDENCIES}
_PKG_MATCHED=	no
.for name py2dir py3dir in ${_SUPPORTED_PACKAGES}
.if "${pkg}" == "${name}"
_PKG_MATCHED=	yes
.if ${PYPKGPREFIX} == "py26" || ${PYPKGPREFIX} == "py27"
DEPENDS+=	${PYPKGPREFIX}-${pkg}-[0-9]*:../../${py2dir}
.else
DEPENDS+=	${PYPKGPREFIX}-${pkg}-[0-9]*:../../${py3dir}
.endif
.endif
.endfor
.if ${_PKG_MATCHED} == "no"
PKG_FAIL_REASON=	"${pkg} unsupported in PYTHON_PACKAGE_AUTOSWITCH"
.endif
.endfor
