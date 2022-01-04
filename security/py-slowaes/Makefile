# $NetBSD: Makefile,v 1.9 2022/01/04 20:54:44 wiz Exp $

DISTNAME=	slowaes-0.1a1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/slowaes/}

MAINTAINER=	kyuupichan@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/slowaes/
COMMENT=	Implementation of AES in pure Python
LICENSE=	apache-2.0

PYTHON_VERSIONS_ACCEPTED=	27 # as of 0.1a1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
