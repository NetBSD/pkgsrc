# $NetBSD: Makefile,v 1.26 2023/12/11 09:55:08 wiz Exp $

DISTNAME=	isort-5.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/isort/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyCQA/isort
COMMENT=	Python utility/library to sort imports
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.3:../../comms/py-colorama
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.10.1:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-black>=0:../../textproc/py-black
TEST_DEPENDS+=	${PYPKGPREFIX}-lama>=7.7:../../devel/py-lama
TEST_DEPENDS+=	${PYPKGPREFIX}-toml>=0.10.2:../../textproc/py-toml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
.for bin in isort isort-identify-imports
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests/unit

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
