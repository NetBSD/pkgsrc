# $NetBSD: Makefile,v 1.12 2022/06/18 22:35:24 wiz Exp $

DISTNAME=	pylama-8.3.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylama/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/klen/pylama
COMMENT=	Code audit tool for Python
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-mccabe>=0.6.1:../../devel/py-mccabe
DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.8.0:../../devel/py-codestyle
DEPENDS+=	${PYPKGPREFIX}-docstyle>=6.1.1:../../devel/py-docstyle
DEPENDS+=	${PYPKGPREFIX}-flakes>=2.4.0:../../devel/py-flakes
TEST_DEPENDS+=	${PYPKGPREFIX}-eradicate>=2.0.0:../../textproc/py-eradicate
TEST_DEPENDS+=	${PYPKGPREFIX}-radon>=5.1.0:../../devel/py-radon
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy-[0-9]*:../../lang/py-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-pylint>=2.11.1:../../devel/py-pylint
# cyclic dependency. not really needed
#TEST_DEPENDS+=	${PYPKGPREFIX}-lama-quotes-[0-9]*:../../devel/py-lama-quotes
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mypy-[0-9]*:../../devel/py-test-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-types-setuptools-[0-9]*:../../devel/py-types-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-vulture-[0-9]*:../../devel/py-vulture

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pylama pylama-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
