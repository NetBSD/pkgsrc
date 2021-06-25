# $NetBSD: Makefile,v 1.32 2021/06/25 07:25:45 adam Exp $

DISTNAME=	tqdm-4.61.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tqdm/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/tqdm/tqdm
COMMENT=	Fast, extensible progress bar for Python
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/tqdm/completion.sh

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${MV} bin/tqdm bin/tqdm-${PYVERSSUFFIX} && \
	${MV} ${PYSITELIB}/tqdm/tqdm.1 ${PKGMANDIR}/man1/tqdm-${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
