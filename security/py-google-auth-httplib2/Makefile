# $NetBSD: Makefile,v 1.3 2020/07/15 09:30:30 adam Exp $

DISTNAME=	google-auth-httplib2-0.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-auth-httplib2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GoogleCloudPlatform/google-auth-library-python-httplib2
COMMENT=	Google Authentication Library: httplib2 transport
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-google-auth-[0-9]*:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.9.1:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
