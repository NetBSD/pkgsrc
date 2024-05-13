# $NetBSD: Makefile,v 1.6 2024/05/13 09:36:52 adam Exp $

DISTNAME=	cyclonedx_bom-4.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cyclonedx-bom/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/CycloneDX/cyclonedx-python
COMMENT=	Creates CycloneDX Software Bill of Materials for Python projects
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-chardet>=5.1:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-cyclonedx-python-lib>=7.3.2:../../security/py-cyclonedx-python-lib
DEPENDS+=	${PYPKGPREFIX}-packageurl>=0.11:../../devel/py-packageurl
DEPENDS+=	${PYPKGPREFIX}-packaging>=24:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pip-requirements-parser>=32.0:../../devel/py-pip-requirements-parser
TEST_DEPENDS+=	${PYPKGPREFIX}-ddt>=1.7.2:../../devel/py-ddt
TEST_DEPENDS+=	${PYPKGPREFIX}-pdm>=2.11:../../devel/py-pdm
TEST_DEPENDS+=	${PYPKGPREFIX}-pip>=23.0:../../devel/py-pip
TEST_DEPENDS+=	${PYPKGPREFIX}-poetry>=1.7:../../devel/py-poetry

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=2.0.1:../../textproc/py-tomli
.endif

SUBST_CLASSES+=		cli
SUBST_STAGE.cli=	pre-configure
SUBST_MESSAGE.cli=	Fixing poetry executable name.
SUBST_FILES.cli=	tests/integration/test_cli_poetry.py
SUBST_SED.cli=		-e "s,'poetry','poetry-${PYVERSSUFFIX}',g"

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cyclonedx-py cyclonedx-py-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
