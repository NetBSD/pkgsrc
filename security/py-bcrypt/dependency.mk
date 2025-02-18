#
# Not for public use - use through versioned_dependencies.mk.
#
# User-settable variables:
#
# PYBCRYPT_TYPE
#	Type of py-bcrypt implementation used.
#
#	Possible values: c rust
#	Default: rust on platforms were Rust is supported
#

.include "../../mk/bsd.fast.prefs.mk"

.include "../../lang/rust/platform.mk"
.if ${PLATFORM_SUPPORTS_RUST:tl} == "yes"
PYBCRYPT_TYPE?=	rust
.else
PYBCRYPT_TYPE?=	c
.endif

.include "../../lang/python/pyversion.mk"
.if ${PYBCRYPT_TYPE:tl} == "rust"
PYBCRYPT_VERSION?=	bcrypt>=4
PYBCRYPT_DIR?=		security/py-bcrypt
.else
PYBCRYPT_VERSION?=	bcrypt>=3<4
PYBCRYPT_DIR?=		security/py-bcrypt3
.endif

.if "${type}" == ":build"
TOOL_DEPENDS:=	${TOOL_DEPENDS} ${PYPKGPREFIX}-${PYBCRYPT_VERSION}:../../${PYBCRYPT_DIR}
.elif "${type}" == ":test"
TEST_DEPENDS:=	${TEST_DEPENDS} ${PYPKGPREFIX}-${PYBCRYPT_VERSION}:../../${PYBCRYPT_DIR}
.elif "${type}" == ":tool"
TOOL_DEPENDS:=	${TOOL_DEPENDS} ${PYPKGPREFIX}-${PYBCRYPT_VERSION}:../../${PYBCRYPT_DIR}
.else
DEPENDS:=	${DEPENDS} ${PYPKGPREFIX}-${PYBCRYPT_VERSION}:../../${PYBCRYPT_DIR}
.endif
