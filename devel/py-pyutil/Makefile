# $NetBSD: Makefile,v 1.12 2014/05/09 07:37:02 wiz Exp $

DISTNAME=	pyutil-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyutil/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://pypi.python.org/pypi/pyutil
COMMENT=	Collection of mature utilities for Python programmers
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-setuptools_trial-[0-9]*:../../devel/py-setuptools_trial
DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-zbase32-[0-9]*:../../converters/py-zbase32

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-twisted via py-setuptools_trial, py-zbase32

REPLACE_PYTHON+=	pyutil/test/current/test_mathutil.py
REPLACE_PYTHON+=	pyutil/benchmarks/bench_xor.py pyutil/lineutil.py pyutil/scripts/*.py pyutil/test/*/*.py

post-extract:
	cd ${WRKSRC}; ${RM} pyutil/*.py~

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
