# $NetBSD: Makefile,v 1.10 2025/12/21 17:13:26 wiz Exp $

DISTNAME=	google_auth_httplib2-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-auth-httplib2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleapis/google-auth-library-python-httplib2
COMMENT=	Google Authentication Library: httplib2 transport
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-google-auth>=1.32:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.19.0:../../www/py-httplib2
TEST_DEPENDS+=	${PYPKGPREFIX}-flask>=0:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-test-localserver>=0:../../devel/py-test-localserver

USE_LANGUAGES=	# none

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
