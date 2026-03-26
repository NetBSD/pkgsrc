# $NetBSD: Makefile,v 1.62 2026/03/26 14:36:13 wiz Exp $

DISTNAME=	cyclonedx_python_lib-11.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cyclonedx-python-lib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/CycloneDX/cyclonedx-python-lib
COMMENT=	Python library for generating CycloneDX SBOMs
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-license-expression>=30:../../devel/py-license-expression
DEPENDS+=	${PYPKGPREFIX}-packageurl>=0.11:../../devel/py-packageurl
DEPENDS+=	${PYPKGPREFIX}-referencing>=0.28.4:../../textproc/py-referencing
DEPENDS+=	${PYPKGPREFIX}-serializable>=2:../../devel/py-serializable
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.4.0:../../devel/py-sortedcontainers
TEST_DEPENDS+=	${PYPKGPREFIX}-ddt>=1.7.2:../../devel/py-ddt
TEST_DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.18:../../textproc/py-jsonschema
TEST_DEPENDS+=	${PYPKGPREFIX}-lxml>=4:../../textproc/py-lxml
TEST_DEPENDS+=	${PYPKGPREFIX}-xmldiff>=2.6.3:../../textproc/py-xmldiff

USE_LANGUAGES=	# none

# as of 11.7.0
# 40 failed, 6490 passed, 1387 warnings

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 313
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.6:../../devel/py-typing-extensions
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
