# $NetBSD: dependency.mk,v 1.1 2022/10/19 13:37:21 nia Exp $
#
# Not for public use - use through versioned_dependencies.mk.
#
# User-settable variables:
#
# PYCRYPTOGRAPHY_TYPE
#	Type of py-cryptography implementation used.
#
#	Possible values: c rust
#	Default: rust on platforms were Rust is supported
#

.include "../../mk/bsd.fast.prefs.mk"

.include "../../lang/rust/platform.mk"
.if ${PLATFORM_SUPPORTS_RUST:tl} == "yes" && empty(_PYTHON_VERSION:M2*)
PYCRYPTOGRAPHY_TYPE?=	rust
.else
PYCRYPTOGRAPHY_TYPE?=	c
.endif

.include "../../lang/python/pyversion.mk"
.if ${PYCRYPTOGRAPHY_TYPE:tl} == "rust"
PYCRYPTOGRAPHY_VERSION?=	cryptography>=0
PYCRYPTOGRAPHY_DIR?=		security/py-cryptography
.else
PYCRYPTOGRAPHY_VERSION?=	cryptography>=0<3.4
PYCRYPTOGRAPHY_DIR?=		security/py27-cryptography
.endif

.if "${type}" == ":build"
BUILD_DEPENDS:=	${BUILD_DEPENDS} ${PYPKGPREFIX}-${PYCRYPTOGRAPHY_VERSION}:../../${PYCRYPTOGRAPHY_DIR}
.elif "${type}" == ":test"
TEST_DEPENDS:=	${TEST_DEPENDS} ${PYPKGPREFIX}-${PYCRYPTOGRAPHY_VERSION}:../../${PYCRYPTOGRAPHY_DIR}
.elif "${type}" == ":tool"
TOOL_DEPENDS:=	${TOOL_DEPENDS} ${PYPKGPREFIX}-${PYCRYPTOGRAPHY_VERSION}:../../${PYCRYPTOGRAPHY_DIR}
.else
DEPENDS:=	${DEPENDS} ${PYPKGPREFIX}-${PYCRYPTOGRAPHY_VERSION}:../../${PYCRYPTOGRAPHY_DIR}
.endif
