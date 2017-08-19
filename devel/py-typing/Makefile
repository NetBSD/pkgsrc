# $NetBSD: Makefile,v 1.3 2017/08/19 14:01:17 adam Exp $

DISTNAME=	typing-3.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.python.org/3/library/typing.html
COMMENT=	Type Hints for Python
LICENSE=	python-software-foundation

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	36	# introduced in Python 3.6

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
