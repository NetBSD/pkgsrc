# $NetBSD: Makefile,v 1.65 2018/11/11 21:56:21 adam Exp $

DISTNAME=	pytest-3.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pytest.org/
COMMENT=	Python testing tool
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-atomicwrites>=1.0:../../devel/py-atomicwrites
DEPENDS+=	${PYPKGPREFIX}-attrs>=17.4.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-more-itertools>=4.0.0:../../devel/py-more-itertools
DEPENDS+=	${PYPKGPREFIX}-pluggy>=0.7:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-py>=1.5.0:../../devel/py-py
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-funcsigs-[0-9]*:../../devel/py-funcsigs
.elif ${_PYTHON_VERSION} < 36
DEPENDS+=	${PYPKGPREFIX}-pathlib2>=2.2.0:../../devel/py-pathlib2
.endif

USE_LANGUAGES=	# none
USE_TOOLS+=	bash:build

REPLACE_PYTHON+=	_pytest/standalonetemplate.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} py.test py.test-${PYVERSSUFFIX} && \
		${MV} pytest pytest-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC}/testing && pytest-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
