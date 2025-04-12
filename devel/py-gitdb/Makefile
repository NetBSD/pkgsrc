# $NetBSD: Makefile,v 1.10 2025/04/12 10:59:19 adam Exp $

DISTNAME=	gitdb-4.0.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gitdb/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/gitpython-developers/gitdb
COMMENT=	Git Object Database
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-smmap>=3.0.1:../../devel/py-smmap

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
