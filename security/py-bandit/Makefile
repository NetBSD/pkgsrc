# $NetBSD: Makefile,v 1.3 2023/11/07 22:38:03 wiz Exp $

DISTNAME=	bandit-1.7.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bandit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyCQA/bandit
COMMENT=	Security oriented static analyser for Python code
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-pbr>=2.0.0:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-gitpython>=1.0.1:../../devel/py-gitpython
DEPENDS+=	${PYPKGPREFIX}-rich-[0-9]*:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-stevedore>=1.20.0:../../devel/py-stevedore
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.8.0:../../www/py-beautifulsoup4
TEST_DEPENDS+=	${PYPKGPREFIX}-testscenarios>=0.5.0:../../devel/py-testscenarios
TEST_DEPENDS+=	${PYPKGPREFIX}-testtools>=2.3.0:../../devel/py-testtools

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

post-install:
.for bin in bandit bandit-baseline bandit-config-generator
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
