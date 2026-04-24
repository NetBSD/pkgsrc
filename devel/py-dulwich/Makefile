# $NetBSD: Makefile,v 1.78 2026/04/24 11:07:18 adam Exp $

DISTNAME=	dulwich-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dulwich/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dulwich.io/
COMMENT=	Python implementation of Git
LICENSE=	apache-2.0 OR gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust-[0-9]*:../../devel/py-setuptools-rust
DEPENDS+=	${PYPKGPREFIX}-urllib3>=2.2.2:../../www/py-urllib3
TEST_DEPENDS+=	${PYPKGPREFIX}-fastimport-[0-9]*:../../devel/py-fastimport
TEST_DEPENDS+=	${PYPKGPREFIX}-gevent-[0-9]*:../../net/py-gevent
TEST_DEPENDS+=	${PYPKGPREFIX}-geventhttpclient-[0-9]*:../../net/py-geventhttpclient
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 312
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.6.0:../../devel/py-typing-extensions
.endif

PY_RENAME_BINARIES=	dul-receive-pack dul-upload-pack dulwich

pre-test:
	# uses atheris
	${RM} -f ${WRKSRC}/fuzzing/fuzz-targets/test_utils.py
	# E   AttributeError: '_MainThread' object has no attribute '_tstate_lock'
	${RM} -f ${WRKSRC}/tests/contrib/test_swift_smoke.py

# as of 0.22.2
# without network access
# 31 failed, 1274 passed, 272 skipped, 1 xfailed, 113 warnings
# with
# ALLOW_NETWORK_ACCESS=	yes
# 1 failed, 1304 passed, 272 skipped, 1 xfailed, 113 warnings

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
