# $NetBSD: Makefile,v 1.61 2024/10/14 09:29:58 wiz Exp $

DISTNAME=	dulwich-0.22.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
# 0.22.2 is not on pypi
#MASTER_SITES=	${MASTER_SITE_PYPI:=d/dulwich/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=jelmer/}
GITHUB_PROJECT=	dulwich
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dulwich.io/
COMMENT=	Python implementation of Git
LICENSE=	apache-2.0 OR gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust-[0-9]*:../../devel/py-setuptools-rust
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.25:../../www/py-urllib3
TEST_DEPENDS+=	${PYPKGPREFIX}-fastimport-[0-9]*:../../devel/py-fastimport
TEST_DEPENDS+=	${PYPKGPREFIX}-gevent-[0-9]*:../../net/py-gevent
TEST_DEPENDS+=	${PYPKGPREFIX}-geventhttpclient-[0-9]*:../../net/py-geventhttpclient
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} dul-receive-pack dul-receive-pack-${PYVERSSUFFIX} && \
	${MV} dul-upload-pack dul-upload-pack-${PYVERSSUFFIX} && \
	${MV} dulwich dulwich-${PYVERSSUFFIX} || ${TRUE}

pre-test:
	# uses atheris
	${RM} -f ${WRKSRC}/fuzzing/fuzz-targets/test_utils.py
	# E   AttributeError: '_MainThread' object has no attribute '_tstate_lock'
	${RM} -f ${WRKSRC}/tests/contrib/test_swift_smoke.py

# as of 0.22.2
# without network access
# 31 failed, 1274 passed, 272 skipped, 1 xfailed, 113 warnings
# with
ALLOW_NETWORK_ACCESS=	yes
# 1 failed, 1304 passed, 272 skipped, 1 xfailed, 113 warnings

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
