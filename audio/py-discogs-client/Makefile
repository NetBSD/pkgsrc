# $NetBSD: Makefile,v 1.8 2026/10/03 08:59:40 adam Exp $

DISTNAME=	python3_discogs_client-2.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python3_//:S/_/-/}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python3-discogs-client/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/joalla/discogs_client
COMMENT=	Python Client for the Discogs API
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-dateutil>=0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-oauthlib>=0:../../security/py-oauthlib
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
