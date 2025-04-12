# $NetBSD: Makefile,v 1.9 2025/04/12 20:34:44 adam Exp $

DISTNAME=	sentry_sdk-2.25.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sentry-sdk/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/getsentry/sentry-python
COMMENT=	Python SDK for Sentry.io
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-certifi>0:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.26.11:../../www/py-urllib3

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
