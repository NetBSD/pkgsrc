# $NetBSD: Makefile,v 1.4 2017/10/09 08:25:56 wiz Exp $

DISTNAME=	slowaes-0.1a1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/slowaes/}

MAINTAINER=	kyuupichan@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/slowaes/
COMMENT=	Implementation of AES in pure Python
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # as of 0.1a1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
