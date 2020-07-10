# $NetBSD: Makefile,v 1.11 2020/07/10 19:46:32 adam Exp $

DISTNAME=	typing-3.7.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.python.org/3/library/typing.html
COMMENT=	Type Hints for Python
LICENSE=	python-software-foundation

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27	# introduced in Python 3.5

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
