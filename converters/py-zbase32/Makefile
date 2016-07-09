# $NetBSD: Makefile,v 1.10 2016/07/09 13:03:34 wiz Exp $

DISTNAME=	zbase32-1.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zbase32/}

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://pypi.python.org/pypi/zbase32/
COMMENT=	Alternate base32 encoder (not RFC 3548 compliant)
LICENSE=	modified-bsd

REPLACE_INTERPRETER+=	python
REPLACE.python.old=	/usr/bin/env python
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	zbase32/zbase32.py zbase32/test/test_zbase32.py

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 1.1.5

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
