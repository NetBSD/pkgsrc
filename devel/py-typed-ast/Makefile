# $NetBSD: Makefile,v 1.17 2022/01/24 11:11:01 adam Exp $

DISTNAME=	typed_ast-1.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typed-ast/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/python/typed_ast
COMMENT=	Optional static typing for Python
LICENSE=	apache-2.0 AND python-software-foundation

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
