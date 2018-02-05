# $NetBSD: Makefile,v 1.1 2018/02/05 16:22:42 adam Exp $

DISTNAME=	async_generator-1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/async_generator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-trio/async_generator
COMMENT=	Async generators and context managers for Python 3.5+
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	36 35

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
