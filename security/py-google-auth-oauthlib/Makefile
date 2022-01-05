# $NetBSD: Makefile,v 1.10 2022/01/05 15:41:20 wiz Exp $

DISTNAME=	google-auth-oauthlib-0.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-auth-oauthlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GoogleCloudPlatform/google-auth-library-python-oauthlib
COMMENT=	Google Authentication Library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-google-auth>=1.0.0:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib>=0.7.0:../../security/py-requests-oauthlib

USE_LANGUAGES=	# none
   
PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} google-oauthlib-tool google-oauthlib-tool-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
