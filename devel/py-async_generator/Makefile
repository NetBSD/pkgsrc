# $NetBSD: Makefile,v 1.3 2018/08/06 19:55:28 adam Exp $

DISTNAME=	async_generator-1.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/async_generator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-trio/async_generator
COMMENT=	Async generators and context managers for Python 3.5+
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	37 36 35

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
