# $NetBSD: Makefile,v 1.5 2023/01/02 13:15:56 adam Exp $

DISTNAME=	pydantic-1.10.4
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
USE_LANGUAGES=	# empty

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
