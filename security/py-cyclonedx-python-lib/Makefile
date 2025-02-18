# $NetBSD: Makefile,v 1.46 2025/02/18 10:43:48 wiz Exp $

DISTNAME=	cyclonedx_python_lib-8.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cyclonedx-python-lib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/CycloneDX/cyclonedx-python-lib
COMMENT=	Python library for generating CycloneDX SBOMs
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-license-expression>=30:../../devel/py-license-expression
DEPENDS+=	${PYPKGPREFIX}-packageurl>=0.11:../../devel/py-packageurl
DEPENDS+=	${PYPKGPREFIX}-serializable>=2:../../devel/py-serializable
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.4.0:../../devel/py-sortedcontainers
TEST_DEPENDS+=	${PYPKGPREFIX}-ddt>=1.7.2:../../devel/py-ddt
TEST_DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.18:../../textproc/py-jsonschema
TEST_DEPENDS+=	${PYPKGPREFIX}-lxml>=4:../../textproc/py-lxml
TEST_DEPENDS+=	${PYPKGPREFIX}-xmldiff>=2.6.3:../../textproc/py-xmldiff

USE_LANGUAGES=	# none

SUBST_CLASSES+=		s2
SUBST_SED.s2+=		-e "s,import serializable,import py_serializable as serializable,"
SUBST_SED.s2+=		-e "s,from serializable,from py_serializable,"
SUBST_FILES.s2+=	cyclonedx/model/__init__.py
SUBST_FILES.s2+=	cyclonedx/model/bom.py
SUBST_FILES.s2+=	cyclonedx/model/bom_ref.py
SUBST_FILES.s2+=	cyclonedx/model/component.py
SUBST_FILES.s2+=	cyclonedx/model/contact.py
SUBST_FILES.s2+=	cyclonedx/model/crypto.py
SUBST_FILES.s2+=	cyclonedx/model/definition.py
SUBST_FILES.s2+=	cyclonedx/model/dependency.py
SUBST_FILES.s2+=	cyclonedx/model/impact_analysis.py
SUBST_FILES.s2+=	cyclonedx/model/issue.py
SUBST_FILES.s2+=	cyclonedx/model/license.py
SUBST_FILES.s2+=	cyclonedx/model/lifecycle.py
SUBST_FILES.s2+=	cyclonedx/model/release_note.py
SUBST_FILES.s2+=	cyclonedx/model/service.py
SUBST_FILES.s2+=	cyclonedx/model/tool.py
SUBST_FILES.s2+=	cyclonedx/model/vulnerability.py
SUBST_FILES.s2+=	cyclonedx/schema/schema.py
SUBST_FILES.s2+=	cyclonedx/serialization/__init__.py
SUBST_MESSAGE.s2=	Adapting for serializable 2.x
SUBST_STAGE.s2=		pre-configure

# as of 8.8.0nb1
# 20 failed, 5223 passed, 510 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
