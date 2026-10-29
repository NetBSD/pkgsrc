# $NetBSD: Makefile,v 1.13 2026/10/29 12:01:45 adam Exp $

DISTNAME=	executing-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/executing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alexmojaki/executing
COMMENT=	Get the currently executing AST node of a frame, and other information
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-asttokens>=2.1.0:../../lang/py-asttokens
TEST_DEPENDS+=	${PYPKGPREFIX}-ipython>=0:../../devel/py-ipython
TEST_DEPENDS+=	${PYPKGPREFIX}-littleutils>=0:../../devel/py-littleutils
TEST_DEPENDS+=	${PYPKGPREFIX}-rich>=0:../../comms/py-rich

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
