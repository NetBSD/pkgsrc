# $NetBSD: Makefile,v 1.19 2023/11/07 23:00:54 wiz Exp $

DISTNAME=	cyclonedx_python_lib-5.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cyclonedx-python-lib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/CycloneDX/cyclonedx-python-lib
COMMENT=	Python library for generating CycloneDX SBOMs
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-packageurl>=0.9:../../devel/py-packageurl
DEPENDS+=	${PYPKGPREFIX}-serializable>=0.11.1:../../devel/py-serializable
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.4.0:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-license-expression>=0:../../devel/py-license-expression
TEST_DEPENDS+=	${PYPKGPREFIX}-ddt>=1.6.0:../../devel/py-ddt
TEST_DEPENDS+=	${PYPKGPREFIX}-jsonschema-[0-9]*:../../textproc/py-jsonschema
TEST_DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
TEST_DEPENDS+=	${PYPKGPREFIX}-xmldiff-[0-9]*:../../textproc/py-xmldiff

PYTHON_VERSIONS_INCOMPATIBLE=	27

# https://github.com/CycloneDX/cyclonedx-python-lib/issues/435
post-install:
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/LICENSE
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/NOTICE
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/README.md

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
