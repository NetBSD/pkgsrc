# $NetBSD: Makefile,v 1.88 2026/02/01 18:15:55 wiz Exp $

DISTNAME=	pip-26.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pip.pypa.io/
COMMENT=	Installs Python packages as an easy_install replacement
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-test_socket>=0:../../devel/py-test_socket

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	src/pip/_vendor/requests/certs.py

post-install:
	cd ${DESTDIR}${PREFIX}/${PYSITELIB}/pip/_internal && \
	${RM} build_env.py.orig commands/install.py.orig \
		operations/install/wheel.py.orig \
		req/__init__.py.orig req/req_install.py.orig
	cd ${DESTDIR}${PREFIX}/bin && \
	${RM} -f pip3 && ${MV} pip pip${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
