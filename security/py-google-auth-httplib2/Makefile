# $NetBSD: Makefile,v 1.8 2025/04/13 19:01:57 wiz Exp $

DISTNAME=	google-auth-httplib2-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-auth-httplib2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GoogleCloudPlatform/google-auth-library-python-httplib2
COMMENT=	Google Authentication Library: httplib2 transport
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-google-auth-[0-9]*:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.19.0:../../www/py-httplib2
TEST_DEPENDS+=	${PYPKGPREFIX}-flask>=0:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-test-localserver>=0:../../devel/py-test-localserver

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
