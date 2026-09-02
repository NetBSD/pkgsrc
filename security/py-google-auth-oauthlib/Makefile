# $NetBSD: Makefile,v 1.30 2026/09/02 07:51:23 adam Exp $

DISTNAME=	google_auth_oauthlib-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-auth-oauthlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleapis/google-cloud-python/tree/main/packages/google-auth-oauthlib
COMMENT=	Google Authentication Library
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-google-auth>=2.46.0:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib>=0.7.0:../../security/py-requests-oauthlib
# tool
DEPENDS+=	${PYPKGPREFIX}-click>=6.0.0:../../devel/py-click

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	google-oauthlib-tool

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
