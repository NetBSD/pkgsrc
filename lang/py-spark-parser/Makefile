# $NetBSD: Makefile,v 1.6 2024/10/14 09:48:48 adam Exp $

DISTNAME=	spark_parser-1.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spark_parser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rocky/python-spark
COMMENT=	Earley-Algorithm Context-free grammar Parser Toolkit
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-click>=0:../../devel/py-click

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	spark_parser/bin/parser_coverage.py
REPLACE_PYTHON+=	spark_parser/example/expr/expr.py
REPLACE_PYTHON+=	spark_parser/example/python2/format-python.py
REPLACE_PYTHON+=	spark_parser/example/python2/reflow.py
REPLACE_PYTHON+=	spark_parser/example/python2/test/test_format.py
REPLACE_PYTHON+=	spark_parser/example/python2/test/test_format_inline.py
REPLACE_PYTHON+=	spark_parser/example/python2/test/test_parse.py
REPLACE_PYTHON+=	spark_parser/example/python2/test/test_parse_inline.py
REPLACE_PYTHON+=	spark_parser/example/python2/test/test_scan.py
REPLACE_PYTHON+=	spark_parser/example/python2/test/test_scan_inline.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} spark-parser-coverage spark-parser-coverage-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
