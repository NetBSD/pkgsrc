# $NetBSD: Makefile,v 1.1 2017/02/19 18:53:25 adam Exp $

DISTNAME=	typing-3.5.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.python.org/3.5/library/typing.html
COMMENT=	Type Hints for Python
LICENSE=	python-software-foundation

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	34 27	# included in Python 3.5+

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
