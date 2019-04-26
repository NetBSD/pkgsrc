# $NetBSD: Makefile,v 1.4 2019/04/26 12:44:43 roy Exp $

DISTNAME=	async_generator-1.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/async_generator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-trio/async_generator
COMMENT=	Async generators and context managers for Python 3.5+
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	37 36

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
