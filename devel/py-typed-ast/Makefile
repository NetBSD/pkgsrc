# $NetBSD: Makefile,v 1.1 2018/05/21 23:14:46 minskim Exp $

DISTNAME=	typed_ast-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=python/}
GITHUB_PROJECT=	typed_ast
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://mypy-lang.org/
COMMENT=	Optional static typing for Python
LICENSE=	apache-2.0 AND python-software-foundation

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
