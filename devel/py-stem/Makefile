# $NetBSD: Makefile,v 1.9 2023/06/14 15:35:31 adam Exp $

DISTNAME=	stem-1.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stem/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://stem.torproject.org/
COMMENT=	Python controller library for the tor daemon
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
TEST_DEPENDS+=	${PYPKGPREFIX}-codestyle-[0-9]*:../../devel/py-codestyle
TEST_DEPENDS+=	${PYPKGPREFIX}-flakes-[0-9]*:../../devel/py-flakes
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography

REPLACE_PYTHON+=	cache_fallback_directories.py
REPLACE_PYTHON+=	cache_manual.py
REPLACE_PYTHON+=	run_tests.py
REPLACE_PYTHON+=	setup.py
REPLACE_PYTHON+=	tor-prompt

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} run_tests.py --unit

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
