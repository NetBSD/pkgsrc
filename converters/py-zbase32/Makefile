# $NetBSD: Makefile,v 1.16 2019/09/02 13:19:58 adam Exp $

DISTNAME=	zbase32-1.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zbase32/}

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	https://pypi.python.org/pypi/zbase32/
COMMENT=	Alternate base32 encoder (not RFC 3548 compliant)
LICENSE=	modified-bsd

REPLACE_INTERPRETER+=	python
REPLACE.python.old=	/usr/bin/env python
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	zbase32/zbase32.py zbase32/test/test_zbase32.py

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.1.5

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
