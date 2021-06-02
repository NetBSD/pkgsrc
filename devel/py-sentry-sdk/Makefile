# $NetBSD: Makefile,v 1.3 2021/06/02 22:46:55 khorben Exp $

DISTNAME=	sentry-sdk-1.1.0
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
