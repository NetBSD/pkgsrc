# $NetBSD: Makefile,v 1.1 2022/07/24 10:48:25 gdt Exp $

DISTNAME=	pydantic-1.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydantic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/samuelcolvin/pydantic
COMMENT=	Data validation and settings management using python type hints
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27 # and 36

DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4.3:../../devel/py-typing-extensions

USE_LANGUAGES=	c99

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
