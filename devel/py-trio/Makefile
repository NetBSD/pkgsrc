# $NetBSD: Makefile,v 1.12 2023/11/07 10:44:10 wiz Exp $

DISTNAME=	trio-0.23.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/trio/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/python-trio/trio
COMMENT=	Friendly Python library for async concurrency and I/O
LICENSE=	mit OR apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-attrs>=20.1.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-idna>=0:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-outcome>=0:../../devel/py-outcome
DEPENDS+=	${PYPKGPREFIX}-sniffio>=0:../../misc/py-sniffio
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=0:../../devel/py-sortedcontainers
TEST_DEPENDS+=	${PYPKGPREFIX}-astor>=0.8.1:../../devel/py-astor
TEST_DEPENDS+=	${PYPKGPREFIX}-async_generator>=0:../../devel/py-async_generator
TEST_DEPENDS+=	${PYPKGPREFIX}-black-[0-9]*:../../textproc/py-black
TEST_DEPENDS+=	${PYPKGPREFIX}-jedi-[0-9]*:../../editors/py-jedi
TEST_DEPENDS+=	${PYPKGPREFIX}-pylint-[0-9]*:../../devel/py-pylint
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-trio-[0-9]*:../../devel/py-test-trio
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme-[0-9]*:../../security/py-trustme

# for tests
USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-exceptiongroup>=1.0.0:../../devel/py-exceptiongroup
.endif

.include "../../lang/python/wheel.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL:test
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
