# $NetBSD: Makefile,v 1.10 2014/01/25 10:30:04 wiz Exp $

DISTNAME=	pyutil-1.9.3
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

PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-twisted via py-setuptools_trial, py-zbase32

REPLACE_INTERPRETER+=	python
REPLACE.python.old=	/usr/bin/env python
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	pyutil/benchmarks/bench_xor.py pyutil/lineutil.py pyutil/scripts/*.py pyutil/test/*/*.py

post-extract:
	@cd ${WRKSRC}; ${RM} pyutil/*.py~

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
