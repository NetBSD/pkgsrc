# $NetBSD: Makefile,v 1.27 2023/12/11 20:53:49 adam Exp $

DISTNAME=	isort-5.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/isort/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyCQA/isort
COMMENT=	Python utility/library to sort imports
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.:../../comms/py-colorama
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.10.1:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesmith>=0.1.3:../../devel/py-hypothesmith
TEST_DEPENDS+=	${PYPKGPREFIX}-black>=0:../../textproc/py-black
TEST_DEPENDS+=	${PYPKGPREFIX}-lama>=7.7:../../devel/py-lama
TEST_DEPENDS+=	${PYPKGPREFIX}-libcst>=0.3.18:../../lang/py-libcst
TEST_DEPENDS+=	${PYPKGPREFIX}-toml>=0.10.2:../../textproc/py-toml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for bin in isort isort-identify-imports
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
