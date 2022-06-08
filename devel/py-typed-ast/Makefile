# $NetBSD: Makefile,v 1.19 2022/06/08 17:18:47 adam Exp $

DISTNAME=	typed_ast-1.5.4
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
