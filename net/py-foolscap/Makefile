# $NetBSD: Makefile,v 1.45 2025/04/22 16:00:40 adam Exp $

DISTNAME=	foolscap-24.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/foolscap/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/warner/foolscap
COMMENT=	RPC protocol for Twisted
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-twisted>=16.0.0:../../net/py-twisted
TEST_DEPENDS+=	${PYPKGPREFIX}-txtorcon>=19.0.0:../../net/py-txtorcon

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
