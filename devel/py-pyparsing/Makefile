# $NetBSD: Makefile,v 1.32 2024/03/06 13:33:03 adam Exp $

DISTNAME=	pyparsing-3.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyparsing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyparsing/pyparsing
COMMENT=	Parsing module for Python
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/bootstrap.mk"
.include "../../mk/bsd.pkg.mk"
