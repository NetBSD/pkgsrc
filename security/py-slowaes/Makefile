# $NetBSD: Makefile,v 1.5 2018/07/03 05:03:32 adam Exp $

DISTNAME=	slowaes-0.1a1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/slowaes/}

MAINTAINER=	kyuupichan@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/slowaes/
COMMENT=	Implementation of AES in pure Python
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.1a1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
