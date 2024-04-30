# $NetBSD: Makefile,v 1.5 2024/04/30 09:28:03 wiz Exp $

DISTNAME=	spark_parser-1.8.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	2
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spark_parser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rocky/python-spark
COMMENT=	Earley-Algorithm Context-free grammar Parser Toolkit
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-click>=0:../../devel/py-click
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.0:../../devel/py-nose

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} spark-parser-coverage spark-parser-coverage-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
