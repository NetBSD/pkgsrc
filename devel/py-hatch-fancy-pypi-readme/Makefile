# $NetBSD: Makefile,v 1.6 2023/10/28 19:57:00 wiz Exp $

DISTNAME=	hatch_fancy_pypi_readme-23.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hatch-fancy-pypi-readme/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hynek/hatch-fancy-pypi-readme
COMMENT=	Fancy PyPI READMEs with Hatch
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-hatchling>=0.21.0:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-build-[0-9]*:../../devel/py-build
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} hatch-fancy-pypi-readme hatch-fancy-pypi-readme-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
