# $NetBSD: Makefile,v 1.2 2021/03/07 13:44:46 adam Exp $

DISTNAME=	sentry-sdk-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sentry-sdk/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/getsentry/sentry-python
COMMENT=	Python SDK for Sentry.io
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-certifi>=0:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.10.0:../../www/py-urllib3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
