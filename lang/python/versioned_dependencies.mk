# $NetBSD: versioned_dependencies.mk,v 1.115 2024/05/10 12:11:34 wiz Exp $
#
# This file determines which separate distribution of a Python package
# is used as dependency, depending on if Rust or C should be used.
# The C versions are old and unmaintained but on some platforms it is
# harder to get Rust running.
#
# === Package-settable variables ===
#
# PYTHON_VERSIONED_DEPENDENCIES
#       The Python package which should be added as a dependency.
#
#       Possible values: OpenSSL cryptography
#       Default: (nothing)
#

.include "../../lang/python/pyversion.mk"

_PY_VERS_PKG.OpenSSL=		security/py-OpenSSL
_PY_VERS_PKG.cryptography=	security/py-cryptography

.for pattern in ${PYTHON_VERSIONED_DEPENDENCIES}
pkg:=	${pattern:C/:.*//}
type:=	${pattern:C/[^:]*//}
.  include "../../${_PY_VERS_PKG.${pkg}}/dependency.mk"
.endfor
