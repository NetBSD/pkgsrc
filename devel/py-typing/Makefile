# $NetBSD: Makefile,v 1.5 2018/01/30 08:44:31 adam Exp $

DISTNAME=	typing-3.6.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.python.org/3/library/typing.html
COMMENT=	Type Hints for Python
LICENSE=	python-software-foundation

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	35 36	# introduced in Python 3.5

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
