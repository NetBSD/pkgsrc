# $NetBSD: Makefile,v 1.86 2022/07/03 10:51:05 wiz Exp $

DISTNAME=	cryptography-37.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cryptography/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyca/cryptography
COMMENT=	Cryptographic recipes and primitives for Python
LICENSE=	apache-2.0 OR modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust-[0-9]*:../../devel/py-setuptools-rust
BUILD_DEPENDS+=	rust>=1.41:../../lang/rust
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.11.4:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-cryptography_vectors-[0-9]*:../../security/py-cryptography_vectors
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-iso8601-[0-9]*:../../time/py-iso8601
TEST_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

CARGO_WRKSRC=	${WRKSRC}/src/rust

MAKE_ENV+=	CARGO_NET_OFFLINE=true

PYTHON_VERSIONS_INCOMPATIBLE=	27

pre-build:
	cd ${WRKSRC} && ${LN} -f -s src/rust/.cargo .cargo

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
post-install:
	install_name_tool -id ${PREFIX}/${PYSITELIB}/cryptography/hazmat/bindings/_rust.abi3.so \
	${DESTDIR}${PREFIX}/${PYSITELIB}/cryptography/hazmat/bindings/_rust.abi3.so
.endif

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "cargo-depends.mk"

.include "../../lang/python/egg.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
