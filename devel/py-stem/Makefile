# $NetBSD: Makefile,v 1.5 2022/01/01 21:21:41 wiz Exp $

DISTNAME=	stem-1.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stem/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://stem.torproject.org/
COMMENT=	Python controller library for the tor daemon
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

TOOL_DEPENDS+=	${PYPKGPREFIX}-codestyle-[0-9]*:../../devel/py-codestyle
TOOL_DEPENDS+=	${PYPKGPREFIX}-flakes-[0-9]*:../../devel/py-flakes

DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-nacl-[0-9]*:../../security/py-nacl
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox

REPLACE_PYTHON+=	cache_fallback_directories.py
REPLACE_PYTHON+=	cache_manual.py
REPLACE_PYTHON+=	run_tests.py
REPLACE_PYTHON+=	setup.py
REPLACE_PYTHON+=	tor-prompt

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ./run_tests.py --unit

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
