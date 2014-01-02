# $NetBSD: Makefile,v 1.10 2014/01/02 17:55:40 wiz Exp $

DISTNAME=	chardet-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES=	http://pypi.python.org/packages/source/c/chardet/

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/chardet
COMMENT=	Character encoding auto-detection in Python
LICENSE=	gnu-lgpl-v2.1

REPLACE_PYTHON=			chardet/chardetect.py
PYTHON_VERSIONS_INCLUDE_3X=	yes

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
