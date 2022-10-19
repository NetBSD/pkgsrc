# $NetBSD: dependency.mk,v 1.1 2022/10/19 14:17:54 nia Exp $
#
# Not for public use - use through versioned_dependencies.mk.
#

.include "../../security/py-cryptography/dependency.mk"

.if ${PYCRYPTOGRAPHY_TYPE:tl} == "rust"
PYOPENSSL_VERSION?=	OpenSSL>=0
PYOPENSSL_DIR?=		security/py-OpenSSL
.else
PYOPENSSL_VERSION?=	OpenSSL>=0<22.0.0
PYOPENSSL_DIR?=		security/py27-OpenSSL
.endif

.if "${type}" == ":build"
BUILD_DEPENDS:=	${BUILD_DEPENDS} ${PYPKGPREFIX}-${PYOPENSSL_VERSION}:../../${PYOPENSSL_DIR}
.elif "${type}" == ":test"
TEST_DEPENDS:=	${TEST_DEPENDS} ${PYPKGPREFIX}-${PYOPENSSL_VERSION}:../../${PYOPENSSL_DIR}
.elif "${type}" == ":tool"
TOOL_DEPENDS:=	${TOOL_DEPENDS} ${PYPKGPREFIX}-${PYOPENSSL_VERSION}:../../${PYOPENSSL_DIR}
.else
DEPENDS:=	${DEPENDS} ${PYPKGPREFIX}-${PYOPENSSL_VERSION}:../../${PYOPENSSL_DIR}
.endif
