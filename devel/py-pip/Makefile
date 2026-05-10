# $NetBSD: Makefile,v 1.91 2026/05/10 13:50:11 wiz Exp $

DISTNAME=	pip-26.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pip.pypa.io/
COMMENT=	Installs Python packages as an easy_install replacement
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-rerunfailures>=0:../../devel/py-test-rerunfailures
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=0:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-test_socket>=0:../../devel/py-test_socket

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	src/pip/_vendor/requests/certs.py

PY_RENAME_BINARIES+=	pip

post-install:
	cd ${DESTDIR}${PREFIX}/${PYSITELIB}/pip/_internal && \
	${RM} build_env.py.orig commands/install.py.orig \
		operations/install/wheel.py.orig \
		req/__init__.py.orig req/req_install.py.orig
	${RM} -f ${DESTDIR}${PREFIX}/bin/pip3

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
