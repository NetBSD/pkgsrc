# $NetBSD: Makefile,v 1.11 2014/01/25 10:29:58 wiz Exp $

DISTNAME=	chardet-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES=	http://pypi.python.org/packages/source/c/chardet/

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/chardet
COMMENT=	Character encoding auto-detection in Python
LICENSE=	gnu-lgpl-v2.1

REPLACE_PYTHON=			chardet/chardetect.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
