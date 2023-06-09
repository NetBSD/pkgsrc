# $NetBSD: Makefile,v 1.10 2023/06/09 09:39:32 adam Exp $

DISTNAME=	pydantic-1.10.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydantic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/samuelcolvin/pydantic
COMMENT=	Data validation and settings management using python type hints
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.2.0:../../devel/py-typing-extensions

PYTHON_VERSIONS_INCOMPATIBLE=	27

MAKE_ENV+=	SKIP_CYTHON=1
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
