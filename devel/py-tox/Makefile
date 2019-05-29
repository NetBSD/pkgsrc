# $NetBSD: Makefile,v 1.18 2019/05/29 19:56:50 adam Exp $

DISTNAME=	tox-3.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://tox.testrun.org/
COMMENT=	Virtualenv-based automation of test activities
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-filelock>=3.0.0:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-pluggy>=0.3.0<1.0:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-py>=1.4.17:../../devel/py-py
DEPENDS+=	${PYPKGPREFIX}-setuptools>=30.0.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-six>=1.0.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-toml>=0.9.4:../../textproc/py-toml
DEPENDS+=	${PYPKGPREFIX}-virtualenv>=1.11.2:../../devel/py-virtualenv
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun>=0.3.11:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=3.4.0:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-pathlib2>=2.3.3:../../devel/py-pathlib2
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.5.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=1.10.0:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly>=1.2.3:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=1.3.0:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.22.2:../../devel/py-test-xdist

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} tox tox-${PYVERSSUFFIX} && \
	${MV} tox-quickstart tox-quickstart-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
