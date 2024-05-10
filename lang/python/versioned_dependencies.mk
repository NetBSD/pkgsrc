# $NetBSD: versioned_dependencies.mk,v 1.112 2024/05/10 10:07:26 adam Exp $
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
#       Possible values: OpenSSL cryptography dns
#       Default: (nothing)
#

.include "../../lang/python/pyversion.mk"

# _PY_VERS_PKG.${PYTHON_VERSION}.${pkg} is the path used for the dependency
# for a specific Python version. This can be "missing", if this Python
# version is not supported for this package.
#
# _PY_VERS_PKG.default.${pkg} is the fallback version if a specific version
# isn't known.
#
# _PY_VERS_PKG.dependency.${PKG} flags packages that need Rust-specific
# handling.

_PY_VERS_PKG.default.OpenSSL=	security/py-OpenSSL
_PY_VERS_PKG.27.OpenSSL=	security/py27-OpenSSL
_PY_VERS_PKG.dependency.OpenSSL=	yes

_PY_VERS_PKG.default.cryptography=	security/py-cryptography
_PY_VERS_PKG.27.cryptography=		security/py27-cryptography
_PY_VERS_PKG.dependency.cryptography=	yes

_PY_VERS_PKG.default.dns=	net/py-dns
_PY_VERS_PKG.27.dns=		net/py-dns1

.for pattern in ${PYTHON_VERSIONED_DEPENDENCIES}
pkg:=	${pattern:C/:.*//}
type:=	${pattern:C/[^:]*//}
dir:=	${_PY_VERS_PKG.${_PYTHON_VERSION}.${pkg}:U${_PY_VERS_PKG.default.${pkg}:Umissing}}
.  if ${dir} == "missing"
PKG_FAIL_REASON+=	"${pkg} unsupported in PYTHON_VERSIONED_DEPENDENCIES"
.  else
.    if ${_PY_VERS_PKG.dependency.${pkg}:Uno} == "yes"
.      include "../../${_PY_VERS_PKG.default.${pkg}}/dependency.mk"
.    endif
.    if "${type}" == ":link"
.include "../../${dir}/buildlink3.mk"
.    elif "${type}" == ":build"
TOOL_DEPENDS:=	${TOOL_DEPENDS} ${PYPKGPREFIX}-${pkg}-[0-9]*:../../${dir}
.    elif "${type}" == ":test"
TEST_DEPENDS:=	${TEST_DEPENDS} ${PYPKGPREFIX}-${pkg}-[0-9]*:../../${dir}
.    elif "${type}" == ":tool"
TOOL_DEPENDS:=	${TOOL_DEPENDS} ${PYPKGPREFIX}-${pkg}-[0-9]*:../../${dir}
.    else
DEPENDS:=	${DEPENDS} ${PYPKGPREFIX}-${pkg}-[0-9]*:../../${dir}
.    endif
.  endif
.endfor
