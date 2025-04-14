# $NetBSD: Makefile,v 1.28 2025/04/14 10:04:42 adam Exp $

DISTNAME=	asttokens-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asttokens/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gristlabs/asttokens
COMMENT=	Annotate AST trees with source code positions
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.3:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-astroid-[0-9]*:../../devel/py-astroid

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
