# $NetBSD: Makefile,v 1.5 2012/10/03 00:20:16 asau Exp $
#

DISTNAME=	zbase32-1.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	http://pypi.python.org/packages/source/z/zbase32/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://pypi.python.org/pypi/zbase32/
COMMENT=	Alternate base32 encoder (not RFC 3548 compliant)
LICENSE=	modified-bsd

REPLACE_INTERPRETER+=	python
REPLACE.python.old=	/usr/bin/env python
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	zbase32/zbase32.py zbase32/test/test_zbase32.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
