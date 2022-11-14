# $NetBSD: Makefile,v 1.14 2022/11/14 19:40:20 adam Exp $

DISTNAME=	google-auth-oauthlib-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-auth-oauthlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GoogleCloudPlatform/google-auth-library-python-oauthlib
COMMENT=	Google Authentication Library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-google-auth>=2.14.0:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib>=0.7.0:../../security/py-requests-oauthlib

USE_LANGUAGES=	# none
   
PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} google-oauthlib-tool google-oauthlib-tool-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
