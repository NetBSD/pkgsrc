# $NetBSD: Makefile,v 1.2 2022/08/01 18:47:40 wiz Exp $

DISTNAME=	pydantic-1.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydantic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/samuelcolvin/pydantic
COMMENT=	Data validation and settings management using python type hints
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4.3:../../devel/py-typing-extensions

PYTHON_VERSIONS_INCOMPATIBLE=	27 # and 36

MAKE_ENV+=	SKIP_CYTHON=1
USE_LANGUAGES=	# empty

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
