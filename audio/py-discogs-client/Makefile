# $NetBSD: Makefile,v 1.2 2021/03/07 17:31:28 adam Exp $

DISTNAME=	discogs-client-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/discogs-client/}

MAINTAINER=	pkgsrc_users@NetBSD.org
HOMEPAGE=	https://github.com/discogs/discogs_client
COMMENT=	Python Client for the Discogs API
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-oauthlib-[0-9]*:../../security/py-oauthlib
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-oauthlib

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
