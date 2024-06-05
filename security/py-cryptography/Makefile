# $NetBSD: Makefile,v 1.116 2024/06/05 07:26:46 adam Exp $

DISTNAME=	cryptography-42.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cryptography/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyca/cryptography
COMMENT=	Cryptographic recipes and primitives for Python
LICENSE=	apache-2.0 OR modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.0.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust>=1.7.0:../../devel/py-setuptools-rust
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.12:../../devel/py-cffi
TEST_DEPENDS+=	${PYPKGPREFIX}-cryptography_vectors-${PKGVERSION_NOREV}:../../security/py-cryptography_vectors
TEST_DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
TEST_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark-[0-9]*:../../devel/py-test-benchmark
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

CARGO_WRKSRC=	${WRKSRC}/src/rust
USE_TOOLS+=	pkg-config
MAKE_ENV+=	CARGO_NET_OFFLINE=true
MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

PYTHON_VERSIONS_INCOMPATIBLE=	27

pre-build:
	cd ${WRKSRC} && ${LN} -f -s src/rust/.cargo .cargo

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
