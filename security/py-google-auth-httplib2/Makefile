# $NetBSD: Makefile,v 1.7 2023/12/17 22:23:50 wiz Exp $

DISTNAME=	google-auth-httplib2-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-auth-httplib2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GoogleCloudPlatform/google-auth-library-python-httplib2
COMMENT=	Google Authentication Library: httplib2 transport
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-google-auth-[0-9]*:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.19.0:../../www/py-httplib2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
