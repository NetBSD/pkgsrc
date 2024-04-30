# $NetBSD: Makefile,v 1.60 2024/04/30 10:10:01 adam Exp $

DISTNAME=	dulwich-0.22.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dulwich/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dulwich.io/
COMMENT=	Python implementation of Git
LICENSE=	apache-2.0 OR gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust-[0-9]*:../../devel/py-setuptools-rust
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.25:../../www/py-urllib3
TEST_DEPENDS+=	${PYPKGPREFIX}-fastimport-[0-9]*:../../devel/py-fastimport
TEST_DEPENDS+=	${PYPKGPREFIX}-gevent-[0-9]*:../../net/py-gevent
TEST_DEPENDS+=	${PYPKGPREFIX}-geventhttpclient-[0-9]*:../../net/py-geventhttpclient
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} >= 312
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} dul-receive-pack dul-receive-pack-${PYVERSSUFFIX} && \
	${MV} dul-upload-pack dul-upload-pack-${PYVERSSUFFIX} && \
	${MV} dulwich dulwich-${PYVERSSUFFIX} || ${TRUE}

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
