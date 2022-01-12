# $NetBSD: Makefile,v 1.2 2022/01/12 08:22:31 wiz Exp $

DISTNAME=	poetry-1.1.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/poetry/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://python-poetry.org/
COMMENT=	Python dependency management and packaging made easy
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-cachecontrol>=0.12.9:../../devel/py-cachecontrol
DEPENDS+=	${PYPKGPREFIX}-cachy>=0.3.0:../../devel/py-cachy
DEPENDS+=	${PYPKGPREFIX}-clikit>=0.6.2:../../comms/py-clikit
DEPENDS+=	${PYPKGPREFIX}-cleo>=0.8.1:../../comms/py-cleo
DEPENDS+=	${PYPKGPREFIX}-crashtest>=0.3.0:../../misc/py-crashtest
DEPENDS+=	${PYPKGPREFIX}-html5lib>=1.0:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-keyring>=21.2.0:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.4:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pexpect>=4.7.0:../../devel/py-pexpect
DEPENDS+=	${PYPKGPREFIX}-pkginfo>=1.4:../../devel/py-pkginfo
DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.7:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.9.1:../../devel/py-requests-toolbelt
DEPENDS+=	${PYPKGPREFIX}-requests>=2.18:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-shellingham>=1.1:../../misc/py-shellingham
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.7.0:../../textproc/py-tomlkit
DEPENDS+=	${PYPKGPREFIX}-virtualenv-[0-9]*:../../devel/py-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.0:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
.endif

USE_LANGUAGES=	# none

post-install:
	# conflicts with py-poetry-core
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/poetry/__init__.py
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/poetry/__pycache__/__init__.*
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} poetry poetry-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
